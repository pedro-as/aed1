/**
 * Exemplo0117 - v0.1 - 01/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0117 Exemplo0117.c -lm
 * Windows: gcc -o Exemplo0117.exe Exemplo0117.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0117
 * Windows: Exemplo0117
*/

// dependencias
#include <math.h> // para funcoes matematicas
#include "io.h" // para definicoes proprias

// para as entradas e saidas
/**
 * Funcao principal.
 * @return codigo de encerramento
 * @param argc - quantidade de parametros na linha de comandos
 * @param argv - arranjo com o grupo de parametros na linha de comandos
 */
int main(int argc, char* argv[])
{
    // definir dados
    double l = 0.0; // definir variavel com valor inicial para lado do cubo
    double l_q = 0.0; // definir variavel com valor inicial para lado (l*4)
    double v = 0.0; // definir variavel com valor inicial para volume com lado (l*4)

    // identificar
    IO_id("Exemplo0117 - Programa = v0.1");

    l = IO_readdouble("Lado do cubo = "); // ler valor de lado do cubo
    l_q = (l * 4.0); // quadruplicar valor do lado
    v = (pow(l_q, 3.0)); // calcular volume para lado=(l*4)

    // mostrar valor do volume
    IO_printf("Volume para lado * 4 (%lf) = %lf\n", l_q, v);

    // encerrar
    IO_pause("\nApertar ENTER para terminar.");
    
    //fflush (stdin);
    // limpar a entrada de dados
    getchar();
    // getchar();
    return (0); // voltar ao SO (sem erros)
} // fim main( )

/**
 * ---------------------------------------------- documentacao complementar
 * ---------------------------------------------- notas / observacoes / comentarios
 * ---------------------------------------------- previsao de testes
 * a.) 3 => 1728
 * b.) 8.25 => 35937
 * c.) 77.1 => 29332096.704
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      01/04/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       teste lendo lado e calculando volume para (l*4)
 */
