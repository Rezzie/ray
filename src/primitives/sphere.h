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

#ifndef RAY_PRIMITIVES_SPHERE_H_
#define RAY_PRIMITIVES_SPHERE_H_

#include "common.h"
#include "primitives/primitive.h"
#include "ray.h"


//! A sphere primitive.
class Sphere : public Primitive
{

   public:

      //! Instantiates a default sphere primitive.
      Sphere();

      //! Instantiates a new sphere by copying an existing one.
      explicit Sphere(const Sphere &sphere);

      //! Instantiates a new sphere primitive from a centre point and radius.
      Sphere(const vec &centre, double radius);

      //! Instantiates a new sphere primitive from a centre point and radius.
      Sphere(double x, double y, double z, double radius);

      //! Gets the centre point of the sphere.
      vec& get_centre();

      //! Sets the centre point of the sphere.
      void set_centre(vec &value);

      //! Gets the radius of the sphere.
      double get_radius();

      //! Gets the square of the radius of the sphere.
      double get_radius_squared();

      //! Sets the radius of the sphere.
      void set_radius(double value);

      virtual bool Intersect(const Ray &ray, double &dist) const;

   private:

      vec    centre_;   //!< The centre point of the sphere.
      double radius_;   //!< The radius of the sphere.
      double radius2_;  //!< The square of the radius.

};

#endif // RAY_PRIMITIVES_SPHERE_H_
