# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

# Target executable
TARGET = main

# Source files (only .cpp)
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp to .o
%.o: %.cpp vector.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

