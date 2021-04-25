/**
 * ed04 - v0.1 - 24/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o ed04 ed04.c
 * Windows: gcc -o ed04.exe ed04.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./ed04
 * Windows: ed04
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
 * Funcao para determinar se caractere e' alfanumerico
 * @return true, se for alfanumerico; false, caso contrario
 * @param x valor a ser testado
 */
bool isAlnum(char x)
{
    // definir dado local
    bool result = false;

    //testar a condicao
    if ('0' <= x && x <= '9' ||
        'A' <= x && x <= 'Z' ||
        'a' <= x && x <= 'z')
    {
        result = true;
    }
    return (result);
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
 * @return caracteres que satisfazem as condicoes
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
 * @return caracteres que satisfazem as condicoes
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

/**
 * Funcao para contar os digitos impares em uma cadeia de caracteres
 * @return quantidade de digitos impares
 * @param string cadeia de caracteres a testar
 */
int countOddDigits(chars string)
{
    // definir dados
    int length = strlen(string);
    int count = 0;
    char character = '\0';
    int charDigit = 0;

    //testar a condicao
    for (int i = 0; i < length; i++)
    {
        character = string[i];
        charDigit = (int) character - 48;
        if (isDigit(character) && ! isEven(character))
        {
            count++;
        }
    }
    return (count);
}

/**
 * Funcao para mostrar os simbolos nao alfanumericos uma cadeia de caracteres
 * @return simbolos nao alfanumericos
 * @param string cadeia de caracteres a testar
 */
chars showNonAlnum(chars string)
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
        if (! isAlnum(character))
        {
            valid = concatDigit(valid, character);
        }
    }
    return (valid);
}

/**
 * Funcao para mostrar os simbolos alfanumericos uma cadeia de caracteres
 * @return simbolos alfanumericos
 * @param string cadeia de caracteres a testar
 */
chars showAlnum(chars string)
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
        if (isAlnum(character))
        {
            valid = concatDigit(valid, character);
        }
    }
    return (valid);
}

/**
 * Funcao para contar os simbolos alfanumericos uma cadeia de caracteres
 * @return quantidade de simbolos alfanumericos
 * @param string cadeia de caracteres a testar
 */
int countAlnum(chars string)
{
    // definir dados
    int length = strlen(string);
    int count = 0;
    char character = '\0';

    //testar a condicao
    for (int i = 0; i < length; i++)
    {
        character = string[i];
        if (isAlnum(character))
        {
            count++;
        }
    }
    return (count);
}

/**
 * Funcao para concatenar resultados de um ou mais testes com
 * cadeia de caracteres
 * @return resultado de teste concatenado
 * @param string cadeia de caracteres
 * @param symbols simbolos resultantes a acrescentar 'a cadeia de caracteres
 * @param count quantidade resultante a acrescentar 'a cadeia de caracteres
 */
chars concatResult(chars string, chars symbols, int count)
{
    chars fullString = IO_new_chars(STR_SIZE);
    fullString = IO_concat(
                           IO_concat(
                                     IO_concat(string, " => "),
                                     IO_concat(symbols, " (")),
                           IO_concat(IO_toString_d(count), ")\n"));

    return(fullString);
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
    int total = 0;

    strcpy(string, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: contar caracteres menores que 'K' ou 'k'");

    // ler do teclado
    string = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    total = countToChar(string, controle);
    IO_printf("Total de caracteres menores que 'K' ou 'k': %d\n", total);
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
 * method07 - Procedimento para mostrar total de digitos impares em uma cadeia
 * de caracteres
 */
void method07(int methodId)
{
    // definir dados
    chars string = IO_new_chars(STR_SIZE);
    int total = 0;

    strcpy(string, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: contar digitos impares na cadeia de caracteres");

    // ler do teclado
    string = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    total = countOddDigits(string);
    IO_printf("Total de digitos impares: %d\n", total);
}

/**
 * method08 - Procedimento para mostrar os simbolos nao alfanumericos em uma
 * cadeia de caracteres
 */
void method08(int methodId)
{
    // definir dados
    chars string = IO_new_chars(STR_SIZE);
    chars validas = IO_new_chars(STR_SIZE);

    strcpy(string, STR_EMPTY);
    strcpy(validas, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: mostrar simbolos nao alfanumericos na cadeia de caracteres");

    // ler do teclado
    string = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    validas = showNonAlnum(string);
    IO_printf("Simbolos nao alfanumericos: %s\n", validas);
}

/**
 * method09 - Procedimento para mostrar os simbolos alfanumericos em uma
 * cadeia de caracteres
 */
void method09(int methodId)
{
    // definir dados
    chars string = IO_new_chars(STR_SIZE);
    chars validas = IO_new_chars(STR_SIZE);

    strcpy(string, STR_EMPTY);
    strcpy(validas, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste: mostrar simbolos alfanumericos na cadeia de caracteres");

    // ler do teclado
    string = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    validas = showAlnum(string);
    IO_printf("Simbolos alfanumericos: %s\n", validas);
}

/**
 * method10 - Procedimento para mostrar e contar os simbolos alfanumericos em
 * multiplas cadeias de caracteres e calcular o total de todas as palavras
 */
void method10(int methodId)
{
    // definir dados
    int reps = 0;
    int subtotal = 0;
    int total = 0;
    chars string = IO_new_chars(STR_SIZE);
    chars simbolos = IO_new_chars(STR_SIZE);
    chars preConcat = IO_new_chars(STR_SIZE);
    chars resultado = IO_new_chars(STR_SIZE);

    strcpy(string, STR_EMPTY);
    strcpy(simbolos, STR_EMPTY);
    strcpy(preConcat, STR_EMPTY);
    strcpy(resultado, STR_EMPTY);

    // exibir identificacao
    decorateMethod(methodId);
    IO_println("Teste multiplo: mostrar e contar simbolos alfanumericos");

    // ler do teclado
    reps = IO_readint("\nEntrar com o numero de repeticoes >> ");

    for (int i = 0; i < reps; i++)
    {
        string = IO_readstring("Entrar com uma cadeia de caracteres >> ");
        simbolos = showAlnum(string);
        subtotal = countAlnum(string);
        total = total + subtotal;
        preConcat = concatResult(string, simbolos, subtotal);
        strncat(resultado, preConcat, STR_SIZE);
    }
    IO_println("");
    IO_println(resultado);
    IO_printf("Total de simbolos alfanum. encontrados no teste: %d\n", total);
}

/**
 * method11 - Procedimento
 */
void method11(int methodId)
{
    return;
}

/**
 * method12 - Procedimento
 */
void method12(int methodId)
{
    return;
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
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      24/04/21        esboco
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
 */
