MAKEFLAGS += --warn-undefined-variables

CXX = clang++

CXXFLAGS = -Wall -Wextra -std=c++20 -pedantic
CXXFLAGS += -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare \
			-Wno-unused-parameter -Wno-unused-variable \
			-Wno-unused-but-set-variable -Wshadow

ifeq ($(CXX), clang++)
CXXFLAGS  += -ferror-limit=1
endif

CXXFLAGS += -O0
OS := $(shell uname)
ifeq ($(OS), Linux)
CXXFLAGS += -gdwarf-4 -ggdb3
LDLIBS = -lm
else ifeq ($(OS), Darwin)
CXXFLAGS += -g
LDLIBS = -lm
else ifeq ($(OS), Windows_NT)
CXXFLAGS += -g
else
# Settings for other systems
CXXFLAGS += -g
endif


BUILDDIR = build
