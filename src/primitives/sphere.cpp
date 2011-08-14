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

#include "sphere.h"

#include "../ray.h"

#define EPSILON 1.0e-10


Sphere::Sphere(vmml::vec3f centre, float radius)
   : _centre(centre), _radius(radius)
{
   return;
}

vmml::vec3f& Sphere::GetCentre()
{
   return _centre;
}

float Sphere::GetRadius()
{
   return _radius;
}

float Sphere::GetRadiusSq()
{
   return _radius * _radius;
}

bool Sphere::Intersect(Ray &ray, float &dist)
{
  vec3f Origin_To_Center = _centre - ray.GetOrigin();

  float OCSquared = Origin_To_Center.dot(Origin_To_Center);

  float t_Closest_Approach = Origin_To_Center.dot(ray.GetDirection());

  if ((OCSquared >= _radius * _radius) && (t_Closest_Approach < EPSILON))
    return false;

  float t_Half_Chord_Squared = (_radius * _radius) - OCSquared + (t_Closest_Approach * t_Closest_Approach);

   if (t_Half_Chord_Squared <= EPSILON)
      return false;

   float Half_Chord = sqrt(t_Half_Chord_Squared);

   float t1 = t_Closest_Approach - Half_Chord;
   float t2 = t_Closest_Approach + Half_Chord;

   if (t1 > dist && t2 > dist)
      return false;

   dist = (t1 < t2) ? t1 : t2;
   return true;


   // vmml::vec3f diff = ray.GetOrigin() - _centre;
   // float a0 = diff.dot(diff) - (_radius * _radius);
   // float a1, discr, root;

   // if (a0 <= 0.0f)
   // {
   //    // P is inside the sphere
   //    a1 = ray.GetDirection().dot(diff);
   //    discr = a1*a1 - a0;
   //    root = sqrtf(discr);
   //    float t0 = -a1 + root;
   //    //vmml::vec3f p0 = ray.GetOrigin() + t0 * ray.GetDirection();

   //    if (t0 >= dist)
   //       return false;

   //    dist = t0;
   //    return true;
   // }
   // // else: P is outside the sphere

   // a1 = ray.GetDirection().dot(diff);
   // if (a1 >= 0.0f)
   //    return false;

   // discr = a1*a1 - a0;
   // if (discr < 0.0f)
   //    return false;

   // root = sqrtf(discr);
   // float t0 = -a1 - root;
   // float t1 = -a1 + root;
   // //vmml::vec3f p0 = ray.GetOrigin() + t0 * ray.GetDirection();
   // //vmml::vec3f p1 = ray.GetOrigin() + t1 * ray.GetDirection();

   // float closest = (t0 < t1) ? t0 : t1;
   // if (closest >= dist)
   //    return false;

   // dist = closest;
   // return true;


   // // Calculate the vector from the sphere's centre to the ray's origin.
   // vmml::vec3f v = ray.GetOrigin() - _centre;
   // float b = -(v.dot(ray.GetDirection()));
   // float disc = (b * b) - v.dot(v) + (_radius * _radius);
   //
   // int retval = 0;
   // if (disc > 0)
   // {
   //    disc = sqrtf( disc );
   //    float i1 = b - disc;
   //    float i2 = b + disc;
   //    if (i2 > 0)
   //    {
   //       if (i1 < 0)
   //       {
   //          dist = i2;
   //          retval = -1;
   //       }
   //       else
   //       {
   //          dist = i1;
   //          retval = 1;
   //       }
   //    }
   // }
   // return retval;

}

void Sphere::SetCentre(vmml::vec3f value)
{
   _centre = value;
}

void Sphere::SetRadius(float value)
{
   _radius = value;
}
