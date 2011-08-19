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

		//! Instantiates a new viewing plane.
		/*! \param width The horizontal resolution of the viewing plane.
		*  \param height The vertical resolution of the viewing plane.
		*/
		ViewPlane(int width, int height);

		//! Instantiates a new viewing plane.
		/*! \param width The horizontal resolution of the viewing plane.
		*  \param height The vertical resolution of the viewing plane.
		*  \param size The size of each pixel in the viewing plane.
		*/
		ViewPlane(int width, int height, double size);

      //! Gets the horizontal resolution of the viewing plane.
      int GetWidth() const;

      //! Sets the horizontal resolution of the viewing plane.
      /*! \param value The new horizontal resolution.
       */
      void SetWidth(int value);

      //! Gets the vertical resolution of the viewing plane.
      int GetHeight() const;

      //! Sets the vertical resolution of the viewing plane.
      /*! \param value The new vertical resolution.
       */
      void SetHeight(int value);

      //! Gets the size of each pixel in the viewing plane.
      int GetSize() const;

      //! Sets the size of each pixel in the viewing plane.
      /*! \param value The new size of each pixel.
       */
      void SetSize(int value);


	private:

		int w; /*! The horizontal resolution of the viewing plane. */
		int h; /*! The vertical resolution of the viewing plane. */

		//! The size of each pixel in the viewing plane.
		double s;

};

#endif // RAY_VIEWPLANE_H_
