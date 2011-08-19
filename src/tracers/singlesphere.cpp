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

#include "tracers/singlesphere.h"

#include "scene.h"


SingleSphere::SingleSphere()
   : Tracer()
{
}


SingleSphere::SingleSphere(Scene *scene)
   : Tracer(scene)
{
}


Colour SingleSphere::Trace(const Ray &ray) const
{
   double dist; // Unusued

   // If the ray intersects the sphere, colour it red
   if (s->sphere.Intersect(ray, dist))
      return Colour(1.0, 0.0, 0.0);

   // Default to just black
   return Colour(0.0);
}
