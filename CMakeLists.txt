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

SET (SRCS src/main.cpp
          src/ray.cpp
          src/camera.cpp
          src/rendersurface.cpp
          src/primitives/primitive.cpp
          src/primitives/sphere.cpp)


#---[ Executable ]--------------------------------------------------------------

ADD_EXECUTABLE (ray ${SRCS})


#---[ Installation ]------------------------------------------------------------

INSTALL (TARGETS ray RUNTIME DESTINATION bin/)

# Documentation
#INSTALL (DIRECTORY   ${DOXYFILE_OUTPUT_DIR}/${DOXYFILE_HTML_DIR}
#         DESTINATION share/doc/${PROJECT_NAME_LOWER}
#         COMPONENT   doc
#         OPTIONAL)
