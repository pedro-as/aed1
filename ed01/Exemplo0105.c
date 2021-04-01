/**
 * Exemplo0105 - v0.1 - 30/03/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0105 Exemplo0105.c
 * Windows: gcc -o Exemplo0105.exe Exemplo0105.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0105
 * Windows: Exemplo0105
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
    char x[] = "abc"; // definir variavel com valor inicial

    // identificar
    printf("%s\n", "Exemplo0105 - Programa = v0.1");
    printf("%s\n", "Autor: Pedro Henrique Amorim Sa");
    printf("\n");
    printf("\n");

    // mudar de linha
    // mostrar valor inicial
    printf ("%s%s\n", "x = ", x);
    // ler do teclado
    printf("Entrar com uma cadeia de caracteres: ");
    scanf("%s", x);
    // mostrar valor lido
    printf ("%s%s\n", "x = ", x);
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
 * o teste (c) resultou na deteccao da vulnerabilidade
 * de stack smashing e a execucao foi abortada
 * ---------------------------------------------- previsao de testes
 * a.) input: "def" => output: "def"
 * b.) input: "d e f" => output: "d" (com lixo)
 * c.) input: "d_e_f" => output: "d_e_f"
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      30/03/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       identificacao de programa
 *                         leitura e exibicao de cadeia de caracteres
 */
