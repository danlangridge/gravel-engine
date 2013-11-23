include_directories(
  ${RENDERER_SOURCE_DIR}
  ${RENDERER_SOURCE_DIR}/externals
)

add_library(GeometricEntities STATIC
  Vector.cpp
  Mat4.cpp
)

add_library(Quaternions STATIC
 Quaternion.cpp
)

target_link_libraries(Quaternions GeometricEntities)

add_library(Gravel STATIC 
  Particle.cpp
  ParticleForceGenerator.cpp
  PFholder.cpp
)

target_link_libraries(Gravel GeometricEntities Quaternions)

