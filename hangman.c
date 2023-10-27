#include <stdio.h>
#include <string.h>

void abertura()
{
    printf("************************************\n");
    printf("*          JOGO DA FORCA           *\n");
    printf("************************************\n\n");
}

void chuta(char chutes[26], int *tent)
{
    char chute;
    scanf(" %c", &chute);

    chutes[(*tent)] = chute;
    (*tent)++;
}

int jachutou(char letra, char chutes[26], int tentativas)
{

    int achou = 0;

    for (int j = 0; j < tentativas; j++)
    {

        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}

int main()
{

    char palavrasecreta[20];
    sprintf(palavrasecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura();

    do
    {
        // imprime a palavra secreta
        for (int i = 0; i < strlen(palavrasecreta); i++)
        {

            // a letra ja foi chutada?
            int achou = jachutou(palavrasecreta[i], chutes, tentativas);

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

        // captura um novo chute
        chuta(chutes, &tentativas);

    } while (!acertou && !enforcou);
}
