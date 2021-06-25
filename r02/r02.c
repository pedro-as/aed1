/**
 * r02 - v0.1 - 24/06/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o r02 r02.cpp
 * Windows: gcc -o r02.exe r02.cpp
 * Para executar em terminal (janela de comandos):
 * Linux: ./r02
 * Windows: r02
 */

// dependencias
#include <stdio.h>
#include <stdlib.h>
#include "adhoc.h"
#include "io.h"

// identificacao do programa
const char PROG_ID[4] = "R02";

// definicao global de nomes de arquivos
const char f_dados[10] = "dados.txt";
const char f_result[15] = "resultados.txt";
const char f_perf[14] = "perfeitos.txt";
const char f_num[12] = "numeros.txt";
const char f_frases[11] = "frases.txt";
const char f_cresc[15] = "crescente.txt";
const char f_inv[15] = "invertidos.txt";

// metodos
void method01()
{
    // identificar metodo
    system("clear");
    printf("ED11 - Metodo01\n");

    FILE *fin = fopen(f_dados, "rt");
    FILE *fout = fopen(f_result, "wt");
    int x = 0;
    int div = 0;
    int div_max = 0;
    int div_min = 0;
    int maior = 0;
    int menor = 0;
    
    fscanf(fin, "%d", &x);
    div_min = totalFactors(x);

    if (x <= 0)
    {
        printf("\nERROR: no data\n");
    }
    else
    {
        while (x != 0)
        {
            div = totalFactors(x);

            if (div > div_max)
            {
                div_max = div;
                maior = x;
            }
            if (div < div_min)
            {
                div_min = div;
                menor = x;
            }

            fscanf(fin, "%d", &x);
        }
    }
    fprintf(fout, "Maior: %d\nMenor: %d\n", maior, menor);
    fclose(fin);
    fclose(fout);
}

void method02()
{
    // identificar metodo
    system("clear");
    printf("ED11 - Metodo02\n");

    FILE *fout = fopen(f_perf, "wt");
    int soma = 0;
    int quant = 0;

    fprintf(fout, "Numeros perfeitos [1000:9999]:\n");

    for (int i = 1000; i < 10000; i++)
    {
        soma = sumFactors(i);
        
        if (soma == i)
        {
            fprintf(fout, "%d\n", i);
            quant++;
        }
    }
    fprintf(fout, "**********\nTotal: %d\n", quant);
    fclose(fout);
}

void method03()
{
    // identificar metodo
    system("clear");
    printf("ED11 - Metodo03\n");

    FILE *fin = fopen(f_num, "rt");
    int a = 0;
    int b = 0;
    int gcd = 0;

    fscanf(fin, "%d", &a);
    fscanf(fin, "%d", &b);

    gcd = getGcd_rec(a, b);
    printf("\nMDC(%d, %d): %d\n", a, b, gcd);

    fclose(fin);
    IO_pause("<Enter> para continuar");
}

void method04()
{
    // identificar metodo
    system("clear");
    printf("ED11 - Metodo04\n");
    
    FILE *fin = fopen(f_num, "rt");
    int a = 0;
    int b = 0;
    int lcm = 0;

    fscanf(fin, "%d", &a);
    fscanf(fin, "%d", &b);

    lcm = getLcm(a, b);
    printf("\nMMC(%d, %d): %d\n", a, b, lcm);

    fclose(fin);
    IO_pause("<Enter> para continuar");
}

void method05()
{
    // identificar metodo
    system("clear");
    printf("ED11 - Metodo05\n");

    FILE *fin = fopen(f_frases, "rt");
    int n = 0;
    char prefix[80] = "\0";
    char *string = "\0";

    n = IO_readint("\nEntre com numero de caracteres: ");

    while (!feof(fin))
    {
        string = IO_fread(fin);
        getPrefix(string, n, prefix);
        printf("%s\n", prefix);
        strcpy(prefix, "\0");
    }

    IO_pause("<Enter> para continuar");
}

void method06()
{
    // identificar metodo
    system("clear");
    printf("ED11 - Metodo06\n");

    FILE *fin = fopen(f_frases, "rt");
    int n = 0;
    char suffix[80] = "\0";
    char *string = "\0";

    n = IO_readint("\nEntre com numero de caracteres: ");

    while (!feof(fin))
    {
        string = IO_fread(fin);
        getSuffix(string, n, suffix);
        printf("%s\n", suffix);
        strcpy(suffix, "\0");
    }

    IO_pause("<Enter> para continuar");
}

void method07()
{
    // identificar metodo
    system("clear");
    printf("ED11 - Metodo07\n");

    FILE *fin = fopen(f_frases, "rt");
    int n = 0;
    char last = '\0';
    char *string = "\0";

    n = IO_readint("\nEntre com numero de palavras: ");

    while (!feof(fin) && n > 0)
    {
        string = IO_fread(fin);
        last = getLastchar(string);
        printf("%c\n", last);
        n--;
    }

    IO_pause("<Enter> para continuar");
}

void method08()
{
    // identificar metodo
    system("clear");
    printf("ED11 - Metodo08\n");

    FILE *fin = fopen(f_frases, "rt");
    int n = 0;
    char substr[80] = "\0";
    char *string = "\0";

    n = IO_readint("\nEntre com numero de palavras: ");

    while (!feof(fin) && n > 0)
    {
        string = IO_fread(fin);
        getButlast(string, substr);
        printf("%s\n", substr);
        strcpy(substr, "\0");

        n--;
    }

    IO_pause("<Enter> para continuar");
}

void method09()
{
    // identificar metodo
    system("clear");
    printf("ED11 - Metodo09\n");

    int x = 0;
    int s = 6;
    int dec = 0;
    int array[s];

    for (int i = 0; i < s; i++)
    {
        do
        {
            printf("%d", i);
            x = IO_readint(": ");
        } while (x != 0 && x != 1);
        
        array[i] = x;
    }

    dec = toDec(s, array);
    
    printf("\nDecimal: %d\n", dec);
    IO_pause("<Enter> para continuar");
}

void method10()
{
    // identificar metodo
    system("clear");
    printf("ED11 - Metodo10\n");

    FILE *fin = fopen(f_cresc, "rt");
    FILE *fout = fopen(f_inv, "wt");
    int n = 0;
    int i = 0;
    int x = 0;
    int y = 0;

    n = IO_readint("\nEntre com numero de valores: ");
    int array1[n];
    int array2[n];

    while (!feof(fin) && i < n)
    {
        fscanf(fin, "%d", &x);
        array1[i] = x;
        i++;
    }

    invertArray(n, array1, array2);
    fprintf(fout, "%d\n", n);

    for (int j = 0; j < n; j++)
    {
        y = array2[j];
        fprintf(fout, "%d\n", y);
    }

    fclose(fin);
    fclose(fout);
}

int main(int argc, char **argv)
{
    // definir opcao do menu
    int option = 0;

    // repetir ate receber comando de parada
    do
    {
        // identificar
        system("clear");
        printf("%s - Programa - v0.1\n", PROG_ID);

        // mostrar opcoes
        printf("\nOpcoes:\n");
        printf("0 - Parar\n");
        printf("1 - Metodo 1\n");
        printf("2 - Metodo 2\n");
        printf("3 - Metodo 3\n");
        printf("4 - Metodo 4\n");
        printf("5 - Metodo 5\n");
        printf("6 - Metodo 6\n");
        printf("7 - Metodo 7\n");
        printf("8 - Metodo 8\n");
        printf("9 - Metodo 9\n");
        printf("10 - Metodo 10\n");

        // ler do teclado
        printf("\nEntrar com uma opcao: ");
        scanf("%d", &option);

        // escolher acao
        switch (option)
        {
          case 0:
            system("clear");
            printf("\nPrograma terminado\n");
            break;
          case 1:
            method01();
            break;
          case 2:
            method02();
            break;
          case 3:
            method03();
            break;
          case 4:
            method04();
            break;
          case 5:
            method05();
            break;
          case 6:
            method06();
            break;
          case 7:
            method07();
            break;
          case 8:
            method08();
            break;
          case 9:
            method09();
            break;
          case 10:
            method10();
            break;
          default:
            printf("\nERRO: valor invalido\n");
        }

    } while (option != 0);

    // encerrar
    return (0);
}

/**
 * ----------------------------------- documentacao complementar
 * ----------------------------------- notas / observacoes / comentarios
 * ----------------------------------- previsao de testes
 * ----------------------------------- historico
 * Versao       Data        Modificacao
 * 0.1          24/06       esboco
 * ----------------------------------- testes
 * Versao       Teste 
 * 0.1          01. (OK)    identificacao de programa
 */
