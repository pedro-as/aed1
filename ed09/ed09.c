/**
 * ed09 - v0.1 - 27/05/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o ed09 ed09.c
 * Windows: gcc -o ed09.exe ed09.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./ed09
 * Windows: ed09
 */

// dependencias
#include "io.h" // para definicoes proprias
#include "decorate.h" // procedimentos proprios de decoracao
#include "matrixlib.h" // biblioteca de metodos para matrizes

// definir o numero de identificacao do programa
char PROGRAM_ID[4] = "ED09";

// para as entradas e saidas

void method01(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados
    int rows = 0;
    int cols = 0;
    int value = 0;
    chars text = IO_new_chars(STR_SIZE);

    // ler dimensoes do teclado
    // verificando se sao nulas ou negativas
    while (rows <= 0)
    {
        rows = IO_readint("\nLinhas: ");
    }

    while (cols <= 0)
    {
        cols = IO_readint("Colunas: ");
    }

    // declarar matriz com dimensoes informadas
    int matrix[rows][cols];
    IO_printf("\n");

    // ler valores do teclado
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // verificar se valor e' positivo
            while (value <= 0)
            {
                strcpy(text, STR_EMPTY);
                value = IO_readint(IO_concat(
                            IO_concat(IO_concat(text, IO_toString_d(i)), ","),
                            IO_concat(IO_concat(text, IO_toString_d(j)), ": ")));
            }

            // guardar valor e reinicia-lo
            matrix[i][j] = value;
            value = 0;
        }
    }

    // mostrar matriz
    IO_printf("\n\n");
    printIntMatrix(rows, cols, matrix);

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method02(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method03(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method04(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method05(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method06(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method07(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method08(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method09(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method10(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method11(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method12(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

/**
 * Funcao principal. 
 * @return codigo de encerramento
 */
int main(void)
{
    // identificar
    chars programId = IO_new_chars(STR_SIZE);
    strcpy(programId, IO_concat(IO_concat("=          ", PROGRAM_ID),
                                          " - Programa = v0.1          ="));

    // inicializar variavel para selecionar opcao
    int option = 0;

    do
    {
        IO_clrscr();
        IO_id(programId);
        // exibir opcoes
        decorateMenu(12);
        IO_println("\n");

        // ler opcao do teclado
        option = IO_readint("Opcao [1:12] >> ");

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
 *  0.1      dd/MM/21        esboco
 * ---------------------------------------------- testes
 */
