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

 /*! @file common.h */

#ifndef RAY_COMMON_H_
#define RAY_COMMON_H_

#include <vmmlib/vector.hpp>


//---[ Type Definitions ]-------------------------------------------------------

typedef vmml::vec3d Normal3;    //!< A 3-dimensional normal vector.
typedef vmml::vec3d Point3;     //!< A 3-dimensional point.
typedef vmml::vec3d Vector3;    //!< A 3-dimensional vector.
typedef vmml::vec3f RGBColour;  //!< A red/green/blue tuple.


//---[ Constants ]--------------------------------------------------------------

//! The difference between 1 and the least value greater than 1 that is representable by a double.
static const double kEpsilon = std::numeric_limits<double>::epsilon();
//! The maximum finite value of a double.
static const double kHugeVal = std::numeric_limits<double>::max();


#endif // RAY_COMMON_H_
