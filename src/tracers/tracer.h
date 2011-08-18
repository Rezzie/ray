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

#ifndef _INCLUDED_F16A6E26CB52441D
#define _INCLUDED_F16A6E26CB52441D

#include "../common.h"

// Forward declarations
class Ray;
class Scene;


class Tracer
{

  public:

   //! Instantiates a default tracer.
   Tracer();

   //! Instantiates a new tracer.
   /*! \param scene The scene to trace.
    */
   Tracer(Scene *scene);

   //! Traces a ray, returning its colour.
   /*! \param ray The ray to trace.
    */
   Colour Trace(const Ray &ray) const;

  private:

   //! The scene to trace.
   Scene *s;

};

#endif // _INCLUDED_F16A6E26CB52441D
