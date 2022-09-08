# 	Trevor Berggren
#	z1906236
#	CSCI 340 
#
#	I certify that this is my own work and where appropriate an extension 
#	of the starter code provided for the assignment.
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file
twosort: twosort.o
	$(CXX) $(CXXFLAGS) -o twosort $^

# Rules to compile source code files to object code
twosort.o: twosort.cc twosort.h

# Phony target to remove object code and executable files
clean:
	rm -f twosort *.o
