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

#ifndef _INCLUDED_4E1D6C0DBB9C4562
#define _INCLUDED_4E1D6C0DBB9C4562

#include "common.h"
#include "tracers/tracer.h"

// Forward declarations
class Ray;


class SingleSphere : public Tracer
{

  public:

   //! Instantiates a default tracer.
   SingleSphere();

   //! Instantiates a new tracer.
   /*! \param scene The scene to trace.
    */
   SingleSphere(Scene *scene);

   //! Traces a ray, returning its colour.
   /*! \param ray The ray to trace.
    */
   virtual Colour Trace(const Ray &ray) const;

};

#endif // _INCLUDED_4E1D6C0DBB9C4562
