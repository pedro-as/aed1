/**
 * ed08 - v0.1 - dd/MM/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o ed08 ed08.c
 * Windows: gcc -o ed08.exe ed08.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./ed08
 * Windows: ed08
 */

// dependencias
#include "io.h" // para definicoes proprias
#include "decorate.h" // procedimentos proprios de decoracao
#include "myMethods.h" // biblioteca de metodos

// definir o numero de identificacao do programa
char PROGRAM_ID[4] = "ED08";

// para as entradas e saidas

void method01(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Verificar valores positivos e pares em arranjo\n");

    // definir dados
    int n = 0;

    // ler dados
    while (n <= 0) // tamanho do arranjo deve ser positivo
    {
        n = IO_readint("Entre com o tamanho do arranjo >> ");
    }

    // definir armazenador
    int array[n];

    // ler elementos do arranjo
    readIntArray(n, array);

    // verificar se todos os valores sao positivos e pares
    // e mostrar resultado
    if (isAllEvenPositive(n, array))
    {
        IO_printf("\nTodos os valores do arranjo sao positivos e pares");
    }
    else
    {
        IO_printf("\nPelo menos um valor do arranjo nao e' positivo ou par");
    }

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method02(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados
    int n = 0;
    chars fileIn = "ARRAY02.TXT";
    chars fileOut = "DADOS02.TXT";

    // verificar tamanho do arranjo
    n = freadArraySize(fileIn);

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        // definir armazenador
        int array[n];

        // ler do arquivo
        freadIntArray(fileIn, n, array);

        // guardar em arquivo o tamanho e os elementos validos
        fprintIntArray_evenPos(fileOut, n, array);
    }

    // finalizar metodo
    IO_printf("\nGravacao finalizada");
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method03(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados
    int n = 0;
    int x = 0;
    int inferior = 0;
    int superior = 0;

    // ler dados
    while (n <= 0)
    {
        n = IO_readint("\nEntre com a quantidade a ser gerada >> ");
    }

    inferior = IO_readint("\nEntre com o limite inferior >> ");

    while (superior <= inferior)
    {
        superior = IO_readint("\nEntre com o limite superior >> ");
    }

    // definir armazenador
    int array[n];

    // gerar valores e armazenar em arranjo
    for (int i = 0; i < n; i++)
    {
        x = getRandomInt(inferior, superior);
        array[i] = x;
    }

    fprintIntArray("DADOS03.TXT", n, array);

    // deixar os resultados na tela
    IO_printf("\nGravacao finalizada");
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method04(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados
    int n = 0;
    int menor = 0;
    chars fileIn = "ARRAY04.TXT";

    // verificar tamanho do arranjo
    n = freadArraySize(fileIn);

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        // definir armazenador
        int array[n];

        // ler do arquivo
        freadIntArray(fileIn, n, array);

        // encontrar menor valor
        menor = minArray(n, array);

        // mostrar menor valor
        IO_printf("\nMenor valor no arranjo: %d", menor);
    }

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method05(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados
    int n = 0;
    int maior = 0;
    chars fileIn = "ARRAY05.TXT";

    // verificar tamanho do arranjo
    n = freadArraySize(fileIn);

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        // definir armazenador
        int array[n];

        // ler do arquivo
        freadIntArray(fileIn, n, array);

        // encontrar maior valor
        maior = maxArray(n, array);

        // mostrar maior valor
        IO_printf("\nMaior valor no arranjo: %d", maior);
    }

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method06(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados


    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method07(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados


    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method08(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados


    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method09(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados


    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method10(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados


    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method11(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados


    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method12(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados


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
