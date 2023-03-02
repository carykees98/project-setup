projectName = project-setup
cppStandard = c++17

sourceFolder = src/
output = build/$(projectName)

objects = help.o generator.o
main = $(sourceFolder)main.cpp

all: $(project-name)-main clean

$(project-name)-main: $(main) $(objects)
	g++ -std=$(cppStandard) $(main) $(objects) -o $(output)

help.o: $(sourceFolder)help.cpp $(sourceFolder)help.h
	g++ -c -std=$(cppStandard) $(sourceFolder)help.cpp

generator.o: $(sourceFolder)generator.cpp $(sourceFolder)generator.h
	g++ -c -std=$(cppStandard) $(sourceFolder)generator.cpp

clean: 
	rm *.o
