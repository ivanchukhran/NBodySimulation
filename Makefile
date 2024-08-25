CC = gcc
CFLAGS = -Wall -Wextra -O2 -I./include
LDFLAGS = -lm

# Default implementation
IMPL ?= naive

SRC_DIR = src
OBJ_DIR = obj
IMPL_DIR = implementations

# Common source files
COMMON_SOURCES = $(wildcard $(SRC_DIR)/*.c)
COMMON_OBJECTS = $(COMMON_SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Implementation-specific source file
IMPL_SOURCE = $(SRC_DIR)/$(IMPL_DIR)/$(IMPL).c
IMPL_OBJECT = $(OBJ_DIR)/$(IMPL_DIR)/$(IMPL).o

# All objects
OBJECTS = $(COMMON_OBJECTS) $(IMPL_OBJECT)

TARGET = nbody_simulation

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/$(IMPL_DIR)/%.o: $(SRC_DIR)/$(IMPL_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@
	mkdir -p $@/$(IMPL_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Targets for different implementations
.PHONY: naive barneshut cuda

naive:
	$(MAKE) IMPL=naive

barneshut:
	$(MAKE) IMPL=barnesHut

cuda:
	$(MAKE) IMPL=cuda
