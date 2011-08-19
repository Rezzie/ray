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


//! A plane primitive.
class Plane : public Primitive
{

   public:

      //! Instantiates a default plane primitive.
      Plane();

      //! Instantiates a new plane primitive.
      /*! \param plane An existing plane to copy from.
       */
      explicit Plane(const Plane &plane);

      //! Instantiates a new plane primitive.
      /*! \param point A point on the plane.
       *  \param normal A normal vector to the plane.
       */
      Plane(const vec &point, const vec &normal);

      //! Gets a normal vector to the plane.
      vec& GetNormal();

      //! Sets a normal vector to the plane.
      /*! \param value A normal vector to the plane.
       */
      void SetNormal(vec &value);

      //! Gets a point on the plane.
      vec& GetPoint();

      //! Sets a point on the plane.
      /*! \param value A point on the plane.
       */
      void SetPoint(vec &value);

      virtual bool Intersect(const Ray &ray, double &dist) const;

   protected:

      //! A point on the plane.
      vec a;

      //! A normal vector to the plane.
      vec n;

};

#endif // RAY_PRIMITIVES_PLANE_H_
