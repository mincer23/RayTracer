compile:
	g++ -std=c++11 -Wall .\Ray.cpp .\ImagePlane.cpp .\raytracer.cpp .\plane.cpp .\Camera.cpp .\Trace.cpp .\Sphere.cpp .\sceneobject.cpp
run:
	./a.out output.ppm
remove:
	*.out