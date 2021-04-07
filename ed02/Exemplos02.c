/**
 * Exemplos02 - v0.2 - 07/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplos02 Exemplos02.c
 * Windows: gcc -o Exemplos02.exe Exemplos02.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplos02
 * Windows: Exemplos02
 */

// dependencias
#include "io.h" // para definicoes proprias

// para as entradas e saidas

/**
 * Exemplo0211 - Procedimento para testar se numero inteiro e' par ou impar
 */
void Exemplo0211()
{
    // definir dado com valor inicial
    int a = 0;

    // exibir identificacao
    IO_clrscr();
    IO_println("*****************");
    IO_println("** Exemplo0211 **");
    IO_println("*****************");
    IO_println("Teste: VALOR par ou impar");
    
    // ler dado do usuario
    a = IO_readint("\nEntrar com VALOR (inteiro): ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    // testar se o numero informado tem resto 0 em uma divisao por 2
    if (a % 2 == 0)    
    {
        IO_println(IO_concat(IO_toString_d(a), " e' PAR."));
    }
    else
    {
        IO_println(IO_concat(IO_toString_d(a), " e' IMPAR."));
    }
}

/**
 * Exemplo0212 - Procedimento para testar se o valor e' par e maior que -100
 * ou impar e menor que 100
 */
void Exemplo0212()
{
    // definir dado com valor inicial
    int a = 0;

    // exibir identificacao
    IO_clrscr();
    IO_println("*****************");
    IO_println("** Exemplo0212 **");
    IO_println("*****************");
    IO_println("Teste: VALOR par e maior que -100 ou impar e menor que 100");
    
    // ler dado do usuario
    a = IO_readint("\nEntrar com VALOR (inteiro): ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    if (a % 2 == 0 && a > -100)
    {
        IO_println(IO_concat(IO_toString_d(a), " e' PAR e maior que -100."));
    }
    else if (a % 2 != 0 && a < 100)
    {
        IO_println(IO_concat(IO_toString_d(a), " e' IMPAR e menor que 100."));
    }
    else
    {
        IO_println(IO_concat(IO_toString_d(a), " nao obedece aos criterios."));
    }
}

/**
 * Exemplo0213 - Procedimento para testar se o valor pertence
 * ao intervalo (25, 60)
 */
void Exemplo0213()
{
    // definir dado com valor inicial
    int a = 0;

    // exibir identificacao
    IO_clrscr();
    IO_println("*****************");
    IO_println("** Exemplo0213 **");
    IO_println("*****************");
    IO_println("Teste: VALOR pertence ao intervalo (25, 60)");
    
    // ler dado do usuario
    a = IO_readint("\nEntrar com VALOR (inteiro): ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    if (a > 25 && a < 60)
    {
        IO_println(IO_concat(IO_toString_d(a),
                             " pertence ao intervalo (25, 60)."));
    }
    else
    {
        IO_println(IO_concat(IO_toString_d(a),
                             " NAO pertence ao intervalo (25, 60)."));
    }
}

/**
 * Exemplo0214 - Procedimento para testar se o valor pertence
 * ao intervalo [25, 60]
 */
void Exemplo0214()
{
    // definir dado com valor inicial
    int a = 0;

    // exibir identificacao
    IO_clrscr();
    IO_println("*****************");
    IO_println("** Exemplo0214 **");
    IO_println("*****************");
    IO_println("Teste: VALOR pertence ao intervalo [25, 60]");
    
    // ler dado do usuario
    a = IO_readint("\nEntrar com VALOR (inteiro): ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    if (a >= 25 && a <= 60)
    {
        IO_println(IO_concat(IO_toString_d(a),
                             " pertence ao intervalo [25, 60]."));
    }
    else
    {
        IO_println(IO_concat(IO_toString_d(a),
                             " NAO pertence ao intervalo [25, 60]."));
    }
}

/**
 * Exemplo0215 - Procedimento para testar se o valor
 * pertence aos intervalos [20, 75] e/ou [33, 55]
 */
void Exemplo0215()
{
    // definir dado com valor inicial
    int a = 0;

    // exibir identificacao
    IO_clrscr();
    IO_println("*****************");
    IO_println("** Exemplo0215 **");
    IO_println("*****************");
    IO_println("Teste: VALOR pertence aos intervalos [20, 75] e/ou [33, 55]");
    
    // ler dado do usuario
    a = IO_readint("\nEntrar com VALOR (inteiro): ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    // 
    if (a >= 20 && a <= 75)
    {
        if (a >= 33 & a <= 55)
        {
            IO_println(IO_concat(IO_toString_d(a),
                             " pertence a ambos os intervalos."));
        }
        else
        {
            IO_println(IO_concat(IO_toString_d(a),
                             " pertence somente ao intervalo [20, 75]."));
        }
    }
    else
    {
        IO_println(IO_concat(IO_toString_d(a),
                             " nao pertence a nenhum dos intervalos."));
    }
}

/**
 * Exemplo0216 - Procedimento para testar se o primeiro valor e' impar
 * e se o segundo valor e' par
 */
void Exemplo0216()
{
    // definir dados com valor inicial
    int a = 0;
    int b = 0;

    // exibir identificacao
    IO_clrscr();
    IO_println("*****************");
    IO_println("** Exemplo0216 **");
    IO_println("*****************");
    IO_println("Teste: VALOR_1 impar e VALOR_2 par");
    
    // ler dado do usuario
    a = IO_readint("\nEntrar com VALOR_1 (inteiro): ");
    b = IO_readint("Entrar com VALOR_2 (inteiro): ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    if (a % 2 != 0 && b % 2 == 0)
    {
        IO_print(IO_concat(IO_toString_d(a), " e' IMPAR e "));
        IO_println(IO_concat(IO_toString_d(b), " e' PAR "));
    }
    else
    {
        IO_printf("\nPelo menos um dos valores informados");
        IO_println(" nao obedece aos criterios");
    }
}

/**
 * Exemplo0217 - Procedimento para testar se o primeiro valor e' par e negativo
 * e se o segundo valor e' impar e positivo
 */
void Exemplo0217()
{
    // definir dados com valor inicial
    int a = 0;
    int b = 0;

    // exibir identificacao
    IO_clrscr();
    IO_println("*****************");
    IO_println("** Exemplo0217 **");
    IO_println("*****************");
    IO_println("Teste: VALOR_1 par e negativo e VALOR_2 impar e positivo");
    
    // ler dado do usuario
    a = IO_readint("\nEntrar com VALOR_1 (inteiro): ");
    b = IO_readint("Entrar com VALOR_2 (inteiro): ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    if ((a % 2 == 0 && a < 0) && (b % 2 != 0 && b > 0))
    {
        IO_print(IO_concat(IO_toString_d(a), " e' IMPAR e "));
        IO_println(IO_concat(IO_toString_d(b), " e' PAR "));
    }
    else
    {
        IO_printf("\nPelo menos um dos valores informados");
        IO_println(" nao obedece aos criterios");
    }
}

/**
 * Exemplo0218 - Procedimento para testar se primeiro valor e'
 * igual, maior ou menor que segundo valor
 */
void Exemplo0218()
{
    // definir dados com valor inicial
    double a = 0.0;
    double b = 0.0;

    // exibir identificacao
    IO_clrscr();
    IO_println("*****************");
    IO_println("** Exemplo0218 **");
    IO_println("*****************");
    IO_println("Teste: VALOR_1 igual, maior ou menor que VALOR_2");
    
    // ler dado do usuario
    a = IO_readdouble("\nEntrar com VALOR_1 (real): ");
    b = IO_readdouble("Entrar com VALOR_2 (real): ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    if (a == b)
    {
        IO_print(IO_concat(IO_toString_f(a), " e' igual a "));
        IO_println(IO_toString_f(b));
    }
    else if (a > b)
    {
        IO_print(IO_concat(IO_toString_f(a), " e' maior que "));
        IO_println(IO_toString_f(b));
    }
    else
    {
        IO_print(IO_concat(IO_toString_f(a), " e' menor que "));
        IO_println(IO_toString_f(b));
    }
}

/**
 * Exemplo0219 - Procedimento para testar se o primeiro valor esta' entre
 * os outros dois, quando estes forem diferentes entre si
 */
void Exemplo0219()
{
    // definir dados com valor inicial
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    // exibir identificacao
    IO_clrscr();
    IO_println("*****************");
    IO_println("** Exemplo0219 **");
    IO_println("*****************");
    IO_println("Teste: VALOR_1 esta' entre VALOR_2 e VALOR_3");
    
    // ler dados do usuario
    a = IO_readdouble("\nEntrar com VALOR_1 (real): ");
    b = IO_readdouble("Entrar com VALOR_2 (real): ");
    c = IO_readdouble("Entrar com VALOR_3 (real): ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    if (b == c)
    {
        IO_println("O segundo e o terceiro valor sao iguais.");
    }
    else
    {
        if ((b < a && a < c) || (c < a && a < b))
        {
            if (b < c)
            {
                IO_print(IO_concat(IO_toString_f(a), " esta' entre "));
                IO_print(IO_toString_f(b));
                IO_println(IO_concat(" e ", IO_toString_f(c)));
            }
            else
            {
                IO_print(IO_concat(IO_toString_f(a), " esta' entre "));
                IO_print(IO_toString_f(c));
                IO_println(IO_concat(" e ", IO_toString_f(b)));
            }
        }
        else
        {
            IO_println("Condicoes de teste nao satisfeitas.");
        }
    }
}

/**
 * Exemplo0220 - Procedimento para testar se o primeiro valor nao esta' entre
 * os outros dois, quando todos forem diferentes entre si
 */
void Exemplo0220()
{
    // definir dados com valor inicial
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    // exibir identificacao
    IO_clrscr();
    IO_println("*****************");
    IO_println("** Exemplo0220 **");
    IO_println("*****************");
    IO_println("Teste: VALOR_1 NAO esta' entre VALOR_2 e VALOR_3");
    
    // ler dados do usuario
    a = IO_readdouble("\nEntrar com VALOR_1 (real): ");
    b = IO_readdouble("Entrar com VALOR_2 (real): ");
    c = IO_readdouble("Entrar com VALOR_3 (real): ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    if (a == b || a == c || b == c) 
    {
        IO_println("Pelo menos dois valores sao iguais.");
    }
    else
    {
        if (!(b < a && a < c) && !(c < a && a < b))
        {
            if (b < c)
            {
                IO_print(IO_concat(IO_toString_f(a), " nao esta' entre "));
                IO_print(IO_toString_f(b));
                IO_println(IO_concat(" e ", IO_toString_f(c)));
            }
            else
            {
            IO_print(IO_concat(IO_toString_f(a), " nao esta' entre "));
            IO_print(IO_toString_f(c));
            IO_println(IO_concat(" e ", IO_toString_f(b)));
            }
        }
        else
        {
            IO_println("Condicoes de teste nao satisfeitas.");
        }
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
    IO_id("=        Exemplos02 - Programa = v0.1       =");
    

    // definir dado
    int option = 0; // inicializar variavel para selecionar opcao

    // exibir opcoes
    IO_println("Escolha uma das acoes a seguir para executar:\n");
    IO_println("[0] Encerrar programa");
    IO_println("[1] Exemplo 0211");
    IO_println("[2] Exemplo 0212");
    IO_println("[3] Exemplo 0213");
    IO_println("[4] Exemplo 0214");
    IO_println("[5] Exemplo 0215");
    IO_println("[6] Exemplo 0216");
    IO_println("[7] Exemplo 0217");
    IO_println("[8] Exemplo 0218");
    IO_println("[9] Exemplo 0219");
    IO_println("[10] Exemplo 0220");

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
        Exemplo0211();
        break;
    case 2:
        Exemplo0212();
        break;
    case 3:
        Exemplo0213();
        break;
    case 4:
        Exemplo0214();
        break;
    case 5:
        Exemplo0215();
        break;
    case 6:
        Exemplo0216();
        break;
    case 7:
        Exemplo0217();
        break;
    case 8:
        Exemplo0218();
        break;
    case 9:
        Exemplo0219();
        break;
    case 10:
        Exemplo0220();
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
 *  0.1      06/04/21        esboco
 *  0.2      07/04/21   aperfeicoar formatacao
 *                      e procedimentos
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       testes geral do menu e dos procedimentos
 *  0.2     01. (OK)       teste do procedimento Exemplo0211
 *          02. (OK)       teste do procedimento Exemplo0212
 *          03. (OK)       teste do procedimento Exemplo0213
 *          04. (OK)       teste do procedimento Exemplo0214
 *          05. (OK)       teste do procedimento Exemplo0215
 *          06. (OK)       teste do procedimento Exemplo0216
 *          07. (OK)       teste do procedimento Exemplo0217
 *          08. (OK)       teste do procedimento Exemplo0218
 *          09. (OK)       teste do procedimento Exemplo0219
 *          10. (OK)       teste do procedimento Exemplo0220
 *          11. (OK)       teste de encerramento do programa
 *          12. (OK)       teste de opcao invalida
 */
