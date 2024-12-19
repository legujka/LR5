PLATFORM ?= linux

ifeq ($(PLATFORM), windows)
    CXX = x86_64-w64-mingw32-g++
    EXT = .exe
else
    CXX = g++
    EXT =
endif

CXXFLAGS = -Wall -Wextra -std=c++17

SRCS := $(wildcard lr*/*.cpp)

EXES := $(SRCS:.cpp=$(EXT))

all: $(EXES)

%$(EXT): %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(EXES)

