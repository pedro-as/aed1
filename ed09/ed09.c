/**
 * ed09 - v0.2 - 29/05/2021
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
    IO_println("Ler e mostrar matriz natural\n");

    // definir dados
    int rows = 0;
    int cols = 0;

    // ler dimensoes do teclado
    rows = IO_readint("\nLinhas: ");
    cols = IO_readint("Colunas: ");

    // definir matriz real com dimensoes informadas
    double matrix[rows][cols];
    readFloatMatrix(rows, cols, matrix);

    // mostrar matriz
    IO_printf("\n***************\n");
    IO_printf("Saida de dados:\n\n");
    printFloatMatrix(rows, cols, matrix);

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method02(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Ler matriz natural, gravar em arquivo e mostrar\n");

    // definir dados
    int rows = 0;
    int cols = 0;
    chars fileName = "matrix.txt";

    // ler dimensoes do teclado
    rows = IO_readint("\nLinhas: ");
    cols = IO_readint("Colunas: ");

    // definir matriz real com dimensoes informadas
    double matrix[rows][cols];
    readFloatMatrix(rows, cols, matrix);

    // gravar em arquivo
    fprintFloatMatrix(fileName, rows, cols, matrix);

    // mostrar matriz
    IO_printf("\n***************\n");
    IO_printf("Saida de dados:\n\n");
    freadFloatMatrix(fileName, rows, cols, matrix);
    printFloatMatrix(rows, cols, matrix);

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method03(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Mostrar diagonal principal de matriz quadrada real\n");

    // definir dados
    int rows = 0;
    int cols = 0;
    chars fileName = "matrix.txt";

    // ler dimensoes do teclado
    rows = IO_readint("\nLinhas: ");
    cols = IO_readint("Colunas: ");

    // definir matriz real com dimensoes informadas
    double matrix[rows][cols];
    freadFloatMatrix(fileName, rows, cols, matrix);

    // mostrar matriz
    IO_printf("\n***************\n");
    IO_printf("Saida de dados:\n\n");
    printMainDiagonal_f(rows, cols, matrix);

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method04(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Mostrar diagonal secundaria de matriz quadrada real\n");

    // definir dados
    int rows = 0;
    int cols = 0;
    chars fileName = "matrix.txt";

    // ler dimensoes do teclado
    rows = IO_readint("\nLinhas: ");
    cols = IO_readint("Colunas: ");

    // definir matriz real com dimensoes informadas
    double matrix[rows][cols];
    freadFloatMatrix(fileName, rows, cols, matrix);

    // mostrar matriz
    IO_printf("\n***************\n");
    IO_printf("Saida de dados:\n\n");
    printAntidiagonal_f(rows, cols, matrix);

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method05(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Mostrar triangulo inferior de matriz quadrada real\n");

    // definir dados
    int rows = 0;
    int cols = 0;
    chars fileName = "matrix.txt";

    // ler dimensoes do teclado
    rows = IO_readint("\nLinhas: ");
    cols = IO_readint("Colunas: ");

    // definir matriz real com dimensoes informadas
    double matrix[rows][cols];
    freadFloatMatrix(fileName, rows, cols, matrix);

    // mostrar matriz
    IO_printf("\n***************\n");
    IO_printf("Saida de dados:\n\n");
    printLowerTriangular_f(rows, cols, matrix);

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method06(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Mostrar triangulo superior de matriz quadrada real\n");

    // definir dados
    int rows = 0;
    int cols = 0;
    chars fileName = "matrix.txt";

    // ler dimensoes do teclado
    rows = IO_readint("\nLinhas: ");
    cols = IO_readint("Colunas: ");

    // definir matriz real com dimensoes informadas
    double matrix[rows][cols];
    freadFloatMatrix(fileName, rows, cols, matrix);

    // mostrar matriz
    IO_printf("\n***************\n");
    IO_printf("Saida de dados:\n\n");
    printUpperTriangular_f(rows, cols, matrix);

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method07(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Mostrar triangulo inferior secundario de matriz quadrada real\n");

    // definir dados
    int rows = 0;
    int cols = 0;
    chars fileName = "matrix.txt";

    // ler dimensoes do teclado
    rows = IO_readint("\nLinhas: ");
    cols = IO_readint("Colunas: ");

    // definir matriz real com dimensoes informadas
    double matrix[rows][cols];
    freadFloatMatrix(fileName, rows, cols, matrix);

    // mostrar matriz
    IO_printf("\n***************\n");
    IO_printf("Saida de dados:\n\n");
    printSecLowerTriangular_f(rows, cols, matrix);

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method08(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Mostrar triangulo superior secundario de matriz quadrada real\n");

    // definir dados
    int rows = 0;
    int cols = 0;
    chars fileName = "matrix.txt";

    // ler dimensoes do teclado
    rows = IO_readint("\nLinhas: ");
    cols = IO_readint("Colunas: ");

    // definir matriz real com dimensoes informadas
    double matrix[rows][cols];
    freadFloatMatrix(fileName, rows, cols, matrix);

    // mostrar matriz
    IO_printf("\n***************\n");
    IO_printf("Saida de dados:\n\n");
    printSecUpperTriangular_f(rows, cols, matrix);

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method09(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Testar se ha' somente zeros em triangulo inferior\n");

    // definir dados
    int rows = 0;
    int cols = 0;
    chars fileName = IO_new_chars(STR_SIZE);

    // ler dimensoes do teclado
    rows = IO_readint("\nLinhas: ");
    cols = IO_readint("Colunas: ");
    
    // ler nome do arquivo do teclado
    fileName = IO_readstring("Nome do arquivo: ");

    // definir matrizes reais com dimensoes informadas
    double matrix[rows][cols];
    freadFloatMatrix(fileName, rows, cols, matrix);

    // mostrar resultados para matriz
    IO_printf("\n***************\n");
    IO_printf("Resultados:\n\n");
    IO_printf("[Arquivo: '%s']\n", fileName);
    
    // mostrar matriz
    printFloatMatrix(rows, cols, matrix);

    if (! allZeroLowerTriangular_f(rows, cols, matrix))
    {
        IO_printf("\nHa' pelo menos um valor nao zero no triangulo inferior");
    }
    else
    {
        IO_printf("\nTodos os valores sao zero");
    }

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method10(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Testar se ha' somente zeros em triangulo superior\n");

    // definir dados
    int rows = 0;
    int cols = 0;
    chars fileName = IO_new_chars(STR_SIZE);

    // ler dimensoes do teclado
    rows = IO_readint("\nLinhas: ");
    cols = IO_readint("Colunas: ");
    
    // ler nome do arquivo do teclado
    fileName = IO_readstring("Nome do arquivo: ");

    // definir matrizes reais com dimensoes informadas
    double matrix[rows][cols];
    freadFloatMatrix(fileName, rows, cols, matrix);

    // mostrar resultados para matriz
    IO_printf("\n***************\n");
    IO_printf("Resultados:\n\n");
    IO_printf("[Arquivo: '%s']\n", fileName);
    
    // mostrar matriz
    printFloatMatrix(rows, cols, matrix);

    if (allZeroUpperTriangular_f(rows, cols, matrix))
    {
        IO_printf("Todos os valores sao zeros no triangulo superior");
    }
    else
    {
        IO_printf("\nHa' pelo menos um valor diferente de zero ");
    }

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method11(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Gerar matriz descrescente e gravar em arquivo\n");

    // definir dados
    int rows = 0;
    int cols = 0;
    chars fileName = "matrix_desc.txt";

    // ler dimensoes do teclado
    rows = IO_readint("\nLinhas: ");
    cols = IO_readint("Colunas: ");

    // definir matriz com dimensoes informadas
    int matrix[rows][cols];

    // gerar matriz decrescente
    genDescMatrix(rows, cols, matrix);

    // gravar em arquivo e mostrar
    fprintIntMatrix(fileName, rows, cols, matrix);
    IO_printf("\n[Matriz gravada em '%s']\n", fileName);
    printIntMatrix(rows, cols, matrix);


    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method12(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Gerar matriz descrescente transposta e gravar em arquivo\n");

    // definir dados
    int rows = 0;
    int cols = 0;
    chars fileName = "matrix_transp.txt";

    // ler dimensoes do teclado
    rows = IO_readint("\nLinhas: ");
    cols = IO_readint("Colunas: ");

    // definir matriz com dimensoes informadas
    int matrix[rows][cols];

    // gerar matriz decrescente
    genDescMatrix_transp(rows, cols, matrix);

    // gravar em arquivo e mostrar
    fprintIntMatrix(fileName, rows, cols, matrix);
    IO_printf("\n[Matriz gravada em '%s']\n", fileName);
    printIntMatrix(rows, cols, matrix);

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
 *  0.1      27/05/21        esboco
 *  0.2      29/05/21        finalizacao dos exercicios
 * ---------------------------------------------- testes
 */
