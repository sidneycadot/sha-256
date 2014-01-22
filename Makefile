
CXXFLAGS = -W -Wall -O3 -std=c++11

sha-256 : sha-256.cc sha-256.h xuint32_t.h
#expr_uint32_t.h

clean :
	$(RM) sha-256 *~
