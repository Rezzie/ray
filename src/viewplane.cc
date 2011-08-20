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

#include "viewplane.h"

static const int kDefaultHRes = 480;
static const int kDefaultVRes = 640;
static const double kDefaultSize = 1.0;


ViewPlane::ViewPlane()
    : hres_(kDefaultHRes),
      vres_(kDefaultVRes),
      size_(kDefaultSize)
{}


ViewPlane::ViewPlane(int width, int height)
    : hres_(width),
      vres_(height),
      size_(kDefaultSize)
{}


ViewPlane::ViewPlane(int width, int height, double size)
    : hres_(width),
      vres_(height),
      size_(size)
{}


int ViewPlane::hres() const
{
  return hres_;
}


void ViewPlane::set_hres(int value)
{
  hres_ = value;
}


int ViewPlane::vres() const
{
  return vres_;
}


void ViewPlane::set_vres(int value)
{
  vres_ = value;
}


double ViewPlane::size() const
{
  return size_;
}


void ViewPlane::set_size(double value)
{
  size_ = value;
}
