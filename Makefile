main: main.o funcs.o
	g++ -o main main.o funcs.o

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o



funcs.o: funcs.cpp funcs.h coord3d.h particle.h

main.o: main.cpp funcs.h coord3d.h particle.h

tests.o: tests.cpp doctest.h funcs.h

clean:
	rm -f main.o funcs.o tests.o
