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


PPM::PPM(int width, int height)
   : RenderTarget(width, height)
{
}


bool PPM::Save(std::ostream &os)
{
   try
   {
      // Write the PPM header
      os << "P3" << std::endl;
      os << _width << " " << _height << std::endl;
      os << "1" << std::endl;

      // Write the pixels
      for (int y = 0; y < _height; y++)
      {
         for (int x = 0; x < _width; x++)
         {
            Colour pixel = GetPixel(x, y);
            int r = (int) pixel.r() * 255;
            int g = (int) pixel.g() * 255;
            int b = (int) pixel.b() * 255;
            os << r << " " << g << " " << b << " ";
         }
         os << std::endl;
      }

      return true;
   }
   catch (std::exception e)
   {
      return false;
   }
}
