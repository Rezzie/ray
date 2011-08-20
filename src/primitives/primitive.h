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

#ifndef RAY_PRIMITIVES_PRIMITIVE_H_
#define RAY_PRIMITIVES_PRIMITIVE_H_

#include "common.h"
#include "ray.h"


//! An abstract base class for all primitive objects.
class Primitive
{

 public:

  /*! @brief Instantiates a default primitive.
   *  @details The primitive's colour will be set to the value of #kDefaultColour.
   */
  Primitive();

  //! Instantiates a primitive with the given colour.
  Primitive(const RGBColour &colour);

  //! Gets the colour of the primitive.
  RGBColour& colour();

  //! Sets the colour of the primitive.
  void set_colour(RGBColour &value);

  /*! @brief Checks if a ray intersects with the primitive.
   *  @param ray  The ray to check for an intersection with.
   *  @param dist The distance to the closest intersection point, if one occurs.
   */
  virtual bool Intersects(const Ray &ray, double &dist) const = 0;

 protected:

  RGBColour colour_; //!< The colour of the primitive.

};

#endif // RAY_PRIMITIVES_PRIMITIVE_H_
