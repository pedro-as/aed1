/**
 * Exemplo0107 - v0.1 - 30/03/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0107 Exemplo0107.c
 * Windows: gcc -o Exemplo0107.exe Exemplo0107.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0107
 * Windows: Exemplo0107
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
    double x = 0.0; // definir variavel com valor inicial
    double y = 0.0; // definir variavel com valor inicial
    double z = 0.0; // definir variavel com valor inicial

    // identificar
    printf("%s\n", "Exemplo0107 - Programa = v0.1");
    printf("%s\n", "Autor: Pedro Henrique Amorim Sa");
    printf("\n");
    printf("\n");

    // mostrar valores iniciais
    printf ("%s%lf\n", "x = ", x);
    printf ("%s%lf\n", "y = ", y);
    
    // ler do teclado
    printf("Entrar com um valor inteiro: ");
    scanf("%lf", &x);
    printf("Entrar com um valor inteiro: ");
    scanf("%lf", &y);

    // operar valores
    z = pow(x, y); // elevar a base (x) 'a potencia (y)

    // mostrar valor resultante
    printf ("%s(%lf)**(%lf) = (%lf)\n", "z = ", x, y, z);
    
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
 * a.) input: 2.0 e 3.0 => output: 8.000000
 * b.) input: 3.0 e 2.0 => output: 9.000000
 * c.) input: -3.0 e 2.0 => output: 9.000000
 * d.) input: -2.0 e -3.0 => output: -0.125000
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      30/03/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       identificacao de programa
 *                         leitura e exibicao de potencia
 */
