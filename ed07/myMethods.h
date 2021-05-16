#include <math.h>

void writeEvenM3(chars fileName, int n)
{
    FILE* arquivo = fopen(fileName, "wt");
    int x = 0;

    for (int i = 1; i <= n; i++)
    {
        x = 3 * 2 * i;
        fprintf(arquivo, "%d\n", x);
    }

    fclose(arquivo);
}

void writeOddM3(chars fileName, int n)
{
    FILE* arquivo = fopen(fileName, "wt");
    int x = 0;

    while (n > 0)
    {
        x = 3 * (2 * n - 1);
        fprintf(arquivo, "%d\n", x);
        n--;
    }

    fclose(arquivo);
}

void writeExp(chars fileName, int b, int n)
{
    FILE* arquivo = fopen(fileName, "wt");
    double y = 0.0;

    for (int x = 0; x < n; x++)
    {
        y = pow(5.0, (double) x);
        fprintf(arquivo, "%.0lf\n", y);
    }

    fclose(arquivo);
}

void writeNegExp(chars fileName, int b, int n)
{
    FILE* arquivo = fopen(fileName, "wt");
    double y = 0.0;
    n = n * (-1);

    while (n < 0)
    {
        n++;
        y = pow((double) b, (double) n);
        fprintf(arquivo, "%.12lf\n", y);
    }

    fclose(arquivo);
}

void writeNegEvenExp(chars fileName, double b, int n)
{
    FILE* arquivo = fopen(fileName, "wt");
    double y = 0.0;
    n = n * (-1);

    for (int i = 0; i > -2; i--)
    {
        y = pow((double) b, (double) i);
        fprintf(arquivo, "%.12lf\n", y);
    }

    for (int i = -2; i > n; i--)
    {
        y = pow((double) b, (double) i);
        fprintf(arquivo, "%.12lf\n", y);        
    }

    fclose(arquivo);
}


void copyText(chars fileOut, chars fileIn)
{
    FILE* saida = fopen(fileOut, "wt");
    FILE* entrada = fopen(fileIn, "rt");
    chars linha = IO_new_chars(STR_SIZE);
    int contador = 0;

    strcpy(linha,IO_freadln(entrada));
    
    while(! feof(entrada))
    {
        contador++;
        
        if (strcmp("PARAR", linha) != 0)
        {
            IO_fprintln(saida, linha);
        }

        strcpy(linha, IO_freadln(entrada));
    }
    IO_printf("Lines read = %d\n", contador);
    fclose(saida);
    fclose(entrada);
}
