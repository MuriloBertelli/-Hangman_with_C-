#include <stdio.h>
#include <string.h>
#include <time.h>
#include "hangman.h"
#include <stdlib.h>
#define TAMANHO_PALAVRA 20;

// variaveis globais
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutes_dados = 0;

void abertura()
{
    printf("************************************\n");
    printf("*          JOGO DA FORCA           *\n");
    printf("************************************\n\n");
}

void chuta()
{
    char chute;
    scanf(" %c", &chute);

    chutes[(chutes_dados)] = chute;
    chutes_dados++;
}

int jachutou(char letra)
{

    int achou = 0;

    for (int j = 0; j < chutes_dados; j++)
    {

        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca()

{
    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      (_)    \n");
    printf(" |      \\|/   \n");
    printf(" |       |     \n");
    printf(" |      / \\   \n");
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

    for (int i = 0; i < strlen(palavrasecreta); i++)
    {

        int achou = jachutou(palavrasecreta[i]);

        if (achou)
        {
            printf("%c ", palavrasecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void adicionapalavra()
{

    char quer;
    printf("Voce seja adicionar um nova palavra no jogo ? (S/N)");
    if (quer == "S")
    {

        char novapalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", novapalavra);

        FILE *f;

        f = fopen("palavras.txt", "r+");
        if (f == 0)
        {
            printf("Desculpe, banco de dados não disponivel\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);
        fclose(f);
    }
}

void escolheparalavra()
{
    FILE *f;
    f = fopen("palavras.txt", "r");

    if (f == 0)
    {
        printf("Desculpe, banco de dados não disponivel\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for (int i = 0; i <= randomico; i++)
    {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int acertou()
{
    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i]))
        {
            return 0;
        }
    }
    return 1;
}

int enforcou()
{

    int erros = 0;
    for (int i = 0; i < chutes_dados; i++)
    {
        int existe = 0;

        for (int j = 0; j < strlen(palavrasecreta); j++)
        {
            if (chutes[i] == palavrasecreta[j])
            {
                existe = 1;
                break;
            }
        }
        if (!existe)
            erros++;
    }
    return erros >= 5;
}

int main()
{

    escolheparalavra();
    abertura();

    do
    {

        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());

    if (acertou())
    {
        printf("Parabens, voce nao e um perdedor");
    }
    else
    {
        printf("Voce perdeu");
    }

    adicionapalavra();
}
