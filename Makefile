# Declaration of variables
CC = g++
CC_FLAGS = -w
 
# File names
EXEC = bin/test
SOURCES = $(wildcard src/*.cc)
OBJECTS = $(SOURCES:.cc=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
