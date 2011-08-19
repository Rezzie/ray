CMAKE_MINIMUM_REQUIRED (VERSION 2.6)


#---[ Project Options ]---------------------------------------------------------

PROJECT (RAY)
SET (PROJECT_NAME "Ray")
STRING (TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)

# Versioning
SET (RAY_VERSION_MAJOR 0)
SET (RAY_VERSION_MINOR 1)
SET (RAY_VERSION_BUILD 0)
SET (RAY_VERSION_STR "0.1")

IF (NOT CMAKE_BUILD_TYPE)
   SET (CMAKE_BUILD_TYPE "RELEASE" CACHE STRING "Choose the type of build, options are: RELEASE (default) or DEBUG" FORCE)
ENDIF ()
STRING (TOUPPER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE)
MESSAGE (STATUS "Build type: ${CMAKE_BUILD_TYPE}")
MESSAGE (STATUS "  will install to ${CMAKE_INSTALL_PREFIX}")


#---[ Doxygen ]-----------------------------------------------------------------

SET (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE (UseDoxygen)


#---[ Project Sources ]---------------------------------------------------------

INCLUDE_DIRECTORIES (include)
INCLUDE_DIRECTORIES (src)

SET (SRCS src/main.cc
          src/ray.cc
          src/scene.cc
          src/viewplane.cc
          src/primitives/plane.cc
          src/primitives/primitive.cc
          src/primitives/sphere.cc
          src/renderers/rendertarget.cc
          src/renderers/ppm.cc
          src/tracers/singlesphere.cc
          src/tracers/tracer.cc)


#---[ Executable ]--------------------------------------------------------------

ADD_EXECUTABLE (ray ${SRCS})


#---[ Installation ]------------------------------------------------------------

INSTALL (TARGETS ray RUNTIME DESTINATION bin/)

# Documentation
#INSTALL (DIRECTORY   ${DOXYFILE_OUTPUT_DIR}/${DOXYFILE_HTML_DIR}
#         DESTINATION share/doc/${PROJECT_NAME_LOWER}
#         COMPONENT   doc
#         OPTIONAL)
