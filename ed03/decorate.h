#include <stdio.h>

void decorateMethod(const char* programId, char* methodId)
{
    system("clear");
    printf("******************\n");
    printf("** Exemplo %s%s **\n", programId, methodId);
    printf("******************\n");
}

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
    if (extras > 0)
    {
        for (int i = 1; i <= extras; i++)
        {
            extraOption = tasks + i;
            printf("[%d] Exemplo %sE%d\n", extraOption, programId, i);
        }
    }
}
