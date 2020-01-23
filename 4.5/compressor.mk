
.PHONY: build clean

build: compressor.exe

clean:
	rm -f compressor.exe compressor.o  

compressor.exe: compressor.o 
	g++  compressor.o -o compressor.exe

compressor.o: compressor.cpp ../07-library/compressor.hpp
	g++ -c compressor.cpp -o compressor.o

compress: compressor.exe
	sudo ./compressor.exe 









#-std=c++17
