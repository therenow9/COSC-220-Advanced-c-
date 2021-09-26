  #Lab 5
#Jeremy Scheuerman
#Make file
#The files we are combining bar.cpp,bar.h,foo.cpp,foo.h,prog.cpp
prog: bar.o foo.o prog.o
	g++ bar.o foo.o prog.o -o prog

#rule for making bar.o
bar.o: bar.cpp bar.h
	g++ -c bar.cpp

#rule for making foo.o
foo.o: foo.cpp foo.h
	g++ -c foo.cpp

#rule for making prog.o
prog.o: prog.cpp
	g++ -c prog.cpp 

#rule for cleaning up
clean:
	rm bar.o foo.o prog.o





