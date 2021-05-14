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

    for (int i = 1; i <= n; i++)
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

    for (int i = 1; i <= n; i++)
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
 * relacionais em uma cadeia de caracteres
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
    cadeia = IO_readln("\nEntre com cadeia de caracteres >> ");
    tamanho = strlen(cadeia);

    for (int i = 0; i < tamanho; i++)
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
        else if (isDelimiter(simbolo))
        {
            IO_printf("\n%c e' um separador", simbolo);
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
 * method04 - Procedimento para contar maiusculas, minusculas, digitos, 
 * operadores e separadores em uma cadeia de caracteres
 * @param methodId numero de identificacao do procedimento para decoracao
 */
void method04(int methodId)
{
    // definir dados
    chars cadeia = IO_new_chars(STR_SIZE);
    char simbolo = '\0';
    int tamanho = 0;
    int maiusculas = 0;
    int minusculas = 0;
    int digitos = 0;
    int operadores = 0;
    int separadores = 0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    cadeia = IO_readln("\nEntre com cadeia de caracteres >> ");
    tamanho = strlen(cadeia);

    for (int i = 0; i < tamanho; i++)
    {
        simbolo = cadeia[i];

        if (isUpper(simbolo))
        {
            maiusculas++;
        }
        else if (isLower(simbolo))
        {
            minusculas++;
        }
        else if (isDigit(simbolo))
        {
            digitos++;
        }
        else if ((isLogical(simbolo)) || (isArithmetic(simbolo)) || 
                 (isRelational(simbolo)))
        {
            operadores++;
        }
        else if (isDelimiter(simbolo))
        {
            separadores++;
        }
    }

    IO_printf("\nMaiusculas: %d", maiusculas);
    IO_printf("\nMinusculas: %d", minusculas);
    IO_printf("\nDigitos: %d", digitos);
    IO_printf("\nOperadores: %d", operadores);
    IO_printf("\nSeparadores %d", separadores);
}

/**
 * method05 - Procedimento para calcular medias e mostrar menor valor
 * @param methodId numero de identificacao do procedimento para decoracao
 */
void method05(int methodId)
{
    // definir dados
    int n = 0;
    double x = 0.0;
    double m1 = 0.0;
    double s1 = 0.0;
    int c1 = 0;
    double m2 = 0.0;
    double s2 = 0.0;
    int c2 = 0;
    double m3 = 0.0;
    double s3 = 0.0;
    int c3 = 0;
    double menor = 0.0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    n = IO_readint("\nEntre com quantidade inteira >> ");

    for (int i = 1; i <= n; i++)
    {
        IO_printf("Valor %d ", i);
        x = IO_readdouble(">> ");

        if (x < -33.25)
        {
            s1 = m1 + x;
            c1++;
        }
        else if (-33.25 <= x && x <= 65.75)
        {
            s2 = m2 + x;
            c2++;
        }
        else if (x > 66.75)
        {
            s3 = s3 + x;
            c3++;
        }
    }

    m1 = s1 / (double) c1;
    m2 = s2 / (double) c2;
    m3 = s3 / (double) c3;
    menor = smallest(m1, m2, m3);

    IO_printf("\nMedia 1: %lf", m1);
    IO_printf("\nMedia 2: %lf", m2);
    IO_printf("\nMedia 3: %lf\n", m3);
    IO_printf("\nA menor media e' %lf", menor);
}

/**
 * method06 - Procedimento para mostrar soma do cubo dos inversos de n numeros
 * @param methodId numero de identificacao do procedimento para decoracao
 */
void method06(int methodId)
{
    // definir dados
    int a = 0;
    int b = 0;
    int x = 0;
    double soma = 0.0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    a = IO_readint("\nEntre com intervalo inferior >> ");
    do
    {
        b = IO_readint("Entre com intervalo superior >> ");
    }
    while (b <= a);

    while (x != -1)
    {
        x = IO_readdouble("Entre com valor >> ");
        soma = soma + invCubeSum(x, a, b);
    }

    IO_printf("\nSoma = %lf", soma);
}

/**
 * method07 - Procedimento para mostrar quantidade de valores dentro e fora de
 * um intevalo informado, e porcentagem de valores acima e abaixo dos limites
 * @param methodId numero de identificacao do procedimento para decoracao
 */
void method07(int methodId)
{
    // definir dados
    double a = 0.0;
    double b = 0.0;
    double x = 0.0;
    int in = 0;
    int ex = 0;
    int acima = 0;
    int abaixo = 0;
    double acima_p = 0.0;
    double abaixo_p = 0.0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    a = IO_readint("\nEntre com intervalo inferior >> ");
    do
    {
        b = IO_readint("Entre com intervalo superior >> ");
    }
    while (b <= a);

    do
    {
        x = IO_readdouble("Entre com valor >> ");

        if (belongsTo_f(x, a, b))
        {
            in++;
        }
        else
        {
            ex++;

            if (x < a)
            {
                acima++;
            }
            else
            {
                abaixo++;
            }
        }
    }
    while (x != 0.0);

    IO_printf("\nValores dentro do intervalo: %d", in);
    IO_printf("\nValores fora do intervalo: %d", ex);

    if (ex > 0)
    {
        acima_p = ((double) acima / (double) ex) * 100.00;
        abaixo_p = ((double) abaixo / (double) ex) * 100.00;
        IO_printf("\nPorcentagem de valores acima do intervalo: %.2lf%%", acima_p);
        IO_printf("\nPorcentagem de valores acima do intervalo: %.2lf%%", abaixo_p);
    }
}

/**
 * method08 - Procedimento para mostrar se valores estao em ordem crescente,
 * decrescente ou nenhuma dessas ordens
 * @param methodId numero de identificacao do procedimento para decoracao
 */
void method08(int methodId)
{
    // definir dados
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    x = IO_readdouble("\nEntre com valor real (x) >> ");
    y = IO_readdouble("Entre com valor real (y) >> ");
    z = IO_readdouble("Entre com valor real (z) >> ");

    if (isIncreasing(x, y, z))
    {
        IO_printf("\nOs valores estao em ordem crescente");
    }
    else if (isDecreasing(x, y, z))
    {
        IO_printf("\nOs valores estao em ordem decrescente");
    }
    else
    {
        IO_printf("\nOs valores nao estao em ordenamento especifico");
        if (x > y && x > z)
        {
            if (y < z)
            {
                IO_printf("\nMaior valor: x; Menor valor: y");
            }
            else
            {
                IO_printf("\nMaior valor: x; Menor valor: z");
            }            
        }
        else if (y > x && y > z)
        {
            if (x < z)
            {
                IO_printf("\nMaior valor: y; Menor valor: x");   
            }
            else
            {
                IO_printf("\nMaior valor: y; Menor valor: z");
            }
        }
        else if (z > x && z > y)
        {
            if (x < y)
            {
                IO_printf("\nMaior valor: z; Menor valor: x");
            }
            else
            {
                IO_printf("\nMaior valor: z; Menor valor: y");
            }
        }
        else
        {
            IO_printf("\nHa' pelo menos dois valores iguais");
        }
    }
}

/**
 * method09 - Procedimento para mostrar se caracteres estao em ordem crescente,
 * decrescente ou nenhuma dessas ordens
 * @param methodId numero de identificacao do procedimento para decoracao
 */
void method09(int methodId)
{
    // definir dados
    char x = '\0';
    char y = '\0';
    char z = '\0';

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    x = IO_readchar("\nEntre com um caractere (x) >> ");
    y = IO_readchar("Entre com um caractere (y) >> ");
    z = IO_readchar("Entre com um caractere (z) >> ");

    if (isIncreasing_c(x, y, z))
    {
        IO_printf("\nOs caracteres estao em ordem crescente");
    }
    else if (isDecreasing_c(x, y, z))
    {
        IO_printf("\nOs caracteres estao em ordem decrescente");
    }
    else
    {
        IO_printf("\nOs caracteres nao estao em ordem especifica");
    }
}

/**
 * method10 - Procedimento para mostrar se cadeias de caracteres estao em ordem
 * crescente, decrescente ou nenhuma dessas ordens
 * @param methodId numero de identificacao do procedimento para decoracao
 */
void method10(int methodId)
{
    // definir dados
    chars x = IO_new_chars(STR_SIZE);
    chars y = IO_new_chars(STR_SIZE);
    chars z = IO_new_chars(STR_SIZE);
    char maior = '\0';
    char menor = '\0';

    // exibir identificacao
    decorateMethod(methodId);

    // ler quantidade do teclado
    x = IO_readstring("\nEntre com uma cadeia de caracteres (x) >> ");
    y = IO_readstring("Entre com uma cadeia de caracteres (y) >> ");
    z = IO_readstring("Entre com uma cadeia de caracteres (z) >> ");

    if (strcmp(x, y) < 0 && strcmp(y, z) < 0)
    {
        IO_printf("\nCadeias em ordem crescente");
    }
    else if (strcmp(x, y) > 0 && strcmp(y, z) > 0)
    {
        IO_printf("\nCadeias em ordem decrescente");
    }
    else if ((strcmp(x, y) != 0) && (strcmp(x, z) != 0) && (strcmp(y, z) != 0))
    {
        // encontrar maior
        if (strcmp(x, y) > 0 && strcmp(x, z) > 0)
        {
            maior = 'x';
        }
        else if (strcmp(y, x) > 0 && strcmp(y, z) > 0)
        {
            maior = 'y';
        }
        else if (strcmp(z, x) > 0 && strcmp(z, y) > 0)
        {
            maior = 'z';
        }

        // encontrar menor
        if (strcmp(x, y) < 0 && strcmp(x, z) < 0)
        {
            menor = 'x';
        }
        else if (strcmp(y, x) < 0 && strcmp(y, z) < 0)
        {
            menor = 'y';
        }
        else if (strcmp(z, x) < 0 && strcmp(z, y) < 0)
        {
            menor = 'z';
        }
        IO_printf("\nCadeias nao estao em ordem especifica");
        IO_printf("\nMaior: %c / Menor: %c", maior, menor);
    }
    else
    {
        IO_printf("\nCadeias nao estao em ordem especifica ");
        IO_printf("e pelo menos dois valores sao iguais");
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
    decorateMenu(10);

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
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      13/05/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 */
