/**
 * r01 - v0.1 - 13/05/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o r01 r01.c
 * Windows: gcc -o r01.exe r01.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./r01
 * Windows: r01
 */

// dependencias
#include "io.h" // para definicoes proprias
#include "decorate.h" // procedimentos proprios de decoracao
#include "myMethods.h" // biblioteca de metodos

// definir o numero de identificacao do programa
char PROGRAM_ID[2] = "01";

// para as entradas e saidas

/**
 * method1 - Procedimento para testar se valor e' negativo, zero, positivo, par
 * ou impar
 * @param methodId numero de identificacao do procedimento para decoracao
 */
void method01(int methodId)
{
    // definir dados
    int n = 0;
    int x = 0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    n = IO_readint("\nEntre com quantidade inteira >> ");

    for (int i; i <= n; i++)
    {
        IO_printf("\n\nValor %d ", i);
        x = IO_readint(">> ");

        // testar se negativo, positivo ou zero
        if (x < 0)
        {
            IO_printf("%d e' negativo", x);
        }
        else if (x > 0)
        {
            IO_printf("%d e' positivo", x);
        }
        else
        {
            IO_printf("%d e' zero", x);
        }

        //testar se par ou impar
        if (x % 2 == 0)
        {
            // para os propositos deste exercicio, 0 sera' considerado par
            IO_printf(" e par");
        }
        else
        {
            IO_printf(" e impar");
        }
    }
}

/**
 * method02 - Procedimento para contar valores negativos, positivos, zeros, pares
 * e impares
 * @param methodId numero de identificacao do procedimento para decoracao
 */
void method02(int methodId)
{
    // definir dados
    int n = 0;
    int x = 0;
    int negativos = 0;
    int positivos = 0;
    int zeros = 0;
    int pares = 0;
    int impares = 0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    n = IO_readint("\nEntre com quantidade inteira >> ");

    for (int i; i <= n; i++)
    {
        IO_printf("\n\nValor %d ", i);
        x = IO_readint(">> ");

        // testar se negativo, positivo ou zero
        if (! isPositive(x))
        {
            negativos++;
        }
        else if (isPositive(x))
        {
            positivos++;
        }
        else
        {
            zeros++;
        }

        //testar se par ou impar
        if (isEven(x))
        {
            // para os propositos deste exercicio, 0 sera' considerado par
            pares++;
        }
        else
        {
            impares++;
        }
    }

    // mostrar 
    if ((positivos > negativos) && (positivos > zeros))
    {
        IO_printf("\nPositivos > negativos e zeros");
    }
    else if ((negativos > positivos) && (negativos > zeros))
    {
        IO_printf("\nNegativos > positivos e zeros");
    }
    else if ((zeros > positivos) && (zeros > negativos))
    {
        IO_printf("\nZeros > positivos e negativos");
    }
    else if ((positivos == negativos) && (positivos > zeros))
    {
        IO_printf("\nPositivos e negativos > zeros");
    }
    else if ((positivos == zeros) && (positivos > negativos))
    {
        IO_printf("\nPositivos e zeros > negativos");
    }
    else if ((negativos == zeros) && (negativos > positivos))
    {
        IO_printf("\nNegativos e zeros > positivos");
    }
    else
    {
        IO_printf("\nQuantidade de positivos, negativos e zeros e' igual");
    }
}

/**
 * method03 - Procedimento para identificar operadores logicos, aritmeticos e
 * relacionais
 * @param methodId numero de identificacao do procedimento para decoracao
 */
void method03(int methodId)
{
    // definir dados
    chars cadeia = IO_new_chars(STR_SIZE);
    char simbolo = '\0';
    int tamanho = 0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    cadeia = IO_readstring("\nEntre com cadeia de caracteres >> ");
    tamanho = strlen(cadeia);

    for (int i; i < tamanho; i++)
    {
        simbolo = cadeia[i];

        if (isLogical(simbolo))
        {
            IO_printf("\n%c e' um operador logico", simbolo);
        }
        else if (isArithmetic(simbolo))
        {
            IO_printf("\n%c e' um operador aritmetico", simbolo);
        }
        else if (isRelational(simbolo))
        {
            IO_printf("\n%c e' um operador relacional", simbolo);
        }
        else
        {
            IO_printf("\n%c nao e' um operador", simbolo);
        }
    }
}

/**
 * Funcao principal.
 * @return codigo de encerramento
 */
int main(void)
{
    // identificar
    chars programId = IO_new_chars(STR_SIZE);
    strcpy(programId, IO_concat(IO_concat("=           R", PROGRAM_ID),
                                          " - Programa = v0.1          ="));
    IO_clrscr();
    IO_id(programId);


    // definir dado
    int option = 0; // inicializar variavel para selecionar opcao

    // exibir opcoes
    decorateMenu(11);

    do
    {
        // ler opcao do teclado
        option = IO_readint("\n\nOpcao [1:10] >> ");

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
                break;/*
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
                break;*/
            default:
                IO_clrscr();
                IO_println(IO_concat("\nComando '", IO_concat(IO_toString_d(option),
                                    "' nao encontrado.")));
                break;
        }
    }
    while (option != 0);

    // encerrar
    // IO_pause("\nApertar ENTER para terminar.");
    IO_clrscr(); // limpar tela ao sair
    return (0);
} // fim main( )

/**
 * ---------------------------------------------- documentacao complementar
 * ---------------------------------------------- notas / observacoes / comentarios
 * ---------------------------------------------- previsao de testes
 * method01:
 * 
 *      2 => positivo e par
 *     -3 => negativo e impar
 *      0 => zero e par
 *  99999 => positivo e impar
 * -99998 => negativo e par
 * 
 * method02:
 * 
 * 
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      13/05/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 */
