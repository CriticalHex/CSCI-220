TARGET = main.exe
SRC_FILES = ../main.cpp

OBJECTS = $(SRC_FILES:.cpp=.o)

INCLUDE_PATH = -I"C:\mingw64\include"

LIBS =
LIB_PATH =

CXX = g++

all: $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CXX) -o $@ $^ $(LIB_PATH) $(LIBS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(INCLUDE_PATH)

clean:
	@$(RM) $(OBJECTS) $(TARGET)

run:
	@$(TARGET)

.PHONY: clean run

main.o: main.cpp