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

#include "main.h"

#include "camera.h"
#include "image.h"
#include "ray.h"
#include "primitives/sphere.h"

#include <vmmlib/vector.hpp>

//#include <cstdio>
//#include <cstdlib>
//#include <limits>

using namespace vmml;


int main(int argc, char *argv[])
{
   Camera cam;
   struct
   {
      int Width;
      int Height;
   } vp;
   vp.Width = 640;
   vp.Height = 480;

   // The image we'll be rendering to
   Image img(vp.Width, vp.Height);

   // One sphere in our scene originally...
   Sphere s(vec3f(0.0f, 0.0f, 0.0f), 1.0f);

// FIXME
   float m_WX1, m_WY1, m_WX2, m_WY2, m_DX, m_DY, m_SX, m_SY;
   m_WX1 = -4, m_WX2 = 4, m_WY1 = m_SY = 3, m_WY2 = -3;
   m_DX = (m_WX2 - m_WX1) / vp.Width;
   m_DY = (m_WY2 - m_WY1) / vp.Height;
   m_SY += 20 * m_DY;
// FIXME

   // Loop through each pixel from left-to-right, one row at a time.
   for (int y = 0; y < vp.Height; y++)
   {
// FIXME
      m_SX = m_WX1;
// FIXME

      for (int x = 0; x < vp.Width; x++)
      {
         // Spawn a ray from the camera through the current pixel
// FIXME
         Ray ray = cam.SpawnRay(x, y, m_SX, m_SY);
// FIXME

         // Create a colour to store the final colour of the pixel,
         // defaulting to the background colour
         Colour colour;
         colour.R = 255;
         colour.G = 0;
         colour.B = 255;

         // Keep track of which primitive (if any) has had the closest intersection
         float closest = std::numeric_limits<float>::max();

         // Find the closest primitive hit by the ray
         bool intersects = s.Intersect(ray, closest);

         if (intersects)
         {
            // The ray intersected with the primitive and it's the closest one
            // we've found so far. Update the colour of the current ray.
            colour = s.GetColour();
         }

         // Draw the colour
         img.SetPixel(x, y, colour);

// FIXME
         m_SX += m_DX;
// FIXME

      }
// FIXME
      m_SY += m_DY;
// FIXME
   }

   // Save the image
   img.Save("render.ppm");

   // All done!
   return EXIT_SUCCESS;

}
