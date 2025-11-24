# Makefile - Hangman_with_C
CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic -std=c11
DBGFLAGS := -g -O0
RELEASEFLAGS := -O2

SRC_DIR := src
SRC := $(SRC_DIR)/hangman.c
BIN_DIR := bin
BIN := $(BIN_DIR)/hangman

.PHONY: all debug release run clean

all: dirs $(BIN)

debug: CFLAGS += $(DBGFLAGS)
debug: all

release: CFLAGS += $(RELEASEFLAGS)
release: all

dirs:
	@mkdir -p $(BIN_DIR)

$(BIN): $(SRC)
	@echo "Compilando $< -> $@"
	$(CC) $(CFLAGS) $< -o $@

run: $(BIN)
	@echo "Executando $(BIN)"
	$(BIN)

clean:
	@echo "Removendo binários..."
	@rm -rf $(BIN_DIR)
