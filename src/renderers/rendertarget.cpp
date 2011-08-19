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

#include "renderers/rendertarget.h"


RenderTarget::RenderTarget(int width, int height)
   : _width(width),
     _height(height)
{
   _data = new Colour[width * height];
}


RenderTarget::~RenderTarget()
{
   delete[] _data;
}


Colour RenderTarget::GetPixel(int x, int y)
{
   if (x > _width)
      throw std::out_of_range ("x");
   if (y > _height)
      throw std::out_of_range ("y");

   return _data[x + y * _width];
}


void RenderTarget::SetPixel(int x, int y, Colour colour)
{
   _data[x + y * _width] = colour;
}
