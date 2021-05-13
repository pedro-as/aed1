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

// definir o numero de identificacao do programa
char PROGRAM_ID[2] = "07";

// para as entradas e saidas

void copyText(chars fileOut, chars fileIn)
{
    FILE* saida = fopen(fileOut, "wt");
    FILE* entrada = fopen(fileIn, "rt");
    chars linha = IO_new_chars(STR_SIZE);
    int contador = 0;

    strcpy(linha,IO_freadln(entrada));
    
    while(! feof(entrada))
    {
        contador++;
        
        if (strcmp("PARAR", linha) != 0)
        {
            IO_fprintln(saida, linha);
        }

        strcpy(linha, IO_freadln(entrada));
    }
    IO_printf("Lines read = %d\n", contador);
    fclose(saida);
    fclose(entrada);
}

void method01(int methodId)
{
    decorateMethod(methodId);
    copyText("out.txt", "test.txt");
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
    decorateMenu(1);

    do
    {
        // ler opcao do teclado
        option = IO_readint("\n\nOpcao [1:12] >> ");

        // selecionar opcao
        switch (option)
        {
            case 0:
                IO_clrscr();
                IO_println("\nEncerrando programa...");
                break;
            case 1:
                method01(option);
                break;/*
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
                break;*/
            default:
                IO_clrscr();
                IO_println(IO_concat("\nComando '", IO_concat(IO_toString_d(option),
                                    "' nao encontrado.")));
                break;
        }
    }
    while (option != 0);

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
 *  0.1      13/05/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 */
