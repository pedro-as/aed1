#include <stdio.h>

/**
 * decorateMethod - Procedimento para gerar e decorar os metodos e 
 * procedimentos utilizados em guias e estudos dirigidos.
 * @param programId Identificacao do programa
 * @param methodId Identificacao do metodo ou procedimento
 */
void decorateMethod(const char* programId, char* methodId)
{
    system("clear");
    printf("******************\n");
    printf("** Exemplo %s%s **\n", programId, methodId);
    printf("******************\n");
}

/**
 * decorateMenu - Procedimento para gerar e decorar o menu de opcoes 
 * em guias e estudos dirigidos.
 * @param tasks Numero de exercicios presentes
 * @param extras Numero de tarefas extras presentes
 * @param programId Identificacao do programa
 */
void decorateMenu(int tasks, int extras, const char* programId)
{
    int methodId;
    int extraOption;

    printf("\nEscolha uma das acoes a seguir para executar:\n\n");
    printf("[0] Encerrar programa\n");

    for (int i = 1; i <= tasks; i++)
    {
        methodId = 10 + i;
        printf("[%d] Exemplo %s%d\n", i, programId, methodId);
    }
    if (extras)
    {
        for (int i = 1; i <= extras; i++)
        {
            extraOption = tasks + i;
            printf("[%d] Exemplo %sE%d\n", extraOption, programId, i);
        }
    }
}
