all: proj4.x

proj4.x: proj4_driver.cpp bet.cpp
	g++6 -o proj4.x proj4_driver.cpp bet.cpp

clean:
	rm *.0 run
