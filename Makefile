# Originaly written by Yanick Rochon <yanick.rochon@gmail.com>, modified for C++
# static library by Nikolaos Dymitriadis <nikolaos@students.mimuw.edu.pl>.
# Original source at http://stackoverflow.com/questions/7004702 .

# project info
TARGETNAME   = croissant
TARGET       = $(BINDIR)/$(TARGETNAME).a

TESTLIB      = boost_unit_test_framework

# programs
CC	     = g++
CFLAGS   = -std=c++11 -Wall -I.

AR       = ar
ARFLAGS  = rvs

RM	   = rm -f

# directories
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
TESTDIR  = tests
TESTBINDIR = test-bin

# files
SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
TESTS    := $(wildcard $(TESTDIR)/*.cpp)
TESTBINS := $(patsubst $(TESTDIR)/%.cpp, $(TESTBINDIR)/%, $(TESTS))

# targets
$(TARGET): $(OBJECTS)
	@$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS)
	@echo "Library successfuly created!"

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$@" successfully!"

$(TESTBINDIR)/%-test : $(TESTDIR)/%-test.cpp $(SRCDIR)/%.h $(TARGET)
	@$(CC) $(CFLAGS) $^ -l$(TESTLIB) -o $@
	@echo "Compiled "$@" successfully!"

# phonies
.PHONEY: all
all : $(TARGET)

.PHONEY: tests
tests : $(TARGET) $(TESTBINS)
	
.PHONEY: clean
clean:
	@$(RM) $(OBJECTS) $(TESTBINS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(RM) $(TARGET)
	@echo "Executable removed!"
