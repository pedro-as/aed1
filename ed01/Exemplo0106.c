/**
 * Exemplo0106 - v0.1 - 30/03/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0106 Exemplo0106.c
 * Windows: gcc -o Exemplo0106.exe Exemplo0106.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0106
 * Windows: Exemplo0106
*/

// dependencias
#include <stdio.h>   // para entradas e saidas
#include <string.h>
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
    int x = 0; // definir variavel com valor inicial
    int y = 0; // definir variavel com valor inicial
    int z = 0; // definir variavel com valor inicial

    // identificar
    printf("%s\n", "Exemplo0106 - Programa = v0.1");
    printf("%s\n", "Autor: Pedro Henrique Amorim Sa");
    printf("\n");
    printf("\n");

    // mostrar valores iniciais
    printf ("%s%d\n", "x = ", x);
    printf ("%s%i\n", "y = ", y);
    
    // ler do teclado
    printf("Entrar com um valor inteiro: ");
    scanf("%d", &x);
    printf("Entrar com um valor inteiro: ");
    scanf("%i", &y);

    // operar valores
    z = x * y; // guardar em z o produto de x por y

    // mostrar valor resultante
    printf ("%s(%i)*(%i) = (%d)\n", "z = ", x, y, z);
    
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
 * a.) input: 3 e 5 => output: 15
 * b.) input: -3 e 5 => output: -15
 * c.) input: -3 e -5 => output: 15
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      30/03/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       identificacao de programa
 *                         leitura e exibicao de produto de dois inteiros
 */
