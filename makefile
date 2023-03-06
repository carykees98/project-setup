projectName = project-setup
cppStandard = c++17

sourceFolder = src/
output = build/$(projectName)

objects = help.o generator.o logging.o
main = $(sourceFolder)main.cpp

all: $(project-name)-main clean

$(project-name)-main: $(main) $(objects) ./build
	g++ -std=$(cppStandard) $(main) $(objects) -o $(output)

help.o: $(sourceFolder)help.cpp $(sourceFolder)help.h
	g++ -c -std=$(cppStandard) $(sourceFolder)help.cpp

generator.o: $(sourceFolder)generator.cpp $(sourceFolder)generator.h
	g++ -c -std=$(cppStandard) $(sourceFolder)generator.cpp

logging.o: $(sourceFolder)logging.cpp $(sourceFolder)logging.h
	g++ -c -std=$(cppStandard) $(sourceFolder)logging.cpp

./build:
	mkdir build

clean: 
	rm *.o
