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

#ifndef _INCLUDED_7770A54E803F4920
#define _INCLUDED_7770A54E803F4920

#include "../common.h"

#include "rendertarget.h"

#include <iostream>


class PPM : public RenderTarget
{

   public:

      //! Instantiates a new render target of the given dimensions.
      /*! \param width The width of the render target.
       *  \param height The height of the render target.
       */
      PPM(int width, int height);

      //! Instantiates a new render target of the given dimensions.
      /*! \param width The width of the render target.
       *  \param height The height of the render target.
       *  \param filename The file to output the PPM to.
       */
      PPM(int width, int height, std::string filename);

      bool Save(std::ostream &os);

};

#endif // _INCLUDED_7770A54E803F4920
