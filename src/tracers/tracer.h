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

#ifndef RAY_TRACERS_TRACER_H_
#define RAY_TRACERS_TRACER_H_

#include "common.h"
#include "ray.h"

// Forward declarations
class Scene;


//! Calculates the colour of a ray by tracing it through the scene.
class Tracer
{

 public:

  //! Instantiates a default tracer.
  Tracer();

  //! Instantiates a new tracer within the specified scene.
  Tracer(Scene *scene);

  /*! \brief Trace the given ray though the scene.
   *  \returns The final colour of the ray.
   */
  virtual Colour Trace(const Ray &ray) const;

 protected:

  //! The scene to trace.
  Scene *scene_;

};

#endif // RAY_TRACERS_TRACER_H_
