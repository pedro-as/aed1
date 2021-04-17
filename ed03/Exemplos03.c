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
    chars word = IO_new_chars(STR_SIZE);
    chars lower = IO_new_chars(STR_SIZE);
    char currChar;

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
    IO_println("Teste: determinar se caractere e' letra minuscula");
    
    // ler do teclado
    word = IO_readstring("\nEntrar com uma cadeia de caracteres: ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    for (int i = 0; i < strlen(word); i++)
    {
        currChar = word[i];
        if (currChar >= 'a' && currChar <= 'z')
        {
            strncat(lower, &currChar, 1);
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
}

/**
 * Exemplo0312 - Procedimento para contar e mostrar minusculas
 */
void Exemplo0312(char* methodId)
{
    // definir dados
    chars word = IO_new_chars(STR_SIZE);
    chars lower = IO_new_chars(STR_SIZE);
    char currChar;
    int count = 0;

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
    IO_println("Teste: contar e mostrar letras minusculas");
    
    // ler do teclado
    word = IO_readstring("\nEntrar com uma cadeia de caracteres: ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    for (int i = 0; i < strlen(word); i++)
    {
        currChar = word[i];
        if (currChar >= 'a' && currChar <= 'z')
        {
            strncat(lower, &currChar, 1);
            count++;
        }
    }

    IO_println(IO_concat("Original: ", word));
    if (strlen(lower) > 0)
    {        
        IO_println(IO_concat("Minusculas: ", lower));
        IO_println(IO_concat("Total: ", IO_toString_d(count)));
    }
    else
    {
        IO_println("Nenhuma minuscula.");
    }
}

/**
 * Exemplo0313 - Procedimento para contar e mostrar minusculas em ordem inversa
 */
void Exemplo0313(char* methodId)
{
    // definir dados
    chars word = IO_new_chars(STR_SIZE);
    chars lower = IO_new_chars(STR_SIZE);
    char currChar;
    int count = 0;

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
    IO_println("Teste: contar e mostrar letras minusculas em ordem inversa");
    
    // ler do teclado
    word = IO_readstring("\nEntrar com uma cadeia de caracteres: ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    for (int i = strlen(word) - 1; i >= 0; i--)
    {
        currChar = word[i];
        if (currChar >= 'a' && currChar <= 'z')
        {
            strncat(lower, &currChar, 1);
            count++;
        }
    }

    IO_println(IO_concat("Original: ", word));
    if (strlen(lower) > 0)
    {        
        IO_println(IO_concat("Minusculas (inverso): ", lower));
        IO_println(IO_concat("Total: ", IO_toString_d(count)));
    }
    else
    {
        IO_println("Nenhuma minuscula.");
    }
}

/**
 * Exemplo0314 - Procedimento para contar e mostrar todas as letras
 * (maiusculas e minusculas)
 */
void Exemplo0314(char* methodId)
{
    // definir dados
    chars word = IO_new_chars(STR_SIZE);
    chars letters = IO_new_chars(STR_SIZE);
    char currChar;
    int count = 0;

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
    IO_println("Teste: contar e mostrar todas as letras");
    
    // ler do teclado
    word = IO_readstring("\nEntrar com uma cadeia de caracteres: ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    for (int i = 0; i < strlen(word); i++)
    {
        currChar = word[i];
        if ((currChar >= 'a' && currChar <= 'z') ||
            (currChar >= 'A' && currChar <= 'Z'))
        {
            strncat(letters, &currChar, 1);
            count++;
        }
    }

    IO_println(IO_concat("Original: ", word));
    if (strlen(letters) > 0)
    {        
        IO_println(IO_concat("Letras (inverso): ", letters));
        IO_println(IO_concat("Total: ", IO_toString_d(count)));
    }
    else
    {
        IO_println("Nenhuma letra.");
    }
}

/**
 * Exemplo0315 - Procedimento para contar e mostrar todas as letras
 * (maiusculas e minusculas) em ordem inversa
 */
void Exemplo0315(char* methodId)
{
    // definir dados
    chars word = IO_new_chars(STR_SIZE);
    chars letters = IO_new_chars(STR_SIZE);
    char currChar;
    int count = 0;

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
    IO_println("Teste: contar e mostrar todas as letras em ordem inversa");
    
    // ler do teclado
    word = IO_readstring("\nEntrar com uma cadeia de caracteres: ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    for (int i = strlen(word) - 1; i >= 0; i--)
    {
        currChar = word[i];
        if ((currChar >= 'a' && currChar <= 'z') ||
            (currChar >= 'A' && currChar <= 'Z'))
        {
            strncat(letters, &currChar, 1);
            count++;
        }
    }

    IO_println(IO_concat("Original: ", word));
    if (strlen(letters) > 0)
    {        
        IO_println(IO_concat("Letras: ", letters));
        IO_println(IO_concat("Total: ", IO_toString_d(count)));
    }
    else
    {
        IO_println("Nenhuma letra.");
    }
}

/**
 * Exemplo0316 - Procedimento para contar e mostrar tudo o que nao for
 * digito ou letra
 */
void Exemplo0316(char* methodId)
{
    // definir dados
    chars word = IO_new_chars(STR_SIZE);
    chars symbols = IO_new_chars(STR_SIZE);
    char currChar;
    int count = 0;

    // exibir identificacao
    decorateMethod(PROGRAM_ID, methodId);
    IO_println("Teste: contar e mostrar tudo o que nao for digito ou letra");
    
    // ler do teclado
    word = IO_readstring("\nEntrar com uma cadeia de caracteres: ");
    IO_println(""); // inserir nova linha antes de exibir resultado

    for (int i = 0; i < strlen(word); i++)
    {
        currChar = word[i];
        if (!(currChar >= 'a' && currChar <= 'z') &&
            !(currChar >= 'A' && currChar <= 'Z') &&
            !(currChar >= '0' && currChar <= '9'))
        {
            strncat(symbols, &currChar, 1);
            count++;
        }
    }

    IO_println(IO_concat("Original: ", word));
    if (strlen(symbols) > 0)
    {        
        IO_println(IO_concat("Simbolos: ", symbols));
        IO_println(IO_concat("Total: ", IO_toString_d(count)));
    }
    else
    {
        IO_println("Nenhum simbolo exceto digitos ou letras.");
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
    IO_id("=        Exemplos03 - Programa = v0.1       =");
    

    // definir dado
    int option = 0; // inicializar variavel para selecionar opcao

    // exibir opcoes
    IO_println("Escolha uma das acoes a seguir para executar:\n");
    IO_println("[0] Encerrar programa");
    IO_println("[1] Exemplo 0311");
    IO_println("[2] Exemplo 0312");
    IO_println("[3] Exemplo 0313");
    IO_println("[4] Exemplo 0314");
    IO_println("[5] Exemplo 0315");
    IO_println("[6] Exemplo 0316");
    IO_println("[7] Exemplo 0317");
    IO_println("[8] Exemplo 0318");
    IO_println("[9] Exemplo 0319");
    IO_println("[10] Exemplo 0320");
    IO_println("[11] Exemplo 03E1");
    IO_println("[12] Exemplo 03E2");

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
        break;/*
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
        break;*/
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
 *  0.1      16/04/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       teste geral
 */
