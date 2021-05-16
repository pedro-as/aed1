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

void method06(int methodId)
{
    FILE *saida = fopen("RESULTADO06.TXT", "wt");
    int quant = 0;
    double soma = 0.0;

    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Soma dos (n) primeiros valores gravados no Metodo 05\n");

    // gravar cabecalho do arquivo de saida
    fprintf(saida, "Arquivo de entrada: DADOS05.TXT\n");
    fprintf(saida, "\nQuantidade\t\tSoma\n");
    fprintf(saida, "-------------------------------\n");

    do // executar para diferentes quantidades
    {
        // ler quantidade do teclado
        quant = IO_readint("\nEntre com quantidade inteira >> ");

        // executar metodo e gravar em arquivo
        if (quant > 0)
        {
            soma = sumValues("DADOS05.TXT", quant);
            fprintf(saida, "\t%d\t\t%.12lf\n", quant, soma);
        }
    }
    while (quant != 0);

    // fechar arquivo para gravacao
    fclose(saida);
}

void method07(int methodId)
{
    FILE *saida = fopen("RESULTADO07.TXT", "wt");
    int quant = 0;
    double soma = 0.0;

    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Soma dos (n) primeiros valores gravados no Metodo 04\n");

    // gravar cabecalho do arquivo de saida
    fprintf(saida, "Arquivo de entrada: DADOS04.TXT\n");
    fprintf(saida, "\nQuantidade\t\tSoma\n");
    fprintf(saida, "-------------------------------\n");

    do // executar para diferentes quantidades
    {
        // ler quantidade do teclado
        quant = IO_readint("\nEntre com quantidade inteira >> ");

        // executar metodo e gravar em arquivo
        if (quant > 0)
        {
            soma = sumValues("DADOS04.TXT", quant);
            fprintf(saida, "\t%d\t\t%.12lf\n", quant, soma);
        }
    }
    while (quant != 0);

    // fechar arquivo para gravacao
    fclose(saida);
}

void method08(int methodId)
{
    FILE *saida = fopen("RESULTADO08.TXT", "wt");
    int quant = 0;

    // decorar o metodo
    decorateMethod(methodId);
    IO_println("(n) primeiros termos impares da serie de Fibonacci\n");

    // gravar cabecalho do arquivo de saida
    fprintf(saida, "\nQuantidade\t\tTermos\n");
    fprintf(saida, "-------------------------------\n");

    do // executar para diferentes quantidades
    {
        // ler quantidade do teclado
        quant = IO_readint("\nEntre com quantidade inteira >> ");

        // executar metodo para gravar em arquivo
        if (quant > 0)
        {
            int x = 0;
            int c = 1;
            fprintf(saida, "\t%d\t\t\t", quant);

            for(int i = 1; i <= quant; i++)
            {
                if (c % 3 == 0)
                {
                    c++;
                }

                x = fibonacci(c);
                fprintf(saida, "%d ", x);
                c++;
            }
            fprintf(saida, "\n");
        }
    }
    while (quant != 0);

    // fechar arquivo para gravacao
    fclose(saida);
}

void method09(int methodId)
{
    FILE *dados = fopen("DADOS09.TXT", "wt");
    chars cadeia = IO_new_chars(STR_SIZE);

    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Total de maiusculas em cadeias de caracteres em arquivo\n");

    do // executar para varias cadeias de caractere
    {
        // ler quantidade do teclado
        IO_printf("\nEntre com cadeia de caracteres ");
        cadeia = IO_readstring("('PARAR' para interromper) >> ");

        // executar metodo e gravar em arquivo
        if (strcmp(cadeia, "PARAR") != 0)
        {
            fprintf(dados, "%s\n", cadeia);
        }
    }
    while (strcmp(cadeia, "PARAR") != 0);

    // fechar arquivo de dadoss
    fclose(dados);

    writeUpper("DADOS09.TXT", "RESULTADO09.TXT");
}

void method10(int methodId)
{
    FILE *dados = fopen("DADOS10.TXT", "wt");
    chars cadeia = IO_new_chars(STR_SIZE);

    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Total de digitos menores ou iguais a 5 em cadeias de caractere\n");

    do // executar para varias cadeias de caractere
    {
        // ler quantidade do teclado
        IO_printf("\nEntre com cadeia de caracteres ");
        cadeia = IO_readstring("('PARAR' para interromper) >> ");

        // executar metodo e gravar em arquivo
        if (strcmp(cadeia, "PARAR") != 0)
        {
            fprintf(dados, "%s\n", cadeia);
        }
    }
    while (strcmp(cadeia, "PARAR") != 0);

    // fechar arquivo de dadoss
    fclose(dados);

    writeDigits_LE5("DADOS10.TXT", "RESULTADO10.TXT");
}

void method11(int methodId)
{
    FILE *saida = fopen("DADOS11.TXT", "wt");
    int x = 0;

    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Divisores de (x) em ordem decrescente\n");

    // ler quantidade do teclado
    x = IO_readint("\nEntre com valor inteiro (x) >> ");
    // executar metodo e gravar em arquivo
    for (int i = x; i > 0; i--)
    {
        if (x % i == 0)
        {
            fprintf(saida, "%d\n", i);
        }
    }
    // fechar arquivo de dadoss
    fclose(saida);
}

void method12(int methodId)
{
    chars nomeArquivo = "DADOS12.TXT";
    FILE *arquivo = fopen(nomeArquivo, "rt");
    chars palavra = IO_new_chars(STR_SIZE);
    char letra = '\0';
    int total = 0;

    // decorar o metodo
    decorateMethod(methodId);
    IO_println("Total de palavras em arquivo iniciadas com 'a' ou 'A'\n");

    // tentar ler primeira linha
    strcpy(palavra, IO_fread(arquivo));

    // repetir enquanto houver dados
    while (! feof(arquivo))
    {
        letra = palavra[0];
        if (letra == 'a' || letra == 'A')
        {
            total++;
        }
        strcpy(palavra, IO_fread(arquivo));
    }
    
    // fechar arquivo de dados
    fclose(arquivo);

    // mostrar total
    IO_printf("\nTotal encontrado em '%s': %d\n", nomeArquivo, total);
    IO_pause("Aperte <ENTER> para voltar ao menu");
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

    do
    {
        IO_clrscr();
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
 *  0.1      13/05/21        esboco
 * ---------------------------------------------- testes
 * Os valores e quantidades utilizados nos testes estao documentados nos arqui-
 * vos TXT que acompanham este programa.
 * Versao      Teste
 */
