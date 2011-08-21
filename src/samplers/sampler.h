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

#ifndef RAY_SAMPLERS_SAMPLER_H_
#define RAY_SAMPLERS_SAMPLER_H_

#include "common.h"


//! Samples a pixel multiple times to reduce aliasing and moire patterns.
class Sampler
{

 public:

  //! Instantiates a new sampler.
  Sampler();

  //! Gets the number of samples per pixel.
  int samples() const;

  //! Sets the number of samples per pixel.
  void set_samples(int value);

 protected:

  int samples_;  //!< The number of samples to take per pixel.

};

#endif // RAY_SAMPLERS_SAMPLER_H_
