#include <math.h>
// #include "io.h"

// funcoes para abstrair a execucao de testes

/**
 * Funcao para retornar o produto de um valor-base por um coeficiente inteiro
 * @return produto de x por n
 * @param x valor-base
 * @param n multiplicador
 */
int multipleValue(int x, int n)
{
    return (x * n);
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
    if (('0' <= x && x <= '9') ||
        ('A' <= x && x <= 'Z') ||
        ('a' <= x && x <= 'z'))
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
        if (isDigit(character) && ! isEven(charDigit))
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
