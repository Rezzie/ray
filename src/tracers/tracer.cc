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

#include "tracers/tracer.h"

#include "primitives/primitive.h"
#include "scene.h"


Tracer::Tracer()
    : scene_(NULL)
{}


Tracer::Tracer(Scene *scene)
    : scene_(scene)
{}


RGBColour Tracer::Trace(const Ray &ray) const
{

  // If a ray misses all primitives it is set to the background colour of the scene.
  RGBColour colour = scene_->background_colour();

  double min_dist = kHugeVal; // The distance to the closest intersection (if any)
  double dist;  // The distance to the current intersection (if any)

  // Need to check for an intersection between each object in the scene
  for (int i = 0; i < scene_->objects.size(); ++i)
  {
    if (scene_->objects[i]->Intersects(ray, dist) && (dist < min_dist))
    {
      // This is the closest intersection we've seen so far
      min_dist = dist;
      colour = scene_->objects[i]->colour();
    }
  }

  return colour;

}
