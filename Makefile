CC = clang++
SDL2_DIR = /usr/local/opt/sdl2
COMPILER_FLAGS = -Wall
INCLUDE_FLAGS = -I$(SDL2_DIR)/include
LINKER_FLAGS = -lSDL2

01: 01.cpp
	$(CC) $< $(COMPILER_FLAGS) $(INCLUDE_FLAGS) $(LINKER_FLAGS) -o $@

02: 02.cpp
	$(CC) $< $(COMPILER_FLAGS) $(INCLUDE_FLAGS) $(LINKER_FLAGS) -o $@

03: 03.cpp
	$(CC) $< $(COMPILER_FLAGS) $(INCLUDE_FLAGS) $(LINKER_FLAGS) -o $@
