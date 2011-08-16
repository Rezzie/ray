/* Part of the Ray project.
 *
 * Copyright (C) 2011 James Arnold
 *
 * Authors:
 *   James Arnold <jarnie@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "camera.h"

#include "ray.h"


#define M_PI_360 0.00872664625997164788
#define EPSILON 1.0e-10


Camera::Camera()
   : _location (vec3f(0.0f, 0.0f, 0.0f)),
     _direction(vec3f(0.0f, 0.0f, 1.0f)),
     _up       (vec3f(0.0f, 1.0f, 0.0f)),
     _right    (vec3f(1.0f, 0.0f, 0.0f)),
     _sky      (vec3f(0.0f, 1.0f, 0.0f)),
     _lookAt   (vec3f(0.0f, 0.0f, 1.0f)),
     _type     (PERSPECTIVE),
     _fov      (90.0f)
{


   // TODO: Remove
   _location = vec3f(0.0f, 0.0f, -5.0f);
   _lookAt = vec3f(0.0f, 1.0f, 2.0f);
   // TODO: Remove


   if (_type == PERSPECTIVE || _type == ORTHOGRAPHIC)
   {
      if (_fov < 0.0f)
      {
         // TODO: Show error
         // "Viewing angle cannot be negative."
         return;
      }
      else if (_fov >= 180.0f)
      {
         // TODO: Show error
         // "Viewing angle has to be less than 180 degrees."
         return;
      }



      // APPLY FOV

      _direction.normalize();
      Right_Length = _right.length();
      Direction_Length = Right_Length / tanf(_fov * M_PI_360) / 2.0f;
      _direction *= Direction_Length;
   }



   // APPLY LOOKAT

   Direction_Length = _direction.length();
   Up_Length = _up.length();
   Right_Length = _right.length();
   tempv.cross(_up, _direction);
   Handedness = tempv.dot(_right);

   _direction = _lookAt;

   _direction -= _location;

   // Check for zero length direction vector.
   if (_direction.squared_length() < EPSILON)
   {
      // TODO: Show error
      // "Camera location and look_at point must be different."
      return;
   }

   _direction.normalize();

   // Save Right vector
   tempv = _right;

   _right.cross(_sky, _direction);

   // Avoid DOMAIN error
   if(fabs(_right.find_max()) < EPSILON)
   {
      // Restore Right vector
      _right = tempv;
   }

   _right.normalize();
   _up.cross(_direction, _right);
   _direction *= Direction_Length;

   if (Handedness > 0.0)
      _right *= Right_Length;
   else
      _right *= -Right_Length;

   _up *= Up_Length;



   // APPLY ORTHOGRAPHIC

   if (_type == ORTHOGRAPHIC)
   {
      // resize right and up vector to get the same image
      // area as we get with the perspective camera
      tempv = _lookAt - _location;
      k1 = tempv.length();
      k2 = _direction.length();
      if ((k1 > EPSILON) && (k2 > EPSILON))
      {
         _right *= (k1 / k2);
         _up *= (k1 / k2);
      }
   }



   // PRINT A WARNING MESSAGE IF VECTORS ARE NOT PERPENDICULAR.

   k1 = _right.dot(_up);
   k2 = _right.dot(_direction);
   k3 = _up.dot(_direction);

   if ((fabs(k1) > EPSILON) || (fabs(k2) > EPSILON) || (fabs(k3) > EPSILON))
   {
      // TODO: Show warning
      // "Camera vectors are not perpendicular."
      ;
   }
}

// FIXME
Ray Camera::SpawnRay(int x, int y, float sx, float sy)
{
// FIXME
   vec3f o = _location;
   vec3f d = vec3f(sx, sy, 0.0f) - o;
   d.normalize();
   return Ray(o, d);
// FIXME

   // TODO: Don't hardcode this
   const int width = 640;
   const int height = 480;

  float x0;
  float y0;

  vec3f ro = _location;
  vec3f rd = _direction;

  /* Create primary ray according to the camera used. */

   if (_type == PERSPECTIVE)
   {
      // Convert X & Y to be floats between -0.5 and +0.5
      x0 = (x / (float) width) - 0.5;
      y0 = (((float) (height - 1) - y) / (float) height) - 0.5;

      /* Create primary ray. */
      rd = vec3f(1.0f * _direction.x() + x0 * _right.x() + y0 * _up.x(),
                 1.0f * _direction.y() + x0 * _right.y() + y0 * _up.y(),
                 1.0f * _direction.z() + x0 * _right.z() + y0 * _up.z());

   }
   else if (_type == ORTHOGRAPHIC)
   {
      // Convert X & Y to be floats between -0.5 and +0.5
      x0 = (x / (float) width) - 0.5;
      y0 = (((float) (height - 1) - y) / (float) height) - 0.5;

      /* Create primary ray. */
      ro = vec3f(1.0f * _location.x() + x0 * _right.x() + y0 * _up.x(),
                 1.0f * _location.y() + x0 * _right.y() + y0 * _up.y(),
                 1.0f * _location.z() + x0 * _right.z() + y0 * _up.z());
   }

   // Orthographic
   return Ray(ro, rd);
}
