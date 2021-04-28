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
char* PROGRAM_ID = "05";

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
    chars string = IO_new_chars(STR_SIZE);
    chars validas = IO_new_chars(STR_SIZE);
    char controle = 'K';

    strcpy(string, STR_EMPTY);
    strcpy(validas, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: mostrar maiusculas menores que 'K'");

    // ler do teclado
    string = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    validas = showUpperToChar(string, controle);
    IO_printf("Maiusculas menores que 'K': %s\n", validas);
}

/**
 * method05 - Procedimento para contar caracteres menores que 'K' ou 'k' por
 * meio de outra funcao
 */
void method05(int methodId)
{
   // definir dados
    chars string = IO_new_chars(STR_SIZE);
    char controle = 'K';
    int total = 0;

    strcpy(string, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: contar caracteres menores que 'K' ou 'k'");

    // ler do teclado
    string = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    total = countToChar(string, controle);
    IO_printf("Total de caracteres menores que 'K' ou 'k': %d\n", total);
}

/**
 * method06 - Procedimento para mostrar caracteres menores que 'K' ou 'k' por
 * meio de outra funcao
 */
void method06(int methodId)
{
    // definir dados
    chars string = IO_new_chars(STR_SIZE);
    chars validas = IO_new_chars(STR_SIZE);
    char controle = 'K';

    strcpy(string, STR_EMPTY);
    strcpy(validas, STR_EMPTY);
    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: mostrar maiusculas menores que 'K' ou 'k'");

    // ler do teclado
    string = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    validas = showToChar(string, controle);
    IO_printf("Caracteres menores que 'K' ou 'k': %s\n", validas);
}

/**
 * method07 - Procedimento para mostrar total de digitos impares em uma cadeia
 * de caracteres
 */
void method07(int methodId)
{
    // definir dados
    chars string = IO_new_chars(STR_SIZE);
    int total = 0;

    strcpy(string, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: contar digitos impares na cadeia de caracteres");

    // ler do teclado
    string = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    total = countOddDigits(string);
    IO_printf("Total de digitos impares: %d\n", total);
}

/**
 * method08 - Procedimento para mostrar os simbolos nao alfanumericos em uma
 * cadeia de caracteres
 */
void method08(int methodId)
{
    // definir dados
    chars string = IO_new_chars(STR_SIZE);
    chars validas = IO_new_chars(STR_SIZE);

    strcpy(string, STR_EMPTY);
    strcpy(validas, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: mostrar simbolos nao alfanumericos na cadeia de caracteres");

    // ler do teclado
    string = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    validas = showNonAlnum(string);
    IO_printf("Simbolos nao alfanumericos: %s\n", validas);
}

/**
 * method09 - Procedimento para mostrar os simbolos alfanumericos em uma
 * cadeia de caracteres
 */
void method09(int methodId)
{
    // definir dados
    chars string = IO_new_chars(STR_SIZE);
    chars validas = IO_new_chars(STR_SIZE);

    strcpy(string, STR_EMPTY);
    strcpy(validas, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: mostrar simbolos alfanumericos na cadeia de caracteres");

    // ler do teclado
    string = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    validas = showAlnum(string);
    IO_printf("Simbolos alfanumericos: %s\n", validas);
}

/**
 * method10 - Procedimento para mostrar e contar os simbolos alfanumericos em
 * multiplas cadeias de caractere e calcular o total de todas as palavras
 */
void method10(int methodId)
{
    // definir dados
    int reps = 0;
    int subtotal = 0;
    int total = 0;
    chars string = IO_new_chars(STR_SIZE);
    chars simbolos = IO_new_chars(STR_SIZE);
    chars preConcat = IO_new_chars(STR_SIZE);
    chars resultado = IO_new_chars(STR_SIZE);

    strcpy(string, STR_EMPTY);
    strcpy(simbolos, STR_EMPTY);
    strcpy(preConcat, STR_EMPTY);
    strcpy(resultado, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste multiplo: mostrar e contar simbolos alfanumericos");

    // ler do teclado
    reps = IO_readint("\nEntrar com o numero de repeticoes >> ");

    for (int i = 0; i < reps; i++)
    {
        string = IO_readstring("Entrar com uma cadeia de caracteres >> ");
        simbolos = showAlnum(string);
        subtotal = countAlnum(string);
        total = total + subtotal;
        preConcat = concatResult(string, simbolos, subtotal);
        strncat(resultado, preConcat, STR_SIZE);
    }
    IO_println("");
    IO_println(resultado);
    IO_printf("Total de simbolos alfanum. encontrados no teste: %d\n", total);
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
    decorateMenu(10);

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
