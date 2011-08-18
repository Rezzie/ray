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

#include "../common.h"

#include <iostream>
#include <string>


class RenderTarget
{

   public:

      //! Instantiates a new render target of the given dimensions.
      /*! \param width The width of the render target.
       *  \param height The height of the render target.
       */
      RenderTarget(int width, int height);

      //! Frees all memory used by the render target.
      ~RenderTarget();

      //! Gets the pixel at the given coordinates.
      /*! \param x The X-ordinate of the pixel.
       *  \param y The Y-ordinate of the pixel.
       */
      Colour GetPixel(int x, int y);

      //! Sets the pixel at the given coordinates to the specified colour.
      /*! \param x The X-ordinate of the pixel.
       *  \param y The Y-ordinate of the pixel.
       *  \param colour The colour to set the pixel to.
       */
      void SetPixel(int x, int y, Colour colour);

      //! Outputs the rendered image to the given stream.
      /*! \param os The output stream to write the file to.
       *  \retval true If the image is saved successfully.
       *  \retval false If the image wasn't saved successfully.
       */
      virtual bool Save(std::ostream &os) = 0;

   protected:

      int _width; /*! The width of the render target. */
      int _height; /*! The height of the render target. */

      //! The pixel colour data.
      Colour *_data;

};

#endif // _INCLUDED_62FAB5E09A7D41FF
