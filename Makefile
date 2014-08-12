SOURCE_DIR  = src
INCLUDE_DIR = include
LIBRARY_DIR = lib

TEST_DIR    = test
TOOL_DIR    = tools

CXX      = g++
CXXFLAGS = -std=c++1y -Wall -O3 -I$(INCLUDE_DIR)
AR       = ar
ARFLAGS  = rsv

TARGET = $(LIBRARY_DIR)/libmd5.a
SRCS   = $(SOURCE_DIR)/utils.cpp $(SOURCE_DIR)/md5.cpp $(SOURCE_DIR)/md5_ptr.cpp
OBJS   = $(subst .cpp,.o,$(SRCS))

t=$(shell find . -name lib | wc -c)

$(TARGET): $(OBJS)
ifeq ($t,0)
		mkdir $(LIBRARY_DIR)
endif
	$(AR) $(ARFLAGS) $@ $^

.SUFFIXES:	.cc .cpp
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
.cc.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: check
check: $(TARGET)
	cd ${TEST_DIR} && make && make check

.PHONY: tools
tools: $(TARGET)
	cd ${TOOL_DIR} && make

.PHONY: clean
clean: $(OBJS)
	rm -f $(SOURCE_DIR)/*.o

.PHONY: distclean
distclean: $(TARGET)
	make clean && rm -f $(TARGET)
ifneq ($t,0)
	rmdir $(LIBRARY_DIR)
endif
	cd ${TEST_DIR} && make distclean
	cd ${TEST_DIR} && make distclean
