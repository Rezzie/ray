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

#ifndef _INCLUDED_C76026C6EAEF43B3
#define _INCLUDED_C76026C6EAEF43B3

#include <vmmlib/vector.hpp>

// Forward declarations
class Ray;

using namespace vmml;

//! The type of projection to use when ejecting ray's from the camera.
enum Projection
{
   PERSPECTIVE, /*! Simulates a pinhole camera. */
   ORTHOGRAPHIC /*! Parallel camera rays are used to view the scene. */
};

//! Models a camera, providing a view into a scene.
class Camera
{
   public:

      Camera();

// FIXME
      Ray SpawnRay(int x, int y, float sx, float sy);
// FIXME

   protected:

      vec3f _location;
      vec3f _direction;
      vec3f _up;
      vec3f _right;
      vec3f _sky;
      vec3f _lookAt;
      Projection _type;
      float _fov;


      // TODO: What's this?
      float Direction_Length;
      float Up_Length;
      float Right_Length;
      float Handedness;
      float k1;
      float k2;
      float k3;
      vec3f tempv;

};

#endif // _INCLUDED_C76026C6EAEF43B3
