# Nirtcpp Engine Regression Tests Makefile
Target = tests
Sources = $(wildcard *.cpp)

CPPFLAGS = -I../include -I../include/nirtcpp -I/usr/X11R6/include -pipe
CXXFLAGS += -Wall -ansi -pedantic -fno-exceptions
CXXFLAGS += -std=c++20 # Be compatible with c++17, c++20, c++23. Default to c++20
ifndef NDEBUG
CXXFLAGS += -O0 -g -D_DEBUG 
else
CXXFLAGS += -fexpensive-optimizations -O3
endif

ifeq ($(HOSTTYPE), x86_64)
LIBSELECT=64
endif

all: all_linux

# target specific settings
all_linux: SYSTEM=Linux
all_linux: LDFLAGS = -L/usr/X11R6/lib$(LIBSELECT) -L../lib/$(SYSTEM) -lnirtcpp -lGL -lXxf86vm -lX11

all_win32 clean_win32: SYSTEM=Win32-gcc
all_win32: LDFLAGS = -L../lib/$(SYSTEM) -lnirtcpp -lopengl32 -lm

all_win32 clean_win32: SUF=.exe
# name of the binary - only valid for targets which set SYSTEM
DESTPATH = ../bin/$(SYSTEM)/$(Target)$(SUF)

OBJ = $(Sources:.cpp=.o)

all_linux all_win32: $(OBJ)
	$(warning Building...)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $(DESTPATH) $(LDFLAGS)
	@$(RM) tests	# otherwise it's easy to forget to copy it and run the old binary

clean: clean_linux clean_win32
	$(warning Cleaning...)
	@$(RM) $(OBJ)

clean_linux clean_win32:
	@$(RM) $(DESTPATH)

.PHONY: all all_win32 clean clean_linux clean_win32

# Create dependency files for automatic recompilation
%.d:%.cpp
	$(CXX) $(CPPFLAGS) -MM -MF $@ $<

ifneq ($(MAKECMDGOALS),clean)
-include $(OBJ:.o=.d)
endif

