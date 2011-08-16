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

#include "ray.h"


Ray::Ray(vec3f origin, vec3f direction)
   : _origin(origin), _direction(direction)
{
   return;
}

vec3f& Ray::GetDirection()
{
   return _direction;
}

vec3f& Ray::GetOrigin()
{
   return _origin;
}

void Ray::SetDirection(vec3f& direction)
{
   _direction = direction;
}

void Ray::SetOrigin(vec3f& origin)
{
   _origin = origin;
}
