CPPRC = cpprc
TEST = test

CXX = g++
CXXFLAGS = -O3

all:	$(CPPRC)

$(CPPRC): Compiler.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST): test.cpp $(CPPRC)
	./$(CPPRC) Makefile $(CPPRC)
	$(CXX) $(CXXFLAGS) -o $@ Resource.cpp $<
	./$(TEST)

clean:
	rm -rf $(CPPRC) $(TEST) Resource.*
