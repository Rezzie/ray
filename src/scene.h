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

#ifndef RAY_SCENE_H_
#define RAY_SCENE_H_

#include "common.h"

#include "primitives/sphere.h"
#include "viewplane.h"

// Forward declarations
class Tracer;


class Scene
{

  public:

   //! Instantiates a default scene.
   Scene();

   //! Constructs a scene.
   void Build();

   //! Renders a scene.
   void Render() const;

   // Temporarily hardcoding this.
   Sphere sphere;

  private:

   //! The scene's viewing plane.
   ViewPlane vp_;

   //! The scene's background colour (for when a ray misses all primitives).
   Colour background_;

   //! The ray tracer used for rendering.
   Tracer *tracer_;

};

#endif // RAY_SCENE_H_
