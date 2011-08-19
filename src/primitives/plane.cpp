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
   : a(vec(0.0)),
     n(vec(0.0, 1.0, 0.0))
{
}


Plane::Plane(const Plane &plane)
   : a(plane.a),
     n(plane.n)
{
}


Plane::Plane(const vec &point, const vec &normal)
   : a(point),
     n(normal)
{
   // Ensure the normal vector is normalised.
   n.normalize();
}


vec& Plane::GetNormal()
{
   return n;
}


void Plane::SetNormal(vec &value)
{
   n = value;
   n.normalize();
}


vec& Plane::GetPoint()
{
   return a;
}


void Plane::SetPoint(vec &value)
{
   a = value;
}


bool Plane::Intersect(const Ray &ray, double &dist) const
{

   double t = (a - ray.Origin).dot(n) / ray.Direction.dot(n);

   if (t > EPSILON)
   {
      dist = t;
      return true;
   }

   // The ray is parallel to the plane
   return false;

}
