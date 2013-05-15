all:test

CPPFLAGS+=-std=c++0x
CPPFLAGS+=-g -O0 -Wall -pedantic
CPPFLAGS+=-I ~/custom/boost/
CPPFLAGS+=-I ../include/

LDFLAGS+=-L ../.libs -lopus

# CXX=clang++
# CC=clang
# CXX=/usr/lib/gcc-snapshot/bin/g++
# CC=/usr/lib/gcc-snapshot/bin/gcc

test: test.cpp COpusCodec.cpp
	$(CXX) $(CPPFLAGS) $^ -o $@ $(LDFLAGS)
