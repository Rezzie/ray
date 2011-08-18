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

#ifndef _INCLUDED_8E4E9230B9F644FC
#define _INCLUDED_8E4E9230B9F644FC

#include "common.h"

#include "primitives/sphere.h"
#include "tracers/tracer.h"
#include "viewplane.h"


class Scene
{

  public:

   //! Instantiates a default scene.
   Scene();

   //! Constructs a scene.
   void Build();

   //! Renders a scene.
   void Render() const;

  private:

   //! The scene's viewing plane.
   ViewPlane vp;

   //! The scene's background colour, when a ray misses all primitives.
   Colour background;

   //! The ray tracer used for rendering.
   Tracer *tracer;

   Sphere sphere;

};

#endif // _INCLUDED_8E4E9230B9F644FC