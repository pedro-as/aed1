/**
 * Exemplo0108 - v0.1 - 30/03/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0108 Exemplo0108.c -lm
 * Windows: gcc -o Exemplo0108.exe Exemplo0108.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0108
 * Windows: Exemplo0108
*/

// dependencias
#include <stdio.h>   // para entradas e saidas
#include <string.h> // para cadeia de caracteres
#include <math.h> // para funcoes matematicas
#include "stdbool.h" // para valores logicos, com biblioteca adaptada

// para as entradas e saidas
/**
 * Funcao principal.
 * @return codigo de encerramento
 * @param argc - quantidade de parametros na linha de comandos
 * @param argv - arranjo com o grupo de parametros na linha de comandos
 */
int main(int argc, char* argv[])
{
    // definir dado
    char x[] = "abc"; // definir variavel com valor inicial
    char y[] = "def"; // definir variavel com valor inicial
    char z [80];      // definir variavel com valor inicial
    stpcpy(z, "");    // copiar para (z) a representacao de vazio

    // identificar
    printf("%s\n", "Exemplo0108 - Programa = v0.1");
    printf("%s\n", "Autor: Pedro Henrique Amorim Sa");
    printf("\n");
    printf("\n");

    // mostrar valores iniciais
    printf ("%s%s (%ld)\n", "x = ", x, strlen(x));
    printf ("%s%s (%ld)\n", "y = ", y, strlen(y));
    
    // ler do teclado
    printf("Entrar com caracteres: ");
    scanf("%s", x);
    printf("Entrar com outros caracteres: ");
    scanf("%s", y);

    // operar valores
    strcpy(z, x); // copiar (x) para (z)
    strcat(z, y); // concatenar (y) a (z)
                  // OBS: forma mais eficiente

    // mostrar valor resultante
    printf ("%s[%s]*[%s] = [%s]\n", "z = ", x, y, z);
    
    // encerrar
    printf ("\n\nApertar ENTER para terminar.");
    
    //fflush (stdin);
    // limpar a entrada de dados
    getchar();
    getchar(); // aguardar por ENTER
    return (0); // voltar ao SO (sem erros)
} // fim main( )

/**
 * ---------------------------------------------- documentacao complementar
 * ---------------------------------------------- notas / observacoes / comentarios
 * ---------------------------------------------- previsao de testes
 * a.) input: 12 e 24 => output: 1224
 * b.) input: ab e cd => output: abcd
 * c.) input: a e bc => output: abc
 * d.) input: ab e c => output: abc
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      30/03/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       identificacao de programa
 *                         leitura e concatenacao de caracteres
 */
