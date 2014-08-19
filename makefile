# project name (generate executable with this name)
TARGET		= LD30

CC		= g++
CFLAGS  	= -Wall

LINKER  	= g++ -o
LFLAGS		= -lsfml-graphics -lsfml-window -lsfml-system

# change these to set the proper directories where each files should be
SRCDIR		= src
OBJDIR		= obj
INCDIR		= includes
BINDIR		= bin

SOURCES		:= $(wildcard $(SRCDIR)/*.cpp)
INCLUDES	:= $(wildcard $(INCDIR)/*.hpp)
OBJECTS		:= $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm		= rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

