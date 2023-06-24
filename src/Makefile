CXX = g++
CXXFLAGS = -std=c++17

SRCS = tests.cpp singleton.cpp

TARGET = my_Program

all: $(TARGET)

$(TARGET): $(SRCS)
		$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
		rm -f $(TARGET) *.o