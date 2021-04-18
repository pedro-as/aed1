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
const char* PROGRAM_ID = "03";

// para as entradas e saidas

/**
 * Exemplo0311 - Procedimento para determinar se caractere e' letra minuscula
 */
void Exemplo0311(char* methodId)
{
    // definir dados
    chars word = IO_new_chars(STR_SIZE);  // cadeia de caracteres do usuario
    chars lower = IO_new_chars(STR_SIZE); // valores validos do teste
    char testChar;                        // caractere individual a testar

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
    IO_println("Teste: determinar se caractere e' letra minuscula");

    // ler do teclado
    word = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    for (int i = 0; i < strlen(word); i++)
    {
        // iterar por toda a cadeia de caracteres
        // definindo valor de acordo com a posicao atual
        testChar = word[i];

        if (testChar >= 'a' && testChar <= 'z')
        {
            // concatenar caractere 'a variavel lower se
            // satisfeitas as condicoes
            strncat(lower, &testChar, 1);
        }
    }

    IO_println(IO_concat("Original: ", word)); // mostrar original

    // mostrar resultado
    if (strlen(lower) > 0)
    {
        IO_println(IO_concat("Minusculas: ", lower));
    }
    else
    {
        IO_println("Nenhuma minuscula.");
    }
}

/**
 * Exemplo0312 - Procedimento para contar e mostrar minusculas
 */
void Exemplo0312(char* methodId)
{
    // definir dados
    chars word = IO_new_chars(STR_SIZE);  // cadeia de caracteres do usuario
    chars lower = IO_new_chars(STR_SIZE); // valores validos do teste
    char testChar;                        // caractere individual a testar
    int count = 0;                        // contagem de valores validos

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
    IO_println("Teste: contar e mostrar letras minusculas");

    // ler do teclado
    word = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    for (int i = 0; i < strlen(word); i++)
    {
        testChar = word[i];
        if (testChar >= 'a' && testChar <= 'z')
        {
            strncat(lower, &testChar, 1);
            count++;
        }
    }

    IO_println(IO_concat("Original: ", word));
    if (strlen(lower) > 0)
    {
        IO_println(IO_concat("Minusculas: ", lower));
    }
    else
    {
        IO_println("Nenhuma minuscula.");
    }
    IO_println(IO_concat("Total: ", IO_toString_d(count)));
}

/**
 * Exemplo0313 - Procedimento para contar e mostrar minusculas em ordem inversa
 */
void Exemplo0313(char* methodId)
{
    // definir dados
    chars word = IO_new_chars(STR_SIZE);  // cadeia de caracteres do usuario
    chars lower = IO_new_chars(STR_SIZE); // valores validos do teste
    char testChar;                        // caractere individual a testar
    int count = 0;                        // contagem de valores validos

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
    IO_println("Teste: contar e mostrar letras minusculas em ordem inversa");

    // ler do teclado
    word = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    for (int i = strlen(word) - 1; i >= 0; i--)
    {
        testChar = word[i];
        if (testChar >= 'a' && testChar <= 'z')
        {
            strncat(lower, &testChar, 1);
            count++;
        }
    }

    IO_println(IO_concat("Original: ", word));
    if (strlen(lower) > 0)
    {
        IO_println(IO_concat("Minusculas (inverso): ", lower));
    }
    else
    {
        IO_println("Nenhuma minuscula.");
    }
    IO_println(IO_concat("Total: ", IO_toString_d(count)));
}

/**
 * Exemplo0314 - Procedimento para contar e mostrar todas as letras
 * (maiusculas e minusculas)
 */
void Exemplo0314(char* methodId)
{
    // definir dados
    chars word = IO_new_chars(STR_SIZE);    // cadeia de caracteres do usuario
    chars letters = IO_new_chars(STR_SIZE); // valores validos do teste
    char testChar;                          // caractere individual a testar
    int count = 0;                          // contagem de valores validos

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
    IO_println("Teste: contar e mostrar todas as letras");

    // ler do teclado
    word = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    for (int i = 0; i < strlen(word); i++)
    {
        testChar = word[i];
        if ((testChar >= 'a' && testChar <= 'z') ||
            (testChar >= 'A' && testChar <= 'Z'))
        {
            strncat(letters, &testChar, 1);
            count++;
        }
    }

    IO_println(IO_concat("Original: ", word));
    if (strlen(letters) > 0)
    {
        IO_println(IO_concat("Letras: ", letters));
    }
    else
    {
        IO_println("Nenhuma letra.");
    }
    IO_println(IO_concat("Total: ", IO_toString_d(count)));
}

/**
 * Exemplo0315 - Procedimento para contar e mostrar todas as letras
 * (maiusculas e minusculas) em ordem inversa
 */
void Exemplo0315(char* methodId)
{
    // definir dados
    chars word = IO_new_chars(STR_SIZE);    // cadeia de caracteres do usuario
    chars letters = IO_new_chars(STR_SIZE); // valores validos do teste
    char testChar;                          // caractere individual a testar
    int count = 0;                          // contagem de valores validos

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
    IO_println("Teste: contar e mostrar todas as letras em ordem inversa");

    // ler do teclado
    word = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    for (int i = strlen(word) - 1; i >= 0; i--)
    {
        testChar = word[i];
        if ((testChar >= 'a' && testChar <= 'z') ||
            (testChar >= 'A' && testChar <= 'Z'))
        {
            strncat(letters, &testChar, 1);
            count++;
        }
    }

    IO_println(IO_concat("Original: ", word));
    if (strlen(letters) > 0)
    {
        IO_println(IO_concat("Letras (inverso): ", letters));
    }
    else
    {
        IO_println("Nenhuma letra.");
    }
    IO_println(IO_concat("Total: ", IO_toString_d(count)));
}

/**
 * Exemplo0316 - Procedimento para contar e mostrar tudo o que nao for
 * digito ou letra
 */
void Exemplo0316(char* methodId)
{
    // definir dados
    chars word = IO_new_chars(STR_SIZE);    // cadeia de caracteres do usuario
    chars symbols = IO_new_chars(STR_SIZE); // valores validos do teste
    char testChar;                          // caractere individual a testar
    int count = 0;                          // contagem de valores validos

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
    IO_println("Teste: contar e mostrar tudo o que nao for digito ou letra");

    // ler do teclado
    word = IO_readstring("\nEntrar com uma cadeia de caracteres >> ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    for (int i = 0; i < strlen(word); i++)
    {
        testChar = word[i];
        if (!(testChar >= 'a' && testChar <= 'z') &&
            !(testChar >= 'A' && testChar <= 'Z') &&
            !(testChar >= '0' && testChar <= '9'))
        {
            strncat(symbols, &testChar, 1);
            count++;
        }
    }

    IO_println(IO_concat("Original: ", word));
    if (strlen(symbols) > 0)
    {
        IO_println(IO_concat("Simbolos: ", symbols));

    }
    else
    {
        IO_println("Nenhum simbolo exceto digitos ou letras.");
    }
    IO_println(IO_concat("Total: ", IO_toString_d(count)));
}

/**
 * Exemplo0317 - Procedimento para testar valores que sejam multiplos de 7
 * em um intervalo definido
 */
void Exemplo0317(char* methodId)
{
    // definir dados
    int start = 0; // limite inferior
    int stop = 0;  // limite superior
    int quant = 0; // quantidade de valores
    int value = 0; // valor para teste
    int count = 0; // contagem de valores validos
    chars valid = IO_new_chars(STR_SIZE); // valores validos

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
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
 * Exemplo0318 - Procedimento para testar valores que sejam multiplos de 7
 * e nao multiplos de 3 em um intervalo definido
 */
void Exemplo0318(char* methodId)
{
    // definir dados
    int start = 0; // limite inferior
    int stop = 0;  // limite superior
    int quant = 0; // quantidade de valores
    int value = 0; // valor para teste
    int count = 0; // contagem de valores validos
    chars valid = IO_new_chars(STR_SIZE); // valores validos

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
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
 * Exemplo0319 - Procedimento para testar valores reais pertencentes a um
 * intervalo definido, com parte inteira impar
 */
void Exemplo0319(char* methodId)
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
    decorateMethod(PROGRAM_ID, methodId);
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
 * Exemplo0320 - Procedimento para testar valores reais com parte fracionaria
 * pertencente a um intervalo definido
 */
void Exemplo0320(char* methodId)
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
    decorateMethod(PROGRAM_ID, methodId);
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
 * Exemplo03E1 - Procedimento para mostrar todos os simbolos nao alfanumericos
 * de uma linha
 */
void Exemplo03E1(char* methodId)
{
    // definir dados
    chars value = IO_new_chars(STR_SIZE); // cadeia de caracteres do usuario
    chars testValue = IO_new_chars(STR_SIZE); // valor para teste
    char testChar; // caractere a testar

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
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
 * Exemplo03E2 - Procedimento para determinar se cadeia de caracteres
 * nao contem letras
 */
void Exemplo03E2(char* methodId)
{
    // definir dados
    chars value = IO_new_chars(STR_SIZE); // cadeia de caracteres do usuario
    char testChar; // caractere a testar
    int control = 0;

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
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
 * @param argc - quantidade de parametros na linha de comandos
 * @param argv - arranjo com o grupo de parametros na linha de comandos
 */
int main(int argc, char* argv[])
{
    // identificar
    IO_clrscr();
    IO_id("=       Exemplos03 - Programa = v0.1       =");


    // definir dado
    int option = 0; // inicializar variavel para selecionar opcao

    // exibir opcoes
    decorateMenu(10, 2, PROGRAM_ID);

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
        Exemplo0311("11");
        break;
    case 2:
        Exemplo0312("12");
        break;
    case 3:
        Exemplo0313("13");
        break;
    case 4:
        Exemplo0314("14");
        break;
    case 5:
        Exemplo0315("15");
        break;
    case 6:
        Exemplo0316("16");
        break;
    case 7:
        Exemplo0317("17");
        break;
    case 8:
        Exemplo0318("18");
        break;
    case 9:
        Exemplo0319("19");
        break;
    case 10:
        Exemplo0320("20");
        break;
    case 11:
        Exemplo03E1("E1");
        break;
    case 12:
        Exemplo03E2("E2");
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
 *          01. (OK)       teste Exemplo0311
 *          02. (OK)       teste Exemplo0312
 *          03. (OK)       teste Exemplo0313
 *          04. (OK)       teste Exemplo0314
 *          05. (OK)       teste Exemplo0315
 *          06. (OK)       teste Exemplo0316
 *          07. (OK)       teste Exemplo0317
 *          08. (OK)       teste Exemplo0318
 *          09. (OK)       teste Exemplo0319
 *          10. (OK)       teste Exemplo0320
 *          11. (OK)       teste Exemplo03E1
 *          12. (OK)       teste Exemplo03E2
 *          13. (OK)       teste opcao invalida
 */
