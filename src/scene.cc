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
#include "primitives/plane.h"
#include "primitives/sphere.h"
#include "renderers/ppm.h"
#include "tracers/tracer.h"


Scene::Scene()
{}


RGBColour& Scene::background_colour()
{
  return background_colour_;
}


void Scene::set_background_colour(const RGBColour &value)
{
  background_colour_ = value;
}


Tracer* Scene::tracer()
{
  return tracer_;
}


void Scene::set_tracer(Tracer *value)
{
  tracer_ = value;
}


ViewPlane& Scene::vp()
{
  return vp_;
}


void Scene::set_vp(const ViewPlane &value)
{
  vp_ = value;
}


void Scene::Build()
{
  // Initialise a default view plane
  vp_ = ViewPlane(300, 300, 16);

  // Default to a fuchsia background
  background_colour_ = RGBColour();

  // Default sphere at origin
  objects.push_back(new Sphere(Point3(0.0, -25.0, 0.0), 80.0, RGBColour(1.0, 0.0, 0.0)));
  objects.push_back(new Sphere(Point3(0.0, 30.0,0.0), 60.0, RGBColour(1.0, 1.0, 0.0)));
  objects.push_back(new Plane(Point3(0.0), Normal3(0.0, 1.0, 1.0), RGBColour(0.0, 0.3, 0.0)));

  // We've only a single sphere in the scene for now.
  tracer_ = new Tracer(this);
}


void Scene::Render() const
{

  // Hardcode viewing plane's Z location (for now)
  double z = 100.0;

  int n = sqrt(vp_.samples());

  // Create a render target to match the scene's viewing plane resolution.
  PPM img = PPM(vp_.hres(), vp_.vres());

  // Create a ray to trace through the scene
  Ray ray = Ray(Point3(0.0), Vector3(0.0, 0.0, -1.0));
  RGBColour colour;

  // Spawn and trace a ray for each pixel in the viewing plane
  for (int y = 0; y < vp_.vres(); ++y)
    for (int x = 0; x < vp_.hres(); ++x)
    {

/*
      // No antialiasing
      // Calculate ray's origin using orthographic projection
      double xs = vp_.size() * (x - 0.5 * (vp_.hres() - 1));
      double ys = vp_.size() * (y - 0.5 * (vp_.vres() - 1));
      ray.origin = Point3(xs, ys, z);

      // Trace the ray through the scene
      colour = tracer_->Trace(ray);
*/

/*
      // Antialising - regular sampling
      colour.set(0.0);
      for (int sy = 0; sy < n; ++sy)
        for (int sx = 0; sx < n; ++sx)
        {
          // Calculate ray's origin using orthographic projection
          double xs = vp_.size() * (x - 0.5 * vp_.hres() + (sx + 0.5) / n);
          double ys = vp_.size() * (y - 0.5 * vp_.vres() + (sy + 0.5) / n);
          ray.origin = Point3(xs, ys, z);

          // Trace the ray through the scene
          colour += tracer_->Trace(ray);
        }
      colour /= vp_.samples();
*/

/*
      // Antialiasing - random sample
      colour.set(0.0);
      #define rand_float() ((float) rand() / (float) RAND_MAX)
      for (int sy = 0; sy < n; ++sy)
        for (int sx = 0; sx < n; ++sx)
        {
          // Calculate ray's origin using orthographic projection
          double xs = vp_.size() * (x - 0.5 * vp_.hres() + (sx + 0.5) / n);
          double ys = vp_.size() * (y - 0.5 * vp_.vres() + (sy + 0.5) / n);
          ray.origin = Point3(xs, ys, z);

          // Trace the ray through the scene
          colour += tracer_->Trace(ray);
        }
      colour /= vp_.samples();
*/

///*
      // Antialiasing - jittered sampling
      colour.set(0.0);
      #define rand_float() ((float) rand() / (float) RAND_MAX)
      for (int sy = 0; sy < n; ++sy)
        for (int sx = 0; sx < n; ++sx)
        {
          // Calculate ray's origin using orthographic projection
          double xs = vp_.size() * (x - 0.5 * vp_.hres() + rand_float());
          double ys = vp_.size() * (y - 0.5 * vp_.vres() + rand_float());
          ray.origin = Point3(xs, ys, z);

          // Trace the ray through the scene
          colour += tracer_->Trace(ray);
        }
      colour /= vp_.samples();
//*/

      // Draw the image row-by-row, starting at the bottom-left pixel
      img.set_pixel(x, (vp_.vres() - 1) - y, colour);
    }

  // Attempt to open the output file
  FILE *output = fopen("render.ppm", "w");
  if (NULL != output)
  {
    img.Save(output);
    fclose(output);
  }

}
