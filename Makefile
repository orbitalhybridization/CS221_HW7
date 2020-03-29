foo.wc:foo.txt
	wc foo.txt > foo.wc

%.wc: %.txt
	wc $*.txt > $*.wc

CXX = g++
CCFLAGS = -g -Wall -Wextra -pedantic -std=c++17

# this is a "Suffix Rule" - how to create a .o from a .cc file
.cpp.o:
	$(CXX) $(CCFLAGS) -c $<

highest: highest.o
	$(CXX) $(CCFLAGS) -o highest highest.o

clean:
	rm -f *.o
	rm -f *.wc
