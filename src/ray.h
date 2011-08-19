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


//! Represents a ray with an origin and direction.
struct Ray
{

 public:

  //! Instantiates a default ray.
  Ray();

  //! Copies an existing ray.
  Ray(const Ray &ray);

  //! Instantiates a new ray with the given origin and direction.
  Ray(const Vector3 &origin, const Vector3 &direction);

  Vector3 origin;     //!< The ray's origin.
  Vector3 direction;  //!< The ray's direction. This should always be normalised.

};

#endif // RAY_RAY_H_
