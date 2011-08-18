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

#include "renderers/ppm.h"
#include "tracers/singlesphere.h"

#include <fstream>


Scene::Scene()
{
}


void Scene::Build()
{
   // Initialise a default view plane
   vp = ViewPlane();

   // Default to a black background
   background = vec(0.0);

   // Default sphere at origin
   sphere = Sphere(vec(0.0), 85.0);

   tracer = new SingleSphere(this);
}


void Scene::Render() const
{
   // Hardcode viewing plane's Z location (for now)
   double z = 100.0;

   // Create a render target to match the scene's viewing plane resolution.
   PPM img(vp.GetWidth(), vp.GetHeight());

   // Create a ray to trace through the scene
   Ray ray(vec(0.0), vec(0.0, 0.0, -1.0));

   for (int y = 0; y < vp.GetHeight(); y++)
      for (int x = 0; x < vp.GetWidth(); x++)
      {
         // Calculate ray's origin using orthographic projection
         double xs = vp.GetSize() * (x - 0.5 * (vp.GetWidth() - 1.0));
         double ys = vp.GetSize() * (y - 0.5 * (vp.GetHeight() - 1.0));
         ray.Origin = vec(xs, ys, z);

         // Trace the ray through the scene
         Colour colour = tracer->Trace(ray);

         // Render the pixel
         img.SetPixel(x, y, colour);
      }

   // Attempt to open the output file
   std::ofstream out("render.ppm", std::ios::out | std::ios::trunc);

   // Save the render
   bool success = img.Save(out);
   if (success)
      std::cout << "Render saved to 'render.ppm'" << std::endl;
   else
      std::cout << "Failed to save render to 'render.ppm'" << std::endl;

}
