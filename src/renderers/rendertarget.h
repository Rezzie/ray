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

#ifndef RAY_RENDERERS_RENDERTARGET_H_
#define RAY_RENDERERS_RENDERTARGET_H_

#include <cstdio>

#include "common.h"


//! Provides a surface for the raytracer to render pixels to.
class RenderTarget
{

 public:

  //! Instantiates a default render target.
  RenderTarget();

  //! Instantiates a new render target with the given dimensions.
  RenderTarget(int width, int height);

  ~RenderTarget();

  //! Gets the colour of the pixel at the given coordinates.
  Colour get_pixel(int x, int y) const;

  //! Sets the colour of the pixel at the given coordinates.
  void set_pixel(int x, int y, Colour colour);

  /*! \brief Saves the rendered image to the given stream.
   *  \param os An output stream to write the image to.
   *  \retval true If the image is saved successfully.
   *  \retval false If the image wasn't saved successfully.
   */
  virtual void Save(FILE *output) const = 0;

 protected:

  int width_;     //!< The width of the render target.
  int height_;    //!< The height of the render target.
  Colour *data_;  //!< The pixel colour data.

 private:

  //! Allocates the memory for storing the pixel data.
  void Init();

};

#endif // RAY_RENDERERS_RENDERTARGET_H_
