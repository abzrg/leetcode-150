MAKEFLAGS += --warn-undefined-variables

CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++20 -pedantic
CXXFLAGS += -gdwarf-4 -ggdb3 -O0
CXXFLAGS += -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare \
			-Wno-unused-parameter -Wno-unused-variable \
			-Wno-unused-but-set-variable -Wshadow
ifeq ($(CXX), clang++)
CXXFLAGS  += -ferror-limit=1
endif

LDLIBS = -lm

BUILDDIR = build
