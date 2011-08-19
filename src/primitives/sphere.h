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


//! A sphere primitive.
class Sphere : public Primitive
{

   public:

      //! Instantiates a default sphere primitive.
      Sphere();

      //! Instantiates a new sphere primitive.
      /*! \param sphere An existing sphere to copy from.
       */
      Sphere(const Sphere &sphere);

      //! Instantiates a new sphere primitive.
      /*! \param centre The sphere's centre.
       *  \param radius The sphere's radius.
       */
      Sphere(const vec &centre, double radius);

      //! Instantiates a new sphere primitive.
      /*! \param x The X-ordinate of the sphere's centre.
       *  \param y The Y-ordinate of the sphere's centre.
       *  \param z The Z-ordinate of the sphere's centre.
       *  \param radius The sphere's radius.
       */
      Sphere(double x, double y, double z, double radius);

      //! Gets the sphere's centre.
      vec& GetCentre();

      //! Sets the sphere's centre.
      /*! \param value The new centre of the sphere.
       */
      void SetCentre(vec &value);

      //! Gets the sphere's radius.
      double GetRadius();

      //! Gets the square of the sphere's radius.
      double GetRadiusSq();

      //! Sets the sphere's radius.
      /*! \param value The new radius of the sphere.
       */
      void SetRadius(double value);

      virtual bool Intersect(const Ray &ray, double &dist) const;

   private:

      vec  c;  /*! The sphere's centre. */
      double r;  /*! The sphere's radius. */
      double r2; /*! The square of the sphere's radius. */

};

#endif // RAY_PRIMITIVES_SPHERE_H_
