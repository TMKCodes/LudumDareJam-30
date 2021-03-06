# project name (generate executable with this name)
TARGET		= LD30

CC		= g++
CFLAGS  	= -g -Wall -I. -fpermissive

LINKER  	= g++ -o
LFLAGS		= -Wall -I. -lsfml-graphics -lsfml-window -lsfml-system

# change these to set the proper directories where each files should be
SRCDIR		= src
OBJDIR		= obj
BINDIR		= bin

SOURCES		:= $(wildcard $(SRCDIR)/*.cpp)
INCLUDES	:= $(wildcard $(SRCDIR)/*.hpp)
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

.PHONEY: install
install: uninstall
	@cp $(BINDIR)/$(TARGET) /usr/bin/$(TARGET)
	@mkdir /usr/share/$(TARGET)
	@cp -r $(BINDIR)/* /usr/share/$(TARGET)/

.PHONEY: uninstall
uninstall:
	@rm -f /usr/bin/$(TARGET)
	@rm -rf /usr/share/$(TARGET)

