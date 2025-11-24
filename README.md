# Hangman_with_C

Jogo da Forca (Hangman) em C — versão refatorada, segura e modular.

## O que está aqui
- `src/hangman.c`  -> implementação do jogo (usa `words.txt`)
- `words.txt`      -> lista de palavras (uma por linha)
- `Makefile`       -> compila o projeto e gera `bin/hangman`
- `.gitignore`     -> para ignorar binários e arquivos temporários

## Como compilar e executar

```bash
# compilar
make

# executar
make run

# compilar em modo debug
make debug
