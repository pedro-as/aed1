/**
 * ed05 - v0.1 - 24/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o ed05 ed05.c
 * Windows: gcc -o ed05.exe ed05.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./ed05
 * Windows: ed05
 */

// dependencias
#include "io.h" // para definicoes proprias
#include "decorate.h" // procedimentos proprios de decoracao
#include "myFunctions.h"

// definir o numero de identificacao do programa
char PROGRAM_ID[2] = "05";

// para as entradas e saidas

/**
 * method01 - Procedimento para testar e contar valores pertencentes e
 * nao pertencentes a um intervalo real
 */
void method01(int methodId)
{
    // definir dados
    int base = 5;
    int quantidade = 0;
    int multiplo = 0;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Mostrar os multiplos de 5 em ordem crescente");

    // ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

    // decorar cabecalho
    IO_printf("\nValor\t:\tMultiplo");
    IO_printf("\n------------------------");

    // mostrar resultados
    for (int i = 1; i <= quantidade; i++)
    {
        multiplo = multipleValue(base, i);
        IO_printf("\n%d\t:\t%d", i, multiplo);
    }
}

/**
 * method02 - Procedimento para contar e mostrar maiusculas menores que 'K'
 */
void method02(int methodId)
{
    // definir dados
    int base = 5;
    int quantidade = 0;
    int multiplo = 0;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Mostrar os multiplos pares de 5 em ordem crescente");

    // ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

    // decorar cabecalho
    IO_printf("\nValor\t:\tMultiplo");
    IO_printf("\n------------------------");

    // mostrar resultados
    for (int i = 1; i <= quantidade; i++)
    {
        multiplo = multipleValue(base, i);

        if (isEven(multiplo))
        {
            IO_printf("\n%d\t:\t%d", i, multiplo);
        }
    }
}

/**
 * method03 - Procedimento para contar maiusculas menores que 'K' por meio
 * de outra funcao
 */
void method03(int methodId)
{
    // definir dados
    int base = 5;
    int quantidade = 0;
    int multiplo = 0;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Mostrar os multiplos impares de 5 em ordem decrescente");

    // ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

    // decorar cabecalho
    IO_printf("\nValor\t:\tMultiplo");
    IO_printf("\n------------------------");

    // mostrar resultados
    for (int i = quantidade; i > 0; i--)
    {
        multiplo = multipleValue(base, i);

        if (! isEven(multiplo))
        {
            IO_printf("\n%d\t:\t%d", i, multiplo);
        }
    }
}

/**
 * method04 - Procedimento para mostrar maiusculas menores que 'K' por meio
 * de outra funcao
 */
void method04(int methodId)
{
    // definir dados
    int base = 5;
    int quantidade = 0;
    int multiplo = 0;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Mostrar os multiplos impares de 5 em ordem decrescente");

    // ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

    // decorar cabecalho
    IO_printf("\nValor\t:\tMultiplo (inv.)");
    IO_printf("\n-------------------------------");

    // mostrar resultados
    for (int i = 1; i <= quantidade; i++)
    {
        multiplo = multipleValue(base, i);
        IO_printf("\n%d\t:\t1/%d", i, multiplo);
    }
}

/**
 * method05 - Procedimento para contar caracteres menores que 'K' ou 'k' por
 * meio de outra funcao
 */
void method05(int methodId)
{
    // definir dados
    double x = 0.0;
    double px = 0.0;
    int quantidade = 0;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Mostrar os multiplos impares de 5 em ordem decrescente");

    // ler quantidade do teclado
    x = IO_readdouble("\nEntre com um valor (x) real >> ");
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

    // decorar cabecalho
    IO_printf("\nn\t:\t x^(-n)");
    IO_printf("\n--------------------------");

    // mostrar resultados
    for (int i = 1; i <= quantidade; i++)
    {
        if (i == 1)
        {
            IO_printf("\n%d\t:\t%lf", i, 1.0);
        }
        else
        {
            px = pow(x, i);
            IO_printf("\n%d\t:\t1/%lf", i, px);
        }
    }
}

/**
 * method06 - Procedimento para mostrar caracteres menores que 'K' ou 'k' por
 * meio de outra funcao
 */
void method06(int methodId)
{
    // definir dados
    int soma = 0;
    int quantidade = 0;
    int valor = 5;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Mostrar os multiplos impares de 5 em ordem decrescente");

    // ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

    // chamar funcao para obter resultado
    soma = conditionalSum(quantidade, valor);

    // mostrar resultado
    IO_printf("\nSoma dos (%d) primeiros valores, ", quantidade);
    IO_printf("\nimpares >= 5 e nao multiplos de 3 => %d\n", soma);
}

/**
 * method07 - Procedimento para mostrar total de digitos impares em uma cadeia
 * de caracteres
 */
void method07(int methodId)
{
    // definir dados
    int quantidade = 0;
    int valor = 5;
    double soma = 0.0;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Mostrar os multiplos impares de 5 em ordem decrescente");

    // ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

     // chamar funcao para obter resultado
    soma = invConditionalSum(quantidade, valor);

    // mostrar resultado
    IO_printf("\nSoma dos inversos dos (%d) primeiros valores ", quantidade);
    IO_printf("\nimpares >= 5 e nao multiplos de 3 => %lf\n", soma);
}

/**
 * method08 - Procedimento para mostrar os simbolos nao alfanumericos em uma
 * cadeia de caracteres
 */
void method08(int methodId)
{
    // definir dados
    int quantidade = 0;
    int soma = 0;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Mostrar os multiplos impares de 5 em ordem decrescente");

    // ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

     // chamar funcao para obter resultado
    soma = sumIntegers(quantidade);

    // mostrar resultado
    IO_printf("\nSoma dos (%d) primeiros numeros naturais => ", quantidade);
    IO_printf("%d\n", soma);
}

/**
 * method09 - Procedimento para mostrar os simbolos alfanumericos em uma
 * cadeia de caracteres
 */
void method09(int methodId)
{
    // definir dados
    double quantidade = 0.0;
    double soma = 0.0;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Mostrar os multiplos impares de 5 em ordem decrescente");

    // ler quantidade do teclado
    quantidade = IO_readdouble("\nEntre com quantidade inteira >> ");

     // chamar funcao para obter resultado
    soma = sumSquares(quantidade);

    // mostrar resultado
    IO_printf("\nSoma dos quadrados dos (%d) ", (int) quantidade);
    IO_printf("primeiros numeros naturais => %.0lf\n", soma);
}

/**
 * method10 - Procedimento para mostrar e contar os simbolos alfanumericos em
 * multiplas cadeias de caractere e calcular o total de todas as palavras
 */
void method10(int methodId)
{
    // definir dados
    double quantidade = 0.0;
    double soma = 0.0;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Mostrar os multiplos impares de 5 em ordem decrescente");

    // ler quantidade do teclado
    quantidade = IO_readdouble("\nEntre com quantidade inteira >> ");

     // chamar funcao para obter resultado
    soma = invSum(quantidade);

    // mostrar resultado
    IO_printf("\nSoma dos inversos dos (%.0lf) ", quantidade);
    IO_printf("primeiros numeros naturais => %lf\n", soma);
}

/**
 * method11 - Procedimento para mostrar e contar os simbolos alfanumericos em
 * multiplas cadeias de caractere e calcular o total de todas as palavras
 */
void method11(int methodId)
{
    // definir dados
    int n = 0;
    long double fatorial = 0.0;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Mostrar os multiplos impares de 5 em ordem decrescente");

    // ler quantidade do teclado
    n = IO_readint("\nEntre com valor inteiro >> ");

     // chamar funcao para obter resultado
    fatorial = factorial(n);

    // mostrar resultado
    IO_printf("\n%d! = %.0Lf\n", n, fatorial);
}

/**
 * method12 - Procedimento para mostrar e contar os simbolos alfanumericos em
 * multiplas cadeias de caractere e calcular o total de todas as palavras
 */
void method12(int methodId)
{
    // definir dados
    int n = 0;
    long double resultado = 0.0;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Mostrar os multiplos impares de 5 em ordem decrescente");

    // ler quantidade do teclado
    n = IO_readint("\nEntre com valor inteiro >> ");

     // chamar funcao para obter resultado
    resultado = superFactorial(n);

    // mostrar resultado
    IO_printf("\n%d! = %Lf\n", n, resultado);
}

/**
 * Funcao principal.
 * @return codigo de encerramento
 */
int main(void)
{
    // identificar
    chars programId = IO_new_chars(STR_SIZE);
    strcpy(programId, IO_concat(IO_concat("=          ED", PROGRAM_ID),
                                          " - Programa = v0.1          ="));
    IO_clrscr();
    IO_id(programId);


    // definir dado
    int option = 0; // inicializar variavel para selecionar opcao

    // exibir opcoes
    decorateMenu(12);

    // ler opcao do teclado
    option = IO_readint("\n>> ");

    // selecionar opcao
    switch (option)
    {
        case 0:
            IO_clrscr();
            IO_println("\nEncerrando programa...");
            break;
        case 1:
            method01(option);
            break;
        case 2:
            method02(option);
            break;
        case 3:
            method03(option);
            break;
        case 4:
            method04(option);
            break;
        case 5:
            method05(option);
            break;
        case 6:
            method06(option);
            break;
        case 7:
            method07(option);
            break;
        case 8:
            method08(option);
            break;
        case 9:
            method09(option);
            break;
        case 10:
            method10(option);
            break;
        case 11:
            method11(option);
            break;
        case 12:
            method12(option);
            break; 
        default:
            IO_clrscr();
            IO_println(IO_concat("\nComando '", IO_concat(IO_toString_d(option),
                                "' nao encontrado. Encerrando...")));
            break;
    }

    // encerrar
    IO_pause("\nApertar ENTER para terminar.");
    IO_clrscr(); // limpar tela ao sair
    return (0);
} // fim main( )

/**
 * ---------------------------------------------- documentacao complementar
 * ---------------------------------------------- notas / observacoes / comentarios
 * ---------------------------------------------- previsao de testes
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      24/04/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     00. (OK)       teste encerrando programa (opcao 0)
 *          01. (OK)       teste method01
 *          02. (OK)       teste method02
 *          03. (OK)       teste method03
 *          04. (OK)       teste method04
 *          05. (OK)       teste method05
 *          06. (OK)       teste method06
 *          07. (OK)       teste method07
 *          08. (OK)       teste method08
 *          09. (OK)       teste method09
 *          10. (OK)       teste method10
 *          11. (OK)       teste comando invalido
 */
