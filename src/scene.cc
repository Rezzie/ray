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

#include "scene.h"

#include <cstdio>

#include "ray.h"
#include "renderers/ppm.h"
#include "tracers/singlesphere.h"


Scene::Scene()
{
}


void Scene::Build()
{
  // Initialise a default view plane
  vp_ = ViewPlane();

  // Default to a black background
  background_ = Vector3(0.0);

  // Default sphere at origin
  sphere = Sphere(Vector3(0.0), 85.0);

  // We've only a single sphere in the scene for now.
  tracer_ = new SingleSphere(this);
}


void Scene::Render() const
{

  // Hardcode viewing plane's Z location (for now)
  double z = 100.0;

  // Create a render target to match the scene's viewing plane resolution.
  PPM img = PPM(vp_.hres(), vp_.vres());

  // Create a ray to trace through the scene
  Ray ray = Ray(Vector3(0.0), Vector3(0.0, 0.0, -1.0));
  Colour colour;

  // Spawn and trace a ray for each pixel in the viewing plane
  for (int y = 0; y < vp_.vres(); ++y)
    for (int x = 0; x < vp_.hres(); ++x)
    {
      // Calculate ray's origin using orthographic projection
      double xs = vp_.size() * (x - 0.5 * (vp_.hres() - 1.0));
      double ys = vp_.size() * (y - 0.5 * (vp_.vres() - 1.0));
      ray.origin = Vector3(xs, ys, z);

      // Trace the ray through the scene
      colour = tracer_->Trace(ray);

      // Render the pixel
      img.set_pixel(x, y, colour);
    }

  // Attempt to open the output file
  FILE *output = fopen("render.ppm", "w");
  if (NULL != output)
  {
    img.Save(output);
    fclose(output);
  }

}
