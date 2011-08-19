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

#include "primitives/plane.h"


Plane::Plane()
   : point_(vec(0.0)),
     normal_(vec(0.0, 1.0, 0.0))
{
}


Plane::Plane(const Plane &plane)
   : point_(plane.point_),
     normal_(plane.normal_)
{
}


Plane::Plane(const vec &point, const vec &normal)
   : point_(point),
     normal_(normal)
{
   // Ensure the normal vector is normalised.
   normal_.normalize();
}


vec& Plane::get_normal()
{
   return normal_;
}


void Plane::set_normal(vec &value)
{
   normal_ = value;
   normal_.normalize();
}


vec& Plane::get_point()
{
   return point_;
}


void Plane::set_point(vec &value)
{
   point_ = value;
}


bool Plane::Intersect(const Ray &ray, double &dist) const
{

   double t = (point_ - ray.Origin).dot(normal_) / ray.Direction.dot(normal_);

   if (t > kEpsilon)
   {
      dist = t;
      return true;
   }

   // The ray is parallel to the plane
   return false;

}
