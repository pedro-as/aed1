/**
 * Exemplo0119 - v0.1 - 01/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0119 Exemplo0119.c -lm
 * Windows: gcc -o Exemplo0119.exe Exemplo0119.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0119
 * Windows: Exemplo0119
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
    double r = 0.0; // definir variavel com valor inicial para raio de um circulo
    double area = 0.0; // definir variavel com valor inicial para area de um circulo

    // identificar
    IO_id("Exemplo0119 - Programa = v0.1");

    r = IO_readdouble("Raio do circulo = "); // ler raio
    area = (M_PI * pow((r / 2.0), 2.0)); // calcular area para raio (r/2)

    // mostrar valor da area
    IO_printf("Area do circulo para r/2 (%lf) = %lf\n", (r / 2.0), area);

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
 * a.) 2 => 3.141593
 * b.) 10.5 => 86.590148
 * c.) 120.25 => 11356.907
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      01/04/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       teste lendo raio e calculando area do circulo
 */
