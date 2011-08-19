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
    : origin(Vector3(0.0)),
      direction(Vector3(0.0, 0.0, 1.0))
{
}


Ray::Ray(const Ray &ray)
    : origin(ray.origin),
      direction(ray.direction)
{
}


Ray::Ray(const Vector3 &origin, const Vector3 &direction)
    : origin(origin),
      direction(direction)
{
}
