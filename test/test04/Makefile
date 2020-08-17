TARGET = test.out
SRCS = test.cpp
OBJS = $(addsuffix .o,$(basename $(SRCS)))

CXXFLAGS = -std=c++11 -Wall -O3 -I../../include $(shell pkg-config --cflags gtest gtest_main)
LDFLAGS = -L../../lib $(shell pkg-config --libs gtest gtest_main)

LIBS = -lmd5 

.SUFFIXES:  .c .cc .cpp .h. .hpp
.PHONY: all check clean distclean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $< 

check: $(TARGET)
	@GTEST_COLOR=1 ./$(TARGET)

clean:
	rm -f *.o

distclean:
	make clean && rm -f $(TARGET) 
