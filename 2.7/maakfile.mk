
.PHONY: build clean

build: generator.exe

clean:
	rm -f generator generator.o  rtttl_player.o

generator.exe: generator.o rtttl_player.o 
	g++  generator.o  rtttl_player.o -o generator.exe

generator.o: generator.cpp note_generator.hpp rtttl_player.hpp note_player.hpp note.hpp
	g++ -c generator.cpp -o generator.o

rtttl_player.o: rtttl_player.hpp rtttl_player.cpp note_player.hpp note.hpp
	g++ -c rtttl_player.cpp -o rtttl_player.o

melody.cpp: generator.exe
	./generator.exe > melody.cpp









#-std=c++17
