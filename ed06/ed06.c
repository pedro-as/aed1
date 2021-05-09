/**
 * ed06 - v0.1 - 09/05/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o ed06 ed06.c
 * Windows: gcc -o ed06.exe ed06.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./ed06
 * Windows: ed06
 */

// dependencias
#include "io.h" // para definicoes proprias
#include "decorate.h" // procedimentos proprios de decoracao
#include "myMethods.h"

// definir o numero de identificacao do programa
char PROGRAM_ID[2] = "06";

// para as entradas e saidas

void method01(int methodId)
{
    // definir dados
    int quantidade = 0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

    showOdd(quantidade);
}

void method02(int methodId)
{
    // definir dados
    int quantidade = 0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

    showMultiples_5(quantidade);
}

void method03(int methodId)
{
    // definir dados
    int quantidade = 0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

    showSequence_a(quantidade);
}

void method04(int methodId)
{
    // definir dados
    int quantidade = 0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

    showSequence_b(quantidade);
}

void method05(int methodId)
{
    // definir dados
    chars cadeia = IO_new_chars(STR_SIZE);
    int tamanho = 0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler cadeia de caracteres do teclado
    cadeia = IO_readstring("\nEntre com cadeia de caracteres >> ");
    tamanho = strlen(cadeia);

    showSymbols(cadeia, tamanho);
}

void method06(int methodId)
{
    // definir dados
    int quantidade = 0;
    int soma = 0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

    soma = sumOdd(quantidade);
    IO_printf("\nSoma dos %d primeiros valores impares, ", quantidade);
    IO_printf("comecando em 5 = %d\n", soma);
}

void method07(int methodId)
{
    // definir dados
    int quantidade = 0;
    double soma = 0.0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira >> ");

    soma = sumOddInv(quantidade);
    IO_printf("\nSoma dos inversos (1/x) dos %d primeiros ", quantidade);
    IO_printf("valores impares, comecando em 5 = %lf\n", soma);
}

void method08(int methodId)
{
    // definir dados
    int indice = 0;
    int indice_t = 0;
    int termo = 0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    indice = IO_readint("\nEntre com indice inteiro >> ");
    
    // todo indice multiplo de 3 da sequencia, quando esta comeca em 1, e' par
    indice_t = indice * 3;

    termo = fibonacci(indice_t);
    IO_printf("\n%d.o termo par da serie de Fibonnaci = %d\n", indice, termo);
}

void method09(int methodId)
{
    // definir dados
    chars cadeia = IO_new_chars(STR_SIZE);
    int n = 0;
    int total = 0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    cadeia = IO_readstring("\nEntre com cadeia de caracteres >> ");

    total = countOddDigits(cadeia, n);
    IO_printf("\nTotal de digitos impares = %d\n", total);
}

void method10(int methodId)
{
    // definir dados
    chars cadeia = IO_new_chars(STR_SIZE);
    int n = 0;
    int total = 0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    cadeia = IO_readstring("\nEntre com cadeia de caracteres >> ");

    total = countUppercase(cadeia, n);
    IO_printf("\nTotal de maiusculas = %d\n", total);
}

void method11(int methodId)
{
    // definir dados
    double x = 0;
    double n = 0;
    double soma = 0.0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    x = IO_readdouble("\nEntre com valor real (x) >> ");
    n = IO_readdouble("\nEntre com valor real (n) >> ");

    soma = oddSummation(x, n);
    IO_printf("\nf(x, n) = 1 + x**1 + x**3 + x**5 + x**7 + ...");
    IO_printf("\nResultado para x = %lf e n = %lf >> %lf\n", x, n, soma);
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
    decorateMenu(11);

    do
    {
        // ler opcao do teclado
        option = IO_readint("\n\nOpcao [1:11] >> ");

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
            default:
                IO_clrscr();
                IO_println(IO_concat("\nComando '", IO_concat(IO_toString_d(option),
                                    "' nao encontrado.")));
                break;
        }
    }
    while (option != 0);

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
 *  0.1      09/05/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 */
