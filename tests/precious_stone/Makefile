CXX=g++
CC=$(CXX)

CFLAGS = -pedantic -Wall -Werror
CFLAGS += -ggdb
CXXFLAGS = $(CFLAGS) -std=c++17

CPPFLAGS = -DDEBUG
CPPFLAGS += -I$(PRECIOUS_INCLUDES_DIR) -I$(INCLUDES_DIR)

INCLUDES_DIR = ../../inc

PRECIOUS_INCLUDES_DIR = ../../inc/precious_stone
PRECIOUS_SOURCES_DIR = ../../src/precious_stone


INFRA = $(PRECIOUS_SOURCES_DIR)/stream_destination.o \
		$(PRECIOUS_SOURCES_DIR)/stream_source.o \
			$(PRECIOUS_SOURCES_DIR)/message.o \
				$(PRECIOUS_SOURCES_DIR)/udp_source.o\
					$(PRECIOUS_SOURCES_DIR)/udp.o\
						$(PRECIOUS_SOURCES_DIR)/convert_caesar.o\
							$(PRECIOUS_SOURCES_DIR)/file_source.o\
								$(PRECIOUS_SOURCES_DIR)/file_destination.o\
									$(PRECIOUS_SOURCES_DIR)/convert_vowel.o\
										$(PRECIOUS_SOURCES_DIR)/convert_capitalize.o\
											$(PRECIOUS_SOURCES_DIR)/black_box.o\

OBJECTS = utest.o $(INFRA)
TARGET = utest

all: $(TARGET)

$(TARGET): $(OBJECTS)

check : $(TARGET)
	@./$(TARGET) -v

recheck: clean check

clean:
	@$(RM) -f ./$(TARGET) $(OBJECTS)


.PHONY : make clean check recheck all

# dependencies

$(PRECIOUS_SOURCES_DIR)/console_destination.o : $(PRECIOUS_SOURCES_DIR)/stream_destination.cpp
$(PRECIOUS_SOURCES_DIR)/console_destination.cpp: $(PRECIOUS_INCLUDES_DIR)/stream_destination.hpp
$(PRECIOUS_INCLUDES_DIR)/console_destination.hpp: $(PRECIOUS_INCLUDES_DIR)/destination.hpp
$(PRECIOUS_INCLUDES_DIR)/destination.hpp: $(PRECIOUS_INCLUDES_DIR)/message.hpp


