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

#ifndef RAY_RENDERERS_PPM_H_
#define RAY_RENDERERS_PPM_H_

#include "common.h"
#include "renderers/rendertarget.h"


//! Outputs a rendered image as a (rawbits) PPM.
class PPM : public RenderTarget
{

   public:

      //! Instantiates a default PPM render target.
      PPM();

      //! Instantiates a new PPM render target with the given dimensions.
      PPM(int width, int height);

      virtual void Save(FILE *output) const;

};

#endif // RAY_RENDERERS_PPM_H_
