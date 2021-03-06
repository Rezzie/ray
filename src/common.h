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

#ifndef RAY_COMMON_H_
#define RAY_COMMON_H_

#include <vmmlib/vector.hpp>


//---[ Type Definitions ]-------------------------------------------------------

typedef vmml::vec3d Vector3;
typedef vmml::vec3f Colour;


//---[ Constants ]--------------------------------------------------------------

static const double kEpsilon = std::numeric_limits<double>::epsilon();


#endif // RAY_COMMON_H_
