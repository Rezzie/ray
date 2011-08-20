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

#ifndef RAY_VIEWPLANE_H_
#define RAY_VIEWPLANE_H_

#include "common.h"


//! Represents a viewing plane.
class ViewPlane
{

 public:

  //! Instantiates a default viewing plane.
  ViewPlane();

  //! Instantiates a new viewing plane with the given resolution.
  ViewPlane(int width, int height);

  //! Instantiates a new viewing plane with the given resolution and anti-aliasing sample count.
  ViewPlane(int width, int height, int samples);

  //! Instantiates a new viewing plane with the given resolution and pixel size.
  ViewPlane(int width, int height, double size);

  //! Instantiates a new viewing plane with the given resolution, pixel size and anti-aliasing sample count.
  ViewPlane(int width, int height, double size, int samples);

  //! Gets the horizontal resolution of the viewing plane.
  int hres() const;

  //! Sets the horizontal resolution of the viewing plane.
  void set_hres(int value);

  //! Gets the vertical resolution of the viewing plane.
  int vres() const;

  //! Sets the vertical resolution of the viewing plane.
  void set_vres(int value);

  //! Gets the size of each pixel in the viewing plane.
  double size() const;

  //! Sets the size of each pixel in the viewing plane.
  void set_size(double value);

  //! Gets the number of samnples per pixel.
  int samples() const;

  //! Sets the number of samples per pixel;
  void set_samples(int value);

 private:

  int    hres_;     //!< The horizontal resolution of the viewing plane.
  int    vres_;     //!< The vertical resolution of the viewing plane.
  double size_;     //!< The size of each pixel in the viewing plane.
  int    samples_;  //!< The number of samples per pixel.

};

#endif // RAY_VIEWPLANE_H_
