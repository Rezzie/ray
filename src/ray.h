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

#ifndef RAY_RAY_H_
#define RAY_RAY_H_

#include "common.h"


//! Represents a ray, fired from the camera into the scene.
class Ray
{

   public:

      //! Instantiates a default ray.
      Ray();

      //! Instantiates a new ray.
      /*! \param ray An existing ray to copy from.
       */
      Ray(const Ray &ray);

      //! Instantiates a new ray.
      /*! \param origin The ray's origin.
       *  \param direction The ray's direction.
       */
      Ray(const vec &origin, const vec &direction);

      //! The ray's origin.
      vec Origin;

      //! The ray's direction. This should always be normalised.
      vec Direction;

};

#endif // RAY_RAY_H_
