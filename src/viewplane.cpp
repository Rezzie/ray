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


ViewPlane::ViewPlane()
   : w(640),
     h(480),
     s(1.0)
{
}


ViewPlane::ViewPlane(int width, int height)
   : w(width),
     h(height),
     s(1.0)
{
}


ViewPlane::ViewPlane(int width, int height, double size)
   : w(width),
     h(height),
     s(size)
{
}


int ViewPlane::GetWidth() const
{
   return w;
}


void ViewPlane::SetWidth(int value)
{
   w = value;
}


int ViewPlane::GetHeight() const
{
   return h;
}


void ViewPlane::SetHeight(int value)
{
   h = value;
}


int ViewPlane::GetSize() const
{
   return s;
}


void ViewPlane::SetSize(int value)
{
   s = value;
}
