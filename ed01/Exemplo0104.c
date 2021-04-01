/**
 * Exemplo0104 - v0.1 - 30/03/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0104 Exemplo0104.c
 * Windows: gcc -o Exemplo0104.exe Exemplo0104.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0104
 * Windows: Exemplo0104
*/

// dependencias
#include <stdio.h>   // para entradas e saidas
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
    bool x = false; // definir variavel com valor inicial

    // identificar
    printf("%s\n", "Exemplo0104 - Programa = v0.1");
    printf("%s\n", "Autor: Pedro Henrique Amorim Sa");
    printf("\n");
    printf("\n");

    // mudar de linha
    // mostrar valor inicial
    printf ("%s%d\n", "x = ", x);
    // ler do teclado
    printf("Entrar com um valor logico: ");
    scanf("%d", &x);
    x=x!=0; // para restringir valor a 0 e 1
           // OBS.: Usar o equivalente inteiro -> 0 = false
    // mostrar valor lido
    printf ("%s%d\n", "x = ", x);
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
 * a.) input: 1 => output: 1
 * b.) input: 0 => output: 0
 * c.) input: true => output: 0 (com lixo)
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      30/03/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       identificacao de programa
 *                         leitura e exibicao de valores logicos
 */
