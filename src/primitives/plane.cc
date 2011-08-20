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

static const Point3  kDefaultPoint = Vector3(0.0);
static const Normal3 kDefaultNormal = Vector3(0.0, 1.0, 0.0);


Plane::Plane()
    : Primitive(),
      point_(kDefaultPoint),
      normal_(kDefaultNormal)
{}


Plane::Plane(const Plane &plane)
    : Primitive(plane.colour_),
      point_(plane.point_),
      normal_(plane.normal_)
{}


Plane::Plane(const Point3 &point, const Normal3 &normal)
    : Primitive(),
      point_(point),
      normal_(normal)
{
  // Ensure the normal vector is normalised.
  normal_.normalize();
}


Plane::Plane(const Point3 &point, const Normal3 &normal, const RGBColour &colour)
    : Primitive(colour),
      point_(point),
      normal_(normal)
{
  // Ensure the normal vector is normalised.
  normal_.normalize();
}


Normal3& Plane::normal()
{
  return normal_;
}


void Plane::set_normal(Normal3 &value)
{
  normal_ = value;
  normal_.normalize();
}


Point3& Plane::point()
{
  return point_;
}


void Plane::set_point(Point3 &value)
{
  point_ = value;
}


bool Plane::Intersects(const Ray &ray, double &dist) const
{

  double t = (point_ - ray.origin).dot(normal_) / ray.direction.dot(normal_);

  if (t > kEpsilon)
  {
    dist = t;
    return true;
  }

  // The ray is parallel to the plane
  return false;

}
