/**
 * Exemplos03 - v0.1 - 16/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplos03 Exemplos03.c
 * Windows: gcc -o Exemplos03.exe Exemplos03.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplos03
 * Windows: Exemplos03
 */

// dependencias
#include "io.h" // para definicoes proprias
#include "decorate.h" // procedimentos proprios de decoracao

// definir o numero de identificacao do programa
char* PROGRAM_ID = "04";

// funcoes para abstrair a execucao de testes

/**
 * Funcao para determinar se valor inteiro e' positivo
 * @return true, se positivo; false, caso contrario
 * @param x valor a ser testado
 */
bool isPositive(int x)
{
    /*
    // definir dado local
    bool result = false;

    //testar a condicao
    if (x > 0)
    {
        result = true;
    }
    return (result);
    */
    // retorno simplificado
    return (x > 0);
    
}

/**
 * Funcao para determinar se valor inteiro pertence a intervalo aberto
 * @return true, se pertencer; false, caso contrario
 * @param x valor a ser testado
 * @param inferior limite inferior
 * @param superior limite superior
 */
bool belongsToEx_d(int x, int inferior, int superior)
{
    /*
    // definir dado local
    bool result = false;

    //testar a condicao
    if (inferior < x && x < superior)
    {
        result = true;
    }
    return (result);
    */
    // retorno simplificado
    return (inferior < x && x < superior);
}

/**
 * Funcao para determinar se valor real pertence a intervalo fechado
 * @return true, se pertencer; false, caso contrario
 * @param x valor a ser testado
 * @param inferior limite inferior
 * @param superior limite superior
 */
bool belongsToIn_f(double x, double inferior, double superior)
{
    /*
    // definir dado local
    bool result = false;

    //testar a condicao
    if (inferior < x && x < superior)
    {
        result = true;
    }
    return (result);
    */
    // retorno simplificado
    return (inferior <= x && x <= superior);
}

/**
 * Funcao para determinar se valor inteiro e' par
 * @return true, se par; false, caso contrario
 * @param x valor a ser testado
 */
bool isEven(int x)
{
    /*
    // definir dado local
    bool result = false;

    //testar a condicao
    if (x % 2 == 0)
    {
        result = true;
    }
    return (result);
    */
    // retorno simplificado
    return (x % 2 == 0);
}

/**
 * Funcao para determinar se caractere e' letra minuscula
 * @return true, se minuscula; false, caso contrario
 * @param x valor a ser testado
 */
bool isLowerCase(char x)
{
    /*
    // definir dado local
    bool result = false;

    //testar a condicao
    if ('a' <= x && x <= 'z')
    {
        result = true;
    }
    return (result);
    */
    // retorno simplificado
    return ('a' <= x && x <= 'z');
}

/**
 * Funcao para determinar se caractere e' letra maiuscula
 * @return true, se maiuscula; false, caso contrario
 * @param x valor a ser testado
 */
bool isUpperCase(char x)
{
    /*
    // definir dado local
    bool result = false;

    //testar a condicao
    if ('a' <= x && x <= 'z')
    {
        result = true;
    }
    return (result);
    */
    // retorno simplificado
    return ('A' <= x && x <= 'Z');
}

/**
 * Funcao para determinar se caractere e' digito
 * @return true, se for digito; false, caso contrario
 * @param x valor a ser testado
 */
bool isDigit(char x)
{
    /*
    // definir dado local
    bool result = false;

    //testar a condicao
    if ('0' <= x && x <= '9')
    {
        result = true;
    }
    return (result);
    */
    // retorno simplificado
    return ('0' <= x && x <= '9');
}

/**
 * Funcao para concatenar 'a cadeia de caracteres mais um digito
 * @return cadeia de caracteres acrescida de mais um digito
 * @param string cadeia de caracteres
 * @param digit simbolo a ser acrescentado 'a cadeia de caracteres
 */
chars concatDigit(chars string, char digit)
{
   return (IO_concat(string, IO_toString_c(digit)));
}

/**
 * Funcao para mostrar os caracteres maiusculos e menores que caractere-controle
 * em uma cadeia de caracteres
 * @return quantidade de caracteres que satisfazem as condicoes
 * @param string cadeia de caracteres a testar
 * @param control caractere do limite superior
 */
chars showUpperToChar(chars string, char control)
{
    // definir dados
    int length = strlen(string);
    char character = '\0';
    chars valid = IO_new_chars(STR_SIZE);

    strcpy(valid, STR_EMPTY);

    //testar a condicao
    for (int i = 0; i < length; i++)
    {
        character = string[i];
        if (isUpperCase(character) && character < control)
        {
            valid = concatDigit(valid, character);
        }
    }
    return (valid); 
}

/**
 * Funcao para contar os caracteres (maiusculos e minusculos) e menores que caractere-controle
 * em uma cadeia de caracteres
 * @return quantidade de caracteres que satisfazem as condicoes
 * @param string cadeia de caracteres a testar
 * @param control caractere do limite superior
 */
int countUpperToChar(chars string, char control)
{
    // definir dados
    int count = 0;
    int length = strlen(string);
    char character = '\0';

    //testar a condicao
    for (int i = 0; i < length; i++)
    {
        character = string[i];
        if (isUpperCase(character) && character < control)
        {
            count++;
        }
    }
    return (count); 
}

/**
 * Funcao para contar os caracteres (minusculos e maiusculos) menores que o 
 * caractere-controle (minusculo/maiusculo) em uma cadeia de caracteres
 * @return quantidade de caracteres que satisfazem as condicoes
 * @param string cadeia de caracteres a testar
 * @param control caractere maiusculo do limite superior
 */
int countToChar(chars string, char control)
{
    // definir dados
    int length = strlen(string);
    int count = 0;
    char character = '\0';
    char controlLower = control + 32;

    //testar a condicao
    for (int i = 0; i < length; i++)
    {
        character = string[i];
        if ((isUpperCase(character) && character < control) ||
            (isLowerCase(character) && character < controlLower))
        {
            count++;
        }
    }
    return (count); 
}

/**
 * Funcao para mostrar os caracteres (minusculos e maiusculos) menores que o 
 * caractere-controle (minusculo/maiusculo) em uma cadeia de caracteres
 * @return quantidade de caracteres que satisfazem as condicoes
 * @param string cadeia de caracteres a testar
 * @param control caractere maiusculo do limite superior
 */
chars showToChar(chars string, char control)
{
    // definir dados
    int length = strlen(string);
    char character = '\0';
    char controlLower = control + 32;
    chars valid = IO_new_chars(STR_SIZE);

    strcpy(valid, STR_EMPTY);

    //testar a condicao
    for (int i = 0; i < length; i++)
    {
        character = string[i];
        if ((isUpperCase(character) && character < control) ||
            (isLowerCase(character) && character < controlLower))
        {
            valid = concatDigit(valid, character);
        }
    }
    return (valid); 
}

// para as entradas e saidas

/**
 * method01 - Procedimento para testar e contar valores pertencentes e
 * nao pertencentes a um intervalo real
 */
void method01(int methodId)
{
    // definir dados
    double inferior = 0.0;
    double superior = 0.0;
    double valor = 0.0;
    int reps = 6;
    int p = 0;
    int np = 0;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: valor real pertence a intervalo fechado");

    // ler limite inferior do teclado
    inferior = IO_readdouble("Entre com limite inferior (real) >> ");

    // ler limite superior do teclado (repetir ate' que >= inferior)
    do
    {
        superior = IO_readdouble("Entre com limite superior (real) >> ");
    } while (superior <= inferior);
    
    // ler 6 valores e testa-los
    for (int i = 0; i < reps; i++)
    {
        valor = IO_readdouble(
            IO_concat(
                IO_concat(
                    IO_concat("Entre com valor real (", IO_toString_d(i + 1)),
                    IO_concat("/", IO_toString_d(reps))
                ),
                ") >> "
            )
        );

        if (belongsToIn_f(valor, inferior, superior))
        {
            p++;
        }
        else
        {
            np++;
        }
    }
    
    // mostrar resultados
    printf("\n"); // imprimir nova linha antes de exibir resultados
    printf("%s: %d\n", "Valores dentro do intervalo", p);
    printf("%s: %d\n", "Valores fora do intervalo", np);
}

/**
 * method02 - Procedimento para contar e mostrar maiusculas menores que 'K'
 */
void method02(int methodId)
{
    // definir dados
    chars string = IO_new_chars(STR_SIZE);
    char caractere = '\0';
    int contador = 0;
    int tamanho = 0;

    strcpy(string, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: contar maiusculas menores que 'K'");

    // ler do teclado
    string = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    tamanho = strlen(string);
    IO_println(""); // inserir nova linha antes de exibir resultado

    for (int i = 0; i < tamanho; i++)
    {
        caractere = string[i];
        if (isUpperCase(caractere) && caractere < 'K')
        {
            contador++;
        }        
    }
    IO_printf("Total de maiusculas menores que 'K': %d", contador);
}

/**
 * method03 - Procedimento para contar maiusculas menores que 'K' por meio
 * de outra funcao 
 */
void method03(int methodId)
{
    // definir dados
    chars string = IO_new_chars(STR_SIZE);
    char controle = 'K';
    int contador = 0;

    strcpy(string, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: contar maiusculas menores que 'K'");

    // ler do teclado
    string = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    contador = countUpperToChar(string, controle);
    IO_printf("Total de maiusculas menores que 'K': %d\n", contador);
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
    int contador = 0;

    strcpy(string, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: contar caracteres menores que 'K' ou 'k'");

    // ler do teclado
    string = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    contador = countToChar(string, controle);
    IO_printf("Total de caracteres menores que 'K' ou 'k': %d\n", contador);
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
 * method07 - Procedimento para testar valores que sejam multiplos de 7
 * em um intervalo definido
 */
void method07(int methodId)
{
    // definir dados
    int start = 0; // limite inferior
    int stop = 0;  // limite superior
    int quant = 0; // quantidade de valores
    int value = 0; // valor para teste
    int count = 0; // contagem de valores validos
    chars valid = IO_new_chars(STR_SIZE); // valores validos

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: contar e mostrar multiplos de 7 em um intervalo");

    // ler do teclado
    start = IO_readint("\nEntrar com o limite inferior >> ");

    // repetir enquanto stop <= start
    do
    {
        stop = IO_readint(IO_concat("Entrar com o limite superior ",
                                    "- restricao: (start, inf) >> "));
    }
    while (stop <= start);

    // repetir enquanto quant <= 0
    do
    {
        quant = IO_readint(IO_concat("Entrar com quantidade a testar ",
                                     "- restricao: (0, inf) >> "));
    }
    while (quant <= 0);

    //int valid[quant];

    // inserir nova linha
    IO_println("");

    for (int i = 1; i <= quant; i++)
    {
        IO_print("Entrar com VALOR_");
        value = IO_readint(IO_concat(IO_toString_d(i), " >> "));

        if (value != 0 && value % 7 == 0 &&
            value >= start && value <= stop)
        {
            valid = IO_concat(valid, IO_toString_d(value));
            valid = IO_concat(valid, " ");
            //valid[i] = value;
            count++;
        }
    }

    if (count == 0)
    {
        valid = "nenhum valor";
    }
    IO_println(IO_concat("\nValores validos: ", valid));
    /*IO_print("\nValores validos: ");
    for (int i = 0; i < count; i++)
    {
        IO_print(IO_concat(IO_toString_d(valid[i]), " "));
    }*/
    IO_println(IO_concat("Total de valores: ", IO_toString_d(count)));
}

/**
 * method08 - Procedimento para testar valores que sejam multiplos de 7
 * e nao multiplos de 3 em um intervalo definido
 */
void method08(int methodId)
{
    // definir dados
    int start = 0; // limite inferior
    int stop = 0;  // limite superior
    int quant = 0; // quantidade de valores
    int value = 0; // valor para teste
    int count = 0; // contagem de valores validos
    chars valid = IO_new_chars(STR_SIZE); // valores validos

    // exibir identificacao
    decorateMethod(methodId);
    IO_println(IO_concat("Teste: contar e mostrar multiplos de 7 e ",
                         "nao multiplos de 3 em um intervalo"));

    // ler do teclado
    start = IO_readint("\nEntrar com o limite inferior >> ");

    // repetir enquanto stop <= start
    do
    {
        stop = IO_readint(IO_concat("Entrar com o limite superior ",
                                    "- restricao: (start, inf) >> "));
    }
    while (stop <= start);

    // repetir enquanto quant <= 0
    do
    {
        quant = IO_readint(IO_concat("Entrar com quantidade a testar ",
                                     "- restricao: (0, inf) >> "));
    }
    while (quant <= 0);

    // inserir nova linha
    IO_println("");

    for (int i = 1; i <= quant; i++)
    {
        IO_print("Entrar com VALOR_");
        value = IO_readint(IO_concat(IO_toString_d(i), " >> "));

        if (value != 0 && value % 7 == 0 && value % 3 != 0 &&
            value >= start && value <= stop)
        {
            valid = IO_concat(valid, IO_toString_d(value));
            valid = IO_concat(valid, " ");
            count++;
        }
    }

    if (count == 0)
    {
        valid = "nenhum valor";
    }
    IO_println(IO_concat("\nValores validos: ", valid));
    IO_println(IO_concat("Total de valores: ", IO_toString_d(count)));
}

/**
 * method09 - Procedimento para testar valores reais pertencentes a um
 * intervalo definido, com parte inteira impar
 */
void method09(int methodId)
{
    // definir dados
    double start = 0.0; // limite inferior
    double stop = 0.0;  // limite superior
    double value = 0.0; // valor para teste
    int quant = 0;      // quantidade de valores
    int trunc = 0;      // valor truncado (inteiro)
    int count = 0;      // contagem de valores validos
    chars valid = IO_new_chars(STR_SIZE); // valores validos

    // exibir identificacao
    decorateMethod(methodId);
    IO_println(IO_concat("Teste: contar e mostrar valores reais em intervalo ",
                         "e com parte inteira impar"));

    // ler do teclado
    start = IO_readdouble("\nEntrar com o limite inferior >> ");

    // repetir enquanto stop <= start
    do
    {
        stop = IO_readdouble(IO_concat("Entrar com o limite superior ",
                                       "- restricao: (start, inf) >> "));
    }
    while (stop <= start);

    // repetir enquanto quant <= 0
    do
    {
        quant = IO_readint(IO_concat("Entrar com quantidade a testar ",
                                     "- restricao: (0, inf) >> "));
    }
    while (quant <= 0);

    // inserir nova linha
    IO_println("");

    for (int i = 1; i <= quant; i++)
    {
        IO_print("Entrar com VALOR_");
        value = IO_readdouble(IO_concat(IO_toString_d(i), " >> "));
        trunc = value;
        if (value >= start && value <= stop && trunc % 2 != 0)
        {
            valid = IO_concat(valid, IO_toString_f(value));
            valid = IO_concat(valid, " ");
            count++;
        }
    }

    if (count == 0)
    {
        valid = "nenhum valor";
    }
    IO_println(IO_concat("\nValores validos: ", valid));
    IO_println(IO_concat("Total de valores: ", IO_toString_d(count)));
}

/**
 * method10 - Procedimento para testar valores reais com parte fracionaria
 * pertencente a um intervalo definido
 */
void method10(int methodId)
{
    // definir dados
    double start = 0.0;   // limite inferior
    double stop = 0.0;    // limite superior
    double value = 0.0;   // valor para teste
    double control = 0.0; // valor de controle para parte fracionaria
    int quant = 0;        // quantidade de valores
    int trunc = 0;        // valor truncado (inteiro)
    int count = 0;        // contagem de valores validos
    chars valid = IO_new_chars(STR_SIZE); // valores validos

    // exibir identificacao
    decorateMethod(methodId);
    IO_println(IO_concat("Teste: contar e mostrar valores com parte ",
                         "fracionaria pertencente ao intervalo"));

    // ler do teclado
    do
    {
    start = IO_readdouble(IO_concat("\nEntrar com o limite inferior ",
                                    "- restricao: (0, 1) >> "));
    }
    while (start <= 0 || start >= 1);

    // repetir enquanto stop <= start
    do
    {
        stop = IO_readdouble(IO_concat("Entrar com o limite superior ",
                                       "- restricao: (start, 1) >> "));
    }
    while (stop <= start || stop >= 1);

    // repetir enquanto quant <= 0
    do
    {
        quant = IO_readint(IO_concat("Entrar com quantidade a testar ",
                                     "- restricao: (0, inf) >> "));
    }
    while (quant <= 0);

    // inserir nova linha
    IO_println("");

    for (int i = 1; i <= quant; i++)
    {
        IO_print("Entrar com VALOR_");
        value = IO_readdouble(IO_concat(IO_toString_d(i), " >> "));

        if (value < 0.0)
        {
            trunc = value * (-1);
            control = (value * (-1.0)) - trunc;
        }
        else
        {
            trunc = value;
            control = value - trunc;
        }

        if (control >= start && control <= stop)
        {
            valid = IO_concat(valid, IO_toString_f(value));
            valid = IO_concat(valid, " ");
            count++;
        }
    }

    if (count == 0)
    {
        valid = "nenhum valor";
    }
    IO_println(IO_concat("\nValores validos: ", valid));
    IO_println(IO_concat("Total de valores: ", IO_toString_d(count)));
}

/**
 * method11 - Procedimento para mostrar todos os simbolos nao alfanumericos
 * de uma linha
 */
void method11(int methodId)
{
    // definir dados
    chars value = IO_new_chars(STR_SIZE); // cadeia de caracteres do usuario
    chars testValue = IO_new_chars(STR_SIZE); // valor para teste
    char testChar; // caractere a testar

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: mostrar simbolos nao alfanumericos");

    // ler do teclado
    value = IO_readln("\nEntrar com cadeia de caracteres >> ");
    for (int i = 0; i < strlen(value); i++)
    {
        testChar = value[i];
        if (!(testChar >= 'a' && testChar <= 'z') &&
            !(testChar >= 'A' && testChar <= 'Z') &&
            !(testChar >= '0' && testChar <= '9'))
        {
            strncat(testValue, &testChar, 1);
        }
    }

    IO_println(IO_concat("\nOriginal: ", value));
    if (strlen(testValue) > 0)
    {
        IO_println(IO_concat("Simbolos nao alfanumericos: ", testValue));
    }
    else
    {
        IO_println("Nenhum simbolo exceto digitos ou letras.");
    }
}

/**
 * method12 - Procedimento para determinar se cadeia de caracteres
 * nao contem letras
 */
void method12(int methodId)
{
    // definir dados
    chars value = IO_new_chars(STR_SIZE); // cadeia de caracteres do usuario
    char testChar; // caractere a testar
    int control = 0;

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: determinar se sequencia nao contem letras");

    // ler do teclado
    value = IO_readln("\nEntrar com cadeia de caracteres >> ");
    for (int i = 0; i < strlen(value); i++)
    {
        testChar = value[i];
        if ((testChar >= 'a' && testChar <= 'z') ||
            (testChar >= 'A' && testChar <= 'Z'))
        {
            control++;
            break;
        }
    }

    if (control > 0)
    {
        IO_println("\nA sequencia contem pelo menos uma letra.");
    }
    else
    {
        IO_println("\nA sequencia nao contem letras.");
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
    strcpy(programId, IO_concat(IO_concat("=          ED", PROGRAM_ID),
                                          " - Programa = v0.1          ="));
    IO_clrscr();
    IO_id(programId);


    // definir dado
    int option = 0; // inicializar variavel para selecionar opcao

    // exibir opcoes
    decorateMenu(12);

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
    case 11:
        method11(option);
        break;
    case 12:
        method12(option);
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
 * 00. programa encerrado
 *
 * 01. "ABCD" => "Nenhuma minuscula"
 *     "ABCDefgh" => "efgh"
 *     "1234ABc." => "c"
 *
 * 02. "ABCD" => "Nenhuma minuscula", "Total: 0"
 *     "ABCDefgh" => "hgfe", "Total: 4"
 *     "1234ABc." => "c", "Total: 1"
 *
 * 03. "ABCD" => "Nenhuma minuscula", "Total: 0"
 *     "ABCDefgh" => "efgh", "Total: 4"
 *     "a1234BCd." => "da", "Total: 2"
 *
 * 04. "1234/" => "Nenhuma letra", "Total: 0"
 *     "123ABcd,." => "ABcd", "Total: 4"
 *     "AaBbÇçDd" => "AaBbDd", "Total: 6"
 *
 * 05. "1234/" => "Nenhuma letra", "Total: 0"
 *     "123ABcd,." => "dcBA", "Total: 4"
 *     "AaBbÇçDd" => "dDbBaA", "Total: 6"
 *
 * 06. "ABcd019" => "Nenhum simbolo", "Total: 0"
 *     "123ABcd,." => ",.", "Total: 2"
 *     "0AaBbÇçDd9" => "Çç", "Total: 2" (O total retornado no teste foi 4.
 *                                       Minha suposicao e' de que o programa
 *                                       conta a letra mais o acento.)
 * 07. ## INPUT ##
 *     start: -7
 *     stop: 21
 *     quant: 6
 *     valores: -21, -7, 0, 1, 14, 28
 *     ## OUTPUT ##
 *     validos: -7 14
 *     total: 2
 *
 * 08. ## INPUT ##
 *     start: -20
 *     stop: 21
 *     quant: 6
 *     valores: -28, -7, 0, 3, 14, 21
 *     ## OUTPUT ##
 *     validos: -7 14
 *     total: 2
 *
 * 09. ## INPUT ##
 *     start: -5.01
 *     stop: 4.99
 *     quant: 6
 *     valores: -5.02, -3.141592, 0, 1.0, 2.71828, 5.0
 *     ## OUTPUT ##
 *     validos: -3.141592 1.000000
 *     total: 2
 *
 * 10. ## INPUT ##
 *     start: 0.2
 *     stop: 0.999999
 *     quant: 6
 *     valores: 0.199999, -5.2, 0.0, 2.71828, -299792458.5, 10.999999
 *     ## OUTPUT ##
 *     validos: -5.200000, 2.718280, -299792458.500000, 10.999999
 *     total: 4
 *     ## RESULTADO OBTIDO ##
 *     validos: -5.200000, 2.718280, -299792458.500000
 *     total: 3
 *     (O valor 10.999999 nao foi considerado como dentro do intervalo.
 *      Testes feitos com 10.999998 e 10.99999, no entanto, funcionaram.)
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      16/04/21        esboco
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
 *          11. (OK)       teste method11
 *          12. (OK)       teste method12
 *          13. (OK)       teste opcao invalida
 */
