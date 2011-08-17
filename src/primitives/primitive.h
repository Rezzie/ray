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

#include "../rendersurface.h"

// Forward declarations
class Ray;


//! An abstract base class for all primitive objects.
class Primitive
{

   public:

      Primitive();
      Primitive(Colour colour);

      Colour GetColour();

      virtual bool Intersect(Ray &ray, float &dist) = 0;

      void SetColour(Colour value);

   protected:

      Colour _colour;

};

#endif // _INCLUDED_6AADDAD8406C40EA
