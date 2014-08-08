# Originaly written by Yanick Rochon <yanick.rochon@gmail.com>, modified for C++
# static library by Nikolaos Dymitriadis <nikolaos@students.mimuw.edu.pl>.
# Original source at http://stackoverflow.com/questions/7004702 .

TARGETNAME   = croissant
TARGET       = $(BINDIR)/$(TARGETNAME).a

CC	     = g++
CFLAGS   = -std=c++11 -Wall -I.

AR       = ar
ARFLAGS  = rvs

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
RM	   = rm -f

.PHONEY: all
all : $(TARGET)
	
$(TARGET): $(OBJECTS)
	@$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS)
	@echo "Library successfuly created!"

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	@$(RM) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(RM) $(TARGET)
	@echo "Executable removed!"
