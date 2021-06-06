/**
 * ed10 - v0.1 - 05/06/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o ed10 ed10.c
 * Windows: gcc -o ed10.exe ed10.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./ed10
 * Windows: ed10
 */

// dependencias
#include "io.h" // para definicoes proprias
#include "decorate.h" // procedimentos proprios de decoracao
#include "arraylib_io.h" // biblioteca de metodos

// definir o numero de identificacao do programa
char PROGRAM_ID[4] = "ED10";

// para as entradas e saidas

void method01(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados
    int_Array array;
    int inferior = 0;
    int superior = 0;

    // ler quantidade
    do
    {
        array.length = IO_readint("\nEntre com a quantidade >> ");
    }
    while (array.length <= 0);

    array.data = IO_new_ints(array.length);

    // ler limites
    inferior = IO_readint("\nEntre com o limite inferior >> ");

    while (superior <= inferior)
    {
        superior = IO_readint("\nEntre com o limite superior >> ");
    }

    // testar se ha' espaco
    if (array.data == NULL)
    {
        array.length= 0;
    }
    else
    {
        // inserir valores aleatorios no arranjo
        for (array.ix = 0; array.ix < array.length; array.ix++)
        {
            array.data[array.ix] = getRandomInt(inferior, superior);
        }
    }

    // gravar em arquivo
    fprintIntArray("dados.txt", array);

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method02(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados
    int value = 0;
    int result =  0;

    // ler arranjo do arquivo
    ref_int_Array array = freadintArray("dados.txt");

    // ler valor a procurar
    value = IO_readint("\nEntre com valor inteiro >> ");

    // procurar valor
    result = searchIntArray(value, array);

    if (result)
    {
        IO_printf("\nValor (%d) encontrado no arranjo", value);
    }
    else
    {
        IO_printf("\nValor (%d) NAO encontrado no arranjo", value);
    }

    // liberar espaco
    free_int_Array(array);

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method03(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados
    bool result = false;
    ref_int_Array array1 = freadintArray("dados1.txt");
    ref_int_Array array2 = freadintArray("dados2.txt");
    
    if (array1->length != array2->length)
    {
        IO_printf("\nERRO: arranjos possuem tamanhos diferentes");
    }
    else
    {
        result = isEqual_array(array1, array2);

        if (result)
        {
            IO_printf("\nOs arranjos sao iguais");
        }
        else
        {
            IO_printf("\nOs arranjos sao diferentes");
        }
    }

    // liberar espaco
    free_int_Array(array1);
    free_int_Array(array2);

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method04(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados
    int sum = 0;
    ref_int_Array array1 = freadintArray("dados1.txt");
    ref_int_Array array2 = freadintArray("dados2.txt");
    
    if (array1->length != array2->length)
    {
        IO_printf("\nERRO: arranjos possuem tamanhos diferentes");
    }
    else
    {
        sum = sumIntArrays(array1, array2, 5);
        IO_printf("\nSoma = %d", sum);
    }

    // liberar espaco
    free_int_Array(array1);
    free_int_Array(array2);

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method05(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Descricao do metodo\n");

    // definir dados
    ref_int_Array array = freadintArray("dados_ord.txt");
    bool result = isAscOrdered(array);
    
    if (result)
    {
        IO_printf("\nArranjo esta' em ordem crescente");
    }
    else
    {
        IO_printf("\nArranjo NAO esta' em ordem crescente");
    }

    // liberar espaco
    free_int_Array(array);

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
 *  0.1      05/06/21        esboco
 * ---------------------------------------------- testes
 */
