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

#ifndef _INCLUDED_88AFB763CCA647E8
#define _INCLUDED_88AFB763CCA647E8

#include "primitive.h"

#include <vmmlib/vector.hpp>

// // Forward declaration
class Ray;

using namespace vmml;


class Sphere : public Primitive
{
   public:

      Sphere(vec3f centre, float radius);

      vec3f& GetCentre();

      float GetRadius();

      float GetRadiusSq();

      bool Intersect(Ray &ray, float &dist);

      void SetCentre(vec3f value);

      void SetRadius(float value);

   private:

      vec3f _centre;

      float _radius;

};

#endif // _INCLUDED_88AFB763CCA647E8
