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

#ifndef _INCLUDED_A644FC0CD69E4D96
#define _INCLUDED_A644FC0CD69E4D96

#include "../common.h"
#include "primitive.h"

// Forward declarations
class Ray;


//! A plane primitive.
class Plane : public Primitive
{

   public:

      //! Instantiates a default plane primitive.
      Plane();

      //! Instantiates a new plane primitive.
      /*! \param plane An existing plane to copy from.
       */
      Plane(const Plane &plane);

      //! Instantiates a new plane primitive.
      /*! \param point A point on the plane.
       *  \param normal A normal vector to the plane.
       */
      Plane(const vec3f &point, const vec3f &normal);

      //! Gets a normal vector to the plane.
      vec3f& GetNormal();

      //! Sets a normal vector to the plane.
      /*! \param value A normal vector to the plane.
       */
      void SetNormal(vec3f &value);

      //! Gets a point on the plane.
      vec3f& GetPoint();

      //! Sets a point on the plane.
      /*! \param value A point on the plane.
       */
      void SetPoint(vec3f &value);

      virtual bool Intersect(Ray &ray, double &dist) const;

   protected:

      //! A point on the plane.
      vec3f a;

      //! A normal vector to the plane.
      vec3f n;

};

#endif // _INCLUDED_A644FC0CD69E4D96
