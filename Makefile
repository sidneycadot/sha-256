
CXXFLAGS = -W -Wall -O3 -std=c++11

sha2 : sha2.cc sha2.h xuint_t.h

clean :
	$(RM) sha2 *~
