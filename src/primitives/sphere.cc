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
    : centre_(Vector3(0.0)),
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


Sphere::Sphere(const Vector3 &centre, double radius)
    : centre_(centre),
      radius_(radius),
      radius2_(radius * radius)
{
}


Sphere::Sphere(double x, double y, double z, double radius)
    : centre_(Vector3(x, y, z)),
      radius_(radius),
      radius2_(radius * radius)
{
}


Vector3& Sphere::centre()
{
  return centre_;
}


void Sphere::set_centre(Vector3 &value)
{
  centre_ = value;
}


double Sphere::radius() const
{
  return radius_;
}


double Sphere::radius_squared() const
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

  Vector3 origin_to_centre = ray.origin - centre_;
  double a    = ray.direction.dot(ray.direction);
  double b    = 2.0 * origin_to_centre.dot(ray.direction);
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
