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

#include "image.h"

#include <stdio.h>


Image::Image(int width, int height)
   : _width(width), _height(height)
{
   _data = new Colour[width * height];
}

Image::~Image()
{
   delete[] _data;
}

Colour Image::GetPixel(int x, int y)
{
   return _data[x + y * _width];
}

void Image::SetPixel(int x, int y, Colour colour)
{
   _data[x + y * _width] = colour;
}

void Image::Save(std::string file)
{
   FILE *output = fopen(file.c_str(), "w");

   fprintf(output, "P3\n");
   fprintf(output, "%d %d\n", _width, _height);
   fprintf(output, "255\n");

   for (int y = 0; y < _height; y++)
   {
      for (int x = 0; x < _width; x++)
      {
         Colour pixel = this->GetPixel(x, y);
         fprintf(output, "%3d %3d %3d ", pixel.R, pixel.G, pixel.B);
      }
      fprintf(output, "\n");
   }

   fclose(output);
}
