#include <stdio.h>

/**
 * decorateMethod - Procedimento para gerar e decorar os metodos e 
 * procedimentos utilizados em guias e estudos dirigidos.
 * @param methodId Identificacao do metodo ou procedimento
 */
void decorateMethod(int methodId)
{
    system("clear");
    printf("******************\n");
    if (methodId < 10)
    {
        printf("**   Metodo 0%d  **\n", methodId);
    }
    else
    {
        printf("**   Metodo %d  **\n", methodId);
    }
    printf("******************\n");
}

/**
 * decorateMenu - Procedimento para gerar e decorar o menu de opcoes 
 * em guias e estudos dirigidos.
 * @param tasks Numero de exercicios presentes
 */
void decorateMenu(int tasks)
{
    printf("\nEscolha uma das acoes a seguir para executar:\n\n");
    printf("[ 0] Encerrar programa\n");

    for (int i = 1; i <= tasks; i++)
    {
        if (i < 10)
        {
            printf("[ %d] Metodo 0%d\n", i, i);
        }
        else
        {
            printf("[%d] Metodo %d\n", i, i);
        }
    }
}
