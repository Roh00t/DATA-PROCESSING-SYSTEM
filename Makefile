# [!IMPORTANT] To be only run on Ubuntu and Windows OS. For MacOS, change .app to .run.

all: compile
compile: main.o Line2D.o Line3D.o Point2D.o Point3D.o PrintFileData.o ReadFileData.o algorithms.o GraphicRepresentation.o
	g++ -std=c++11 main.cpp Line2D.cpp Line3D.cpp Point2D.cpp Point3D.cpp PrintFileData.cpp ReadFileData.cpp algorithms.cpp GraphicRepresentation.cpp -o csci251_a3.app
		./csci251_a3.app
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Line2D.o: Line2D.cpp Line2D.h
	g++ -std=c++11 -c Line2D.cpp
Point2D.o: Point2D.cpp Point2D.h
	g++ -std=c++11 -c Point2D.cpp
Point3D.o: Point3D.cpp Point3D.h
	g++ -std=c++11 -c Point3D.cpp
PrintFileData.o: PrintFileData.cpp PrintFileData.h MyTemplates.h
	g++ -std=c++11 -c PrintFileData.cpp
ReadFileData.o: ReadFileData.cpp ReadFileData.h MyTemplates.h
	g++ -std=c++11 -c ReadFileData.cpp
algorithms.o: algorithms.cpp algorithms.h
	g++ -std=c++11 -c algorithms.cpp
GraphicRepresentation.o: GraphicRepresentation.cpp GraphicRepresentation.h
	g++ -std=c++11 -c GraphicRepresentation.cpp

# Removes all object files:
clean:
	rm *.o