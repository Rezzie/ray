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

#include <cassert>


RenderTarget::RenderTarget()
    : width_(640),
      height_(480)
{
  Init();
}


RenderTarget::RenderTarget(int width, int height)
    : width_(width),
      height_(height)
{
   Init();
}


RenderTarget::~RenderTarget()
{
   delete[] data_;
}


Colour RenderTarget::get_pixel(int x, int y) const
{
   assert(x < width_ && y < height_);
   return data_[x + y * width_];
}


void RenderTarget::set_pixel(int x, int y, Colour colour)
{
   assert(x < width_ && y < height_);
   data_[x + y * width_] = colour;
}

void RenderTarget::Init()
{
   data_ = new Colour[width_ * height_];
}
