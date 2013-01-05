CC = g++
SOURCES = Particle.cpp Vector.cpp
INCLUDE_PATHS = -I./../
LINKER_FLAGS = -lGL -lGLU -lglut -lSOIL 


ParticleForceGenerator.o : ParticleForceGenerator.h Particle.o
	$(CC) $(LINKER_FLAGS) $(INCLUDE_PATHS) -c Particle.h Particle.o

Particle.o : Particle.cpp Particle.h Vector.o
	$(CC) $(LINKER_FlAGS) $(INCLUDE_PATHS) -c Particle.cpp Particle.h Vector.o
Vector.o : Vector.h Vector.cpp
	$(CC) $(LINKER_FLAGS) $(INCLUDE_PATHS) -c Vector.cpp Vector.h	

all: ParticleForceGenerator.o

clean: rm *.o 
