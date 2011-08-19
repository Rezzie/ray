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

#include "primitives/sphere.h"


Sphere::Sphere()
   : centre_(vec(0.0)),
     radius_(1.0),
     radius2_(1.0)
{
}


Sphere::Sphere(const Sphere &sphere)
   : centre_(sphere.centre_),
     radius_(sphere.radius_),
     radius2_(sphere.radius_ * sphere.radius_)
{
}


Sphere::Sphere(const vec &centre, double radius)
   : centre_(centre),
     radius_(radius),
     radius2_(radius * radius)
{
}


Sphere::Sphere(double x, double y, double z, double radius)
   : centre_(vec(x, y, z)),
     radius_(radius),
     radius2_(radius * radius)
{
}


vec& Sphere::get_centre()
{
   return centre_;
}


void Sphere::set_centre(vec &value)
{
   centre_ = value;
}


double Sphere::get_radius()
{
   return radius_;
}


double Sphere::get_radius_squared()
{
   return radius2_;
}


void Sphere::set_radius(double value)
{
   radius_ = value;
   radius2_ = value * value;
}


bool Sphere::Intersects(const Ray &ray, double &dist) const
{

   vec origin_to_centre = ray.Origin - centre_;
   double a    = ray.Direction.dot(ray.Direction);
   double b    = 2.0 * origin_to_centre.dot(ray.Direction);
   double c    = origin_to_centre.dot(origin_to_centre) - radius2_;
   double disc = (b * b) - 4.0 * a * c;

   if (disc < 0.0)
      return false;

   double e = sqrt(disc);
   double denom = 2.0 * a;

   double t = (-b - e) / denom;
   if (t > kEpsilon)
   {
      dist = t;
      return true;
   }

   t = (-b + e) / denom;
   if (t > kEpsilon)
   {
      dist = t;
      return true;
   }

   return false;

}
