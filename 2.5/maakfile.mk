
.PHONY: build clean

build: generator

clean:
	rm -f generator generator.o melody.o

generator: generator.cpp melody.cpp
	g++ -std=c++17 generator.cpp melody.cpp -o generator.o

melody.cpp: generator
	./generator >  melody.cpp