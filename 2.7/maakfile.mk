
.PHONY: build clean

build: generator 

generator: generator.obj melody.obj
	g++  generator.obj -o generator.exe

generator.obj: generator.cpp 
	g++ -c generator.cpp -o generator.obj

melody.obj: melody.hpp note_player.hpp
	g++ -c melody.hpp -o melody.obj

melody.cpp: generator.exe
	./generator.exe > melody.cpp









#-std=c++17
