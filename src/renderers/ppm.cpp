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

#include "ppm.h"

#include "rendertarget.h"

#include <stdexcept>


PPM::PPM(int width, int height)
   : RenderTarget(width, height)
{
}


PPM::PPM(int width, int height, std::string filename)
   : RenderTarget(width, height),
     _filename(filename)
{
}


std::string PPM::GetFilename() const
{
   return _filename;
}


void PPM::SetFilename(std::string value)
{
   _filename = value;
}


bool PPM::Save()
{
   // FILE *output = fopen(file.c_str(), "w");

   // fprintf(output, "P3\n");
   // fprintf(output, "%d %d\n", _width, _height);
   // fprintf(output, "255\n");

   // for (int y = 0; y < _height; y++)
   // {
   //    for (int x = 0; x < _width; x++)
   //    {
   //       Colour pixel = this->GetPixel(x, y);
   //       fprintf(output, "%3d %3d %3d ", pixel.r(), pixel.g(), pixel.b());
   //    }
   //    fprintf(output, "\n");
   // }

   // fclose(output);
   return true;

}
