# Hangman_with_C

Jogo da forca (Hangman) em C — projeto feito durante o curso.  
Este repositório contém o código fonte em C para o jogo, instruções de compilação e sugestões de melhorias.

## Como compilar

Use o `Makefile` incluído (compila todos os `.c` recursivamente e coloca os binários em `bin/`):

```bash
# compila todos
make

# compila em modo debug
make debug

# lista fontes e binários gerados
make list

# executa (exemplo)
make run NAME=path/to/program_without_.c
