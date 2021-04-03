/**
 * Exemplo0120 - v0.1 - 01/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0120 Exemplo0120.c -lm
 * Windows: gcc -o Exemplo0120.exe Exemplo0120.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0120
 * Windows: Exemplo0120
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
    double r = 0.0; // definir variavel com valor inicial para raio de uma esfera
    double r_ = 0.0; // definir variavel com valor inicial para raio = (r*3/8)
    double v = 0.0; // definir variavel com valor inicial para volume de uma esfera

    // identificar
    IO_id("Exemplo0120 - Programa = v0.1");

    r = IO_readdouble("Raio da esfera = "); // ler raio
    r_ = (r * 3 / 8); // calcular 3/8 de r
    v = (4 * M_PI * pow(r_, 3.0) / 3); // calcular volume para r_

    // mostrar valor do volume
    IO_printf("Volume da esfera para 3/8*r (%lf) = %lf\n", r_, v);

    // encerrar
    IO_pause("\nApertar ENTER para terminar.");

    // limpar a entrada de dados
    //fflush (stdin);
    getchar();
    return (0); // voltar ao SO (sem erros)
} // fim main( )

/**
 * ---------------------------------------------- documentacao complementar
 * ---------------------------------------------- notas / observacoes / comentarios
 * ---------------------------------------------- previsao de testes
 * a.) 2 => 1.767146
 * b.) 10.5 => 255.711529
 * c.) 120.25 => 384094.128
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      01/04/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       teste lendo raio e calculando volume da esfera (r=r*3/8)
 */
