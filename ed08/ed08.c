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
    IO_println("Copiar valores pares positivos entre arquivos");
    IO_println("(primeira linha da saida = tamanho da entrada)\n");

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
        fprintIntArray_evenPositive(fileOut, n, array);
    }

    // finalizar metodo
    IO_printf("\nGravacao finalizada");
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method03(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Gravar valores aleatorios em arquivo\n");

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

    fprintIntArray("DADOS.TXT", n, array);

    // deixar os resultados na tela
    IO_printf("\nGravacao finalizada");
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method04(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Procurar menor valor em arranjo\n");

    // definir dados
    int n = 0;
    int menor = 0;
    chars fileIn = "DADOS.TXT";

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
        menor = minIntArray(n, array);

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
    IO_println("Procurar maior valor em arranjo\n");

    // definir dados
    int n = 0;
    int maior = 0;
    chars fileIn = "DADOS.TXT";

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
        maior = maxIntArray(n, array);

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
    IO_println("Calcular media de valores em arranjo\n");

    // definir dados
    int n = 0;
    double media = 0.0;
    chars fileIn = "DADOS.TXT";

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

        // encontrar valor medio
        media = meanIntArray(n, array);

        // mostrar valor medio
        IO_printf("\nValor medio do arranjo: %lf", media);
    }

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method07(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Verificar se arranjo esta' em ordem crescente\n");

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

    // verificar se o arranjo esta' em ordem crescente
    if (isOrderedIntArray_asc(n, array))
    {
        IO_printf("\nO arranjo esta' em ordem crescente");
    }
    else
    {
        IO_printf("\nO arranjo esta' desordenado");
    }

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method08(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Procurar valor em arranjo a partir de posicao inicial\n");

    // definir dados
    int n = 0;
    int procurado = 0;
    int posicao = 5;
    chars fileIn = "DADOS.TXT";

    // verificar tamanho do arranjo
    n = freadArraySize(fileIn);

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        // ler valor a ser procurado
        procurado = IO_readint("Entre com o valor inteiro a procurar >> ");

        // definir armazenador
        int array[n];

        // ler do arquivo
        freadIntArray(fileIn, n, array);

        // verificar se o valor esta' no arranjo a partir da posicao indicada
        if (searchIntArray_pos(procurado, posicao, n, array))
        {
            IO_printf("\nVal: %d; pos: %d => encontrado", procurado, posicao);
        }
        else
        {
            IO_printf("\nVal: %d; pos: %d => nao encontrado", procurado, posicao);
        }
    }

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method09(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Procurar indice de valor em arranjo\n");

    // definir dados
    int n = 0;
    int procurado = 0;
    int posicao = 5;
    int indice = 0;
    chars fileIn = "DADOS.TXT";

    // verificar tamanho do arranjo
    n = freadArraySize(fileIn);

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        // ler valor a ser procurado
        procurado = IO_readint("Entre com o valor inteiro a procurar >> ");

        // definir armazenador
        int array[n];

        // ler do arquivo
        freadIntArray(fileIn, n, array);

        // verificar se o valor esta' no arranjo a partir da posicao indicada
        if (searchIntArray_pos(procurado, posicao, n, array))
        {
            // procurar o indice
            indice = indexIntArray_pos(procurado, posicao, n, array);
            IO_printf("\nValor: %d => indice: %d", procurado, indice);
        }
        else
        {
            IO_printf("\nValor (%d) nao encontrado", procurado);
        }
    }

    // deixar os resultados na tela
    IO_pause("\n\n<Enter> para voltar ao menu");
}

void method10(int methodId)
{
    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Calcular quantidade de valor em arranjo\n");

    // definir dados
    int n = 0;
    int procurado = 0;
    int posicao = 5;
    int quant = 0;
    chars fileIn = "DADOS.TXT";

    // verificar tamanho do arranjo
    n = freadArraySize(fileIn);

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        // ler valor a ser procurado
        procurado = IO_readint("Entre com o valor inteiro a procurar >> ");

        // definir armazenador
        int array[n];

        // ler do arquivo
        freadIntArray(fileIn, n, array);

        // procurar quantidade do valor no arranjo
        quant = searchIntArray_quant(procurado, posicao, n, array);
        IO_printf("\nValor: %d => quantidade: %d", procurado, quant);
    }

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
