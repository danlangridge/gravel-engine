CC = g++
SOURCES = Particle.cpp Vector.cpp
INCLUDE_PATHS = -I./../
LINKER_FLAGS = -lGL -lGLU -lglut -lSOIL 


PFholder.o : ParticleForceGenerator.o
	$(CC) $(LINKER_FLAGS) $(INCLUDE_PATHS) -c PFholder.cpp

ParticleForceGenerator.o : Particle.o
	$(CC) $(LINKER_FLAGS) $(INCLUDE_PATHS) -c ParticleForceGenerator.cpp

Particle.o : Vector.o
	$(CC) $(LINKER_FlAGS) $(INCLUDE_PATHS) -c Particle.cpp
Vector.o :
	$(CC) $(LINKER_FLAGS) $(INCLUDE_PATHS) -c Vector.cpp

all: PFholder.o

clean: rm *.o 
