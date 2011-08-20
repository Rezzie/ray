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

#ifndef RAY_PRIMITIVES_PLANE_H_
#define RAY_PRIMITIVES_PLANE_H_

#include "common.h"
#include "primitives/primitive.h"
#include "ray.h"


//! A plane primitive.
class Plane : public Primitive
{

 public:

  /*! @brief Instantiates a default plane primitive.
   *  @details The colour will be the value of #kDefaultColour, the point
   *           defining it will be #kDefaultPoint and its surface normal will be
   *           #kDefaultNormal.
   */
  Plane();

  //! Copies an existing plane.
  explicit Plane(const Plane &plane);

  /*! @brief Instantiates a new plane from a point and normal vector to the surface.
   *  @details The colour will be the value of #kDefaultColour.
   */
  Plane(const Point3 &point, const Normal3 &normal);

  //! Instantiates a new plane from a point, normal vector to the surface and colour.
  Plane(const Point3 &point, const Normal3 &normal, const RGBColour &colour);

  //! Gets a normal vector to the plane.
  Normal3& normal();

  //! Sets the normal vector to the plane.
  void set_normal(Normal3 &value);

  //! Gets a point on the plane.
  Point3& point();

  //! Sets a point on the plane.
  void set_point(Point3 &value);

  virtual bool Intersects(const Ray &ray, double &dist) const;

 protected:

  Point3  point_;   //!< A point on that lies on the plane.
  Normal3 normal_;  //!< A normal vector to the plane.

};

#endif // RAY_PRIMITIVES_PLANE_H_
