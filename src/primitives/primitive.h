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

#ifndef _INCLUDED_6AADDAD8406C40EA
#define _INCLUDED_6AADDAD8406C40EA

#include "../common.h"

#include "../ray.h"


//! An abstract base class for all primitive objects.
class Primitive
{

   public:

      //! Checks whether a ray intersects with the primitive.
      /*! \param ray The ray to check for an intersection with.
       *  \param dist The distance to the closest intersection point, if one occurs.
       */
      virtual bool Intersect(Ray &ray, double &dist) const = 0;

};

#endif // _INCLUDED_6AADDAD8406C40EA
