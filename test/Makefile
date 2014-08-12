SRC_DIR=src

CXX      = g++
CXXFLAGS = -std=c++1y -Wall -O3 -I../include
LD       = g++
LDFLAGS  = -L../lib

TARGET1 = test01.exe
TARGET2 = test02.exe
SRCS   = $(SRC_DIR)/test01.cpp $(SRC_DIR)/test02.cpp
OBJS   = $(subst .cpp,.o,$(SRCS))

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $< -lmd5

$(TARGET2): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $< -lmd5

.SUFFIXES:	.cc .cpp
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: check
check: $(TARGET)
	@./check

.PHONY: clean
clean: $(OBJS)
	rm -f *.o

.PHONY: distclean
distclean: $(TARGET1) $(TARGET2)
	make clean && rm -f {$(TARGET1),$(TARGET2)} 
