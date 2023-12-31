#
# Mark's Magic Makefile
#
# Instructions:
#
# 1. Add .cc files (not .h files) to the line beginning with SRCS = main.cc.
#    Files should be separated with spaces, not commas.  If all of the
#    .cc files in the directory should be included in the build, then you
#    can avoid maintaining a specific list of source files by commenting
#    out the first SRCS line and uncommenting the second (as done below).
# 2. Type 'make depend' to build or update the dependency list.  Do this
#    whenever you add this Makefile or add a .cc or .h file to a project.
# 3. Type 'make' to build the project.
# 4. Type 'make clean' to start over or prepare for submission.  This does
#    not remove the dependency information.
#
# N.B. If you're using files with .cpp extensions, then you need to search
# and replace cc with cpp.
#

DRIVER_NAME = main
SUBMIT_NAME = submit

p2: main.o Chaining.o QuadProbing.o DoubleHash.o
	g++ main.o Chaining.o QuadProbing.o DoubleHash.o -o p2

main.o: main.cpp Chaining.h QuadProbing.h DoubleHash.o
	g++ -c main.cpp

chaining.o: Chaining.cpp Chaining.h
	g++ -c Chaining.cpp

quadProbing.o: QuadProbing.cpp QuadProbing.h
	g++ -c QuadProbing.cpp

DoubleHash.o: DoubleHash.cpp DoubleHash.h
	g++ -c DoubleHash.cpp

submit:
	rm -f submit.zip
	zip submit.zip $(DRIVER_NAME).cpp Chaining.cpp Chaining.h QuadProbing.cpp QuadProbing.h DoubleHash.cpp DoubleHash.h Makefile

#p1: main.o LL.o MTFList.o orderedList.o
#	g++ main.o LL.o MTFList.o orderedList.o -o p1

#main.o: main.cpp LL.hpp MTFList.hpp orderedList.hpp
#	g++ -c main.cpp
	
#LL.o:  LL.cpp LL.hpp
#	g++ -c LL.cpp
	
#MTFList.o: MTFList.cpp MTFList.hpp
#	g++ -c MTFList.cpp
	
#orderedList.o: orderedList.cpp orderedList.hpp
#	g++ -c orderedList.cpp
	
#submit:
#	rm -f submit.zip
#	zip submit.zip $(DRIVER_NAME).cpp  LL.hpp LL.cpp MTFList.cpp MTFList.hpp orderedList.hpp orderedList.cpp Makefile