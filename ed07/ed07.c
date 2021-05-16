/**
 * ed07 - v0.1 - 13/05/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o ed07 ed07.c
 * Windows: gcc -o ed07.exe ed07.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./ed07
 * Windows: ed07
 */

// dependencias
#include "io.h" // para definicoes proprias
#include "decorate.h" // procedimentos proprios de decoracao
#include "myMethods.h" // biblioteca de metodos

// definir o numero de identificacao do programa
char PROGRAM_ID[2] = "07";

// para as entradas e saidas

void method01(int methodId)
{
    int quant = 0;

    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Multiplos pares de 3, em ordem crescente\n");
    
    // ler quantidade do teclado
    quant = IO_readint("\nEntre com quantidade inteira >> ");

    // executar metodo e gravar em arquivo
    writeEvenM3("DADOS01.TXT", quant);
}

void method02(int methodId)
{
    int quant = 0;

    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Multiplos impares de 3, em ordem decrescente\n");
    
    // ler quantidade do teclado
    quant = IO_readint("\nEntre com quantidade inteira >> ");

    // executar metodo e gravar em arquivo
    writeOddM3("DADOS02.TXT", quant);
}

void method03(int methodId)
{
    int base = 5;
    int quant = 0;

    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Funcao exponencial f(x) = 5^(x) para x inteiro >= 0\n");
    
    // ler quantidade do teclado
    quant = IO_readint("\nEntre com quantidade inteira >> ");

    // executar metodo e gravar em arquivo
    writeExp("DADOS03.TXT", base, quant);
}

void method04(int methodId)
{
    int base = 4;
    int quant = 0;

    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Funcao exponencial f(x) = 4^(x) para x inteiro < 0\n");
    
    // ler quantidade do teclado
    quant = IO_readint("\nEntre com quantidade inteira >> ");

    // executar metodo e gravar em arquivo
    writeNegExp("DADOS04.TXT", base, quant);
}

void method05(int methodId)
{
    int quant = 0;
    double base = 0.0;

    // decorar o metodo
    decorateMethod(methodId);
    IO_printf("Funcao exponencial f(x) = 1/(b^x) para x inteiro no intervalo ");
    IO_println("[0,1] U [inteiros pares)\n");
    
    // ler quantidade do teclado
    quant = IO_readint("\nEntre com quantidade inteira >> ");
    base = IO_readdouble("\nEntre com quantidade real >> ");

    // executar metodo e gravar em arquivo
    writeNegEvenExp("DADOS05.TXT", base, quant);
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
    //decorateMenu(10);
    //IO_println("\n");

    do
    {
        IO_clrscr();
        // exibir opcoes
        decorateMenu(10);
        IO_println("\n");

        // ler opcao do teclado
        option = IO_readint("Opcao [1:10] >> ");

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
                break;/*
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
                break;*/
            default:
                IO_printf("Opcao nao reconhecida: '%d'\n", option);
                break;
        }
    }
    while (option != 0);

    // encerrar
    IO_clrscr();
    return (0);
} // fim main( )

/**
 * ---------------------------------------------- documentacao complementar
 * ---------------------------------------------- notas / observacoes / comentarios
 * ---------------------------------------------- previsao de testes
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      13/05/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 */
