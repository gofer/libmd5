CXX=g++
CXXFLAGS=-std=c++1y -Wall -O3 -I../include
LD=g++
LDFLAGS=-L../lib

TARGET=md5
OBJS=md5cmd.o

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $< -lmd5

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o

distclean:
	make clean && rm -f $(TARGET)
