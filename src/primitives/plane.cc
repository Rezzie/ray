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
    : point_(Vector3(0.0)),
      normal_(Vector3(0.0, 1.0, 0.0))
{
}


Plane::Plane(const Plane &plane)
    : point_(plane.point_),
      normal_(plane.normal_)
{
}


Plane::Plane(const Vector3 &point, const Vector3 &normal)
    : point_(point),
      normal_(normal)
{
  // Ensure the normal vector is normalised.
  normal_.normalize();
}


Vector3& Plane::normal()
{
  return normal_;
}


void Plane::set_normal(Vector3 &value)
{
  normal_ = value;
  normal_.normalize();
}


Vector3& Plane::point()
{
  return point_;
}


void Plane::set_point(Vector3 &value)
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
