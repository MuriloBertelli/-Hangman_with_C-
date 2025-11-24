# Makefile para Hangman_with_C
CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic -std=c11
DBGFLAGS := -g -O0
RELEASEFLAGS := -O2

SRC := $(shell find . -type f -name "*.c" -not -path "./bin/*")
BIN_DIR := bin
.PHONY: all debug release run clean list

all: dirs $(patsubst ./%.c,$(BIN_DIR)/%,$(SRC))

debug: CFLAGS += $(DBGFLAGS)
debug: all

release: CFLAGS += $(RELEASEFLAGS)
release: all

dirs:
	@mkdir -p $(BIN_DIR)

# compila ./path/name.c -> bin/path/name  (mantém estrutura relativa)
$(BIN_DIR)/%: ./% 
	@echo "Compilando $< -> $@"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@ || (echo "Falha ao compilar $<"; false)

list:
	@echo "Fontes:"
	@printf "%s\n" $(SRC)
	@echo; echo "Executáveis gerados em $(BIN_DIR)/"
	@find $(BIN_DIR) -maxdepth 2 -type f -executable -printf " - %p\n" || true

# Run por arquivo: ex: make run NAME=src/hangman
run:
ifndef NAME
	$(error NAME não definido. Ex: make run NAME=src/hangman)
endif
	@exe="$(BIN_DIR)/$(NAME)"; \
	if [ -x "$$exe" ]; then echo "Executando $$exe"; $$exe; else echo "$$exe não encontrado. Rode make ou make all"; exit 1; fi

test: all
	@echo "Teste: compilação concluída. Rode 'make run NAME=<caminho-sem-.c>' para executar."

clean:
	@echo "Removendo binários..."
	@rm -rf $(BIN_DIR)
