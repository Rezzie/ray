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


Ray::Ray()
   : Origin(vec3f(0.0)),
     Direction(vec3f(0.0, 0.0, 1.0))
{
}


Ray::Ray(const Ray &ray)
   : Origin(ray.Origin),
     Direction(ray.Direction)
{
}


Ray::Ray(const vec3f &origin, const vec3f &direction)
   : Origin(origin),
     Direction(direction)
{
}
