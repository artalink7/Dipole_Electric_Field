main: main.o Particle.o Position.o VectorField.o MaterialPoint.o
	g++ -o main main.o Particle.o Position.o VectorField.o MaterialPoint.o

Particle.o: Particle.cpp Particle.h
	g++ -c -o Particle.o Particle.cpp

Position.o: Position.cpp Position.h
	g++ -c -o Position.o Position.cpp

VectorField.o: VectorField.cpp VectorField.h
	g++ -c -o VectorField.o VectorField.cpp

MaterialPoint.o: MaterialPoint.cpp MaterialPoint.h
	g++ -c -o MaterialPoint.o MaterialPoint.cpp

main.o: main.cpp Particle.h Position.h VectorField.h MaterialPoint.h
	g++ -c -o main.o main.cpp