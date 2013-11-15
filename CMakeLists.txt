include_directories(
  ${RENDERER_SOURCE_DIR}
  ${RENDERER_SOURCE_DIR}/externals
)

add_library(Gravel STATIC 
  Vector.cpp
  Quaternion.cpp
  Particle.cpp
  ParticleForceGenerator.cpp
  PFholder.cpp
)
