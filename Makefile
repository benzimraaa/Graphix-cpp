CXX = g++
CXXFLAGS = -std=c++11
LDFLAGS = -lSDL2

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

TARGET = myGame

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
