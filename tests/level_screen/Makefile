CXX=g++
CC=$(CXX)

CFLAGS = -pedantic -Wall -Werror
CFLAGS += -ggdb
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -ljsoncpp
CXXFLAGS = $(CFLAGS) -std=c++17

CPPFLAGS = -DDEBUG
CPPFLAGS += -I$(INCLUDES_DIR)

INCLUDES_DIR = ../../inc
SOURCES_DIR = ../../src

OBJECTS = utest.o $(SOURCES_DIR)/player.o $(SOURCES_DIR)/level_screen.o $(SOURCES_DIR)/font.o $(SOURCES_DIR)/ball.o $(SOURCES_DIR)/brick.o $(SOURCES_DIR)/paddle.o $(SOURCES_DIR)/timer.o $(SOURCES_DIR)/board.o $(SOURCES_DIR)/text.o $(SOURCES_DIR)/audio.o


TARGET = utest

all: $(TARGET)

$(TARGET) : $(OBJECTS)

utest : $(SOURCE)

check : $(TARGET)
	@./$(TARGET) -v

recheck: clean check

clean:
	@$(RM) -f ./$(TARGET) $(OBJECTS)


.PHONY : make clean check recheck all



