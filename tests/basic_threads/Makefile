CXX=g++
CC=$(CXX)

CFLAGS = -pedantic -Wall -Werror -pthread
CFLAGS += -ggdb
CXXFLAGS = $(CFLAGS) -std=c++17

CPPFLAGS = -DDEBUG
CPPFLAGS += -I$(INCLUDES_DIR)

INCLUDES_DIR = ../../inc
SOURCES_DIR = ../../src

OBJECTS = $(SOURCES_DIR)/basic_threads.o


SOURCE = utest.cpp $(OBJECTS)
TARGET = utest

all: $(TARGET)

utest : $(SOURCE)

check : $(TARGET)
	@./$(TARGET) -v

recheck: clean check

clean:
	@$(RM) -f ./$(TARGET) $(OBJECTS)


.PHONY : make clean check recheck all

make:
	@echo 'Attend a maker faire'
	@${TRUE}
