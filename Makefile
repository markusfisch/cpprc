CPPRC = cpprc
PROBE = probe

CXX = g++
FLAGS = -O3

all:	$(CPPRC) $(PROBE)

$(CPPRC): Compiler.cpp main.cpp
	$(CXX) $(FLAGS) -o $@ Compiler.cpp main.cpp

$(PROBE): $(CPPRC) probe.cpp
	./$(CPPRC) Makefile $(CPPRC)
	$(CXX) $(FLAGS) -o $@ Resource.cpp probe.cpp
	./$(PROBE)

clean:
	rm -rf $(CPPRC) $(PROBE) Resource.*
