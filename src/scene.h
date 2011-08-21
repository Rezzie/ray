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

#include <vector>

#include "primitives/primitive.h"
#include "viewplane.h"

// Forward declarations
class Tracer;


class Scene
{

 public:

  //! Instantiates a default scene.
  Scene();

  //! Gets the background colour of the scene.
  RGBColour& background_colour();

  //! Sets the background colour of the scene.
  void set_background_colour(const RGBColour &value);

  //! Gets the tracer used to trace rays through the scene.
  Tracer* tracer();

  //! Sets the tracer used to trace rays through the scene.
  void set_tracer(Tracer *value);

  //! Gets the viewing plane of the scene.
  ViewPlane& vp();

  //! Sets the viewing plane of the scene.
  void set_vp(const ViewPlane &value);

  //! Adds an object to the scene.
  void AddObject(Primitive *object);

  //! Constructs a scene.
  void Build();

  //! Renders a scene.
  void Render() const;

  //! A list of objects in the scene.
  std::vector<Primitive *> objects;

 private:

  //! The ray tracer used for rendering.
  Tracer *tracer_;

  //! The scene's viewing plane.
  ViewPlane vp_;

  //! The scene's background colour (for when a ray misses all primitives).
  RGBColour background_colour_;

};

#endif // RAY_SCENE_H_
