include_directories(
  ${RENDERER_SOURCE_DIR}
  ${RENDERER_SOURCE_DIR}/externals
)

add_library(Gravel STATIC 
  Vector.cpp 
  Particle.cpp
  ParticleForceGenerator.cpp
  PFholder.cpp
)

add_library(Vector Vector.cpp)
add_library(Particle Particle.cpp)
