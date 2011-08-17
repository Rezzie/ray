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

#ifndef _INCLUDED_62FAB5E09A7D41FF
#define _INCLUDED_62FAB5E09A7D41FF

#include <string>


struct Colour
{
   int R;
   int G;
   int B;
};

enum ImageFormat
{
   PPM
};

class RenderSurface
{

   public:

      RenderSurface(int width, int height);
      ~RenderSurface();

      Colour GetPixel(int x, int y);
      void SetPixel(int x, int y, Colour colour);

      void Save(std::string file, ImageFormat format = PPM);

   private:

      int _width;
      int _height;

      Colour *_data;

      void ToPPM(FILE* output);

};

#endif // _INCLUDED_62FAB5E09A7D41FF
