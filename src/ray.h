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

#ifndef _INCLUDED_CA06791DEB744AD8
#define _INCLUDED_CA06791DEB744AD8

#include <vmmlib/vector.hpp>

using namespace vmml;


class Ray
{
   public:

      Ray(vec3f origin, vec3f direction);

      vec3f& GetDirection();

      vec3f& GetOrigin();

      void SetDirection(vec3f& direction);

      void SetOrigin(vec3f& origin);

   private:

      vec3f _origin;

      vec3f _direction;

};

#endif // _INCLUDED_CA06791DEB744AD8
