
.PHONY: build clean

build: generator 

clean:
	rm -f generator.exe generator.o melody.o

generator: generator.o melody.o
	g++  generator.o -o generator.exe

generator.o: generator.cpp 
	g++ -c generator.cpp -o generator.o

melody.o: melody.hpp note_player.hpp
	g++ -c melody.hpp -o melody.o

melody.cpp: generator.exe
	./generator.exe > melody.cpp









#-std=c++17
