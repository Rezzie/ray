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


Sphere::Sphere()
   : c(vec3f(0.0)),
     r(1.0),
     r2(1.0)
{
}


Sphere::Sphere(const Sphere &sphere)
   : c(sphere.c),
     r(sphere.r),
     r2(sphere.r * sphere.r)
{
}


Sphere::Sphere(const vec3f &centre, double radius)
   : c(centre),
     r(radius),
     r2(radius * radius)
{
}


Sphere::Sphere(double x, double y, double z, double radius)
   : c(vec3f(x, y, z)),
     r(radius),
     r2(radius * radius)
{
}


vec3f& Sphere::GetCentre()
{
   return c;
}


void Sphere::SetCentre(vec3f &value)
{
   c = value;
}


double Sphere::GetRadius()
{
   return r;
}


double Sphere::GetRadiusSq()
{
   return r2;
}


void Sphere::SetRadius(double value)
{
   r = value;
   r2 = value * value;
}


bool Sphere::Intersect(Ray &ray, double &dist) const
{

   vec3f  o2c  = ray.Origin - c;
   double a    = ray.Direction.dot(ray.Direction);
   double b    = 2.0 * o2c.dot(ray.Direction);
   double c    = (o2c.dot(o2c)) - (r * r);
   double disc = (b * b) - 4.0 * a * c;

   if (disc < 0.0)
      return false;

   double e = sqrt(disc);
   double denom = 2.0 * a;

   double t = (-b - e) / denom;
   if (t > EPSILON)
   {
      dist = t;
      return true;
   }

   t = (-b + e) / denom;
   if (t > EPSILON)
   {
      dist = t;
      return true;
   }

   return false;

}
