include_directories(
  ${RENDERER_SOURCE_DIR}
  ${RENDERER_SOURCE_DIR}/externals
  ./externals
)

add_library(GeometricEntities STATIC
  Vector.cpp
  Mat4.cpp
)

add_library(Quaternions STATIC
 Quaternion.cpp
)

target_link_libraries(Quaternions GeometricEntities)

add_library(Conversions STATIC
  Conversion.cpp
)

target_link_libraries(Conversions Quaternions)

add_library(Gravel STATIC 
  Particle.cpp
  ParticleForceGenerator.cpp
  PFholder.cpp
)

target_link_libraries(Gravel Conversions)

add_subdirectory(tests)
