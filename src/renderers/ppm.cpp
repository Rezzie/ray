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

#include "renderers/ppm.h"


PPM::PPM()
   : RenderTarget()
{
}


PPM::PPM(int width, int height)
   : RenderTarget(width, height)
{
}


void PPM::Save(FILE *output)
{
   // Write the PPM header
   fprintf(output, "P6\n");
   fprintf(output, "%d %d\n", width_, height_);
   fprintf(output, "255\n");

   // Write the pixel data
   Colour pixel;
   for (int y = 0; y < height_; y++)
      for (int x = 0; x < width_; x++)
      {
         pixel = get_pixel(x, y) * 255;
         fprintf(output, "%c%c%c", static_cast<char>(pixel.r()),
                                   static_cast<char>(pixel.g()),
                                   static_cast<char>(pixel.b()));
      }
}
