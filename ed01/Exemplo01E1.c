/**
 * Exemplo01E1 - v0.1 - 01/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo01E1 Exemplo01E1.c -lm
 * Windows: gcc -o Exemplo01E1.exe Exemplo01E1.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo01E1
 * Windows: Exemplo01E1
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
    double area = 0.0; // definir variavel com valor inicial para area de circunferencia
    double r = 0.0; // definir variavel com valor inicial para raio

    // identificar
    IO_id("Exemplo01E1 - Programa = v0.1");

    area = IO_readdouble("Area da circunferencia = "); // ler area
    r = (sqrt(area * 2 / M_PI)); // calcular raio de area * 2

    // mostrar valor do volume
    IO_printf("Raio de area * 2 (%lf) = %lf\n", area * 2, r);

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
 * a.) 2 => 1.128379
 * b.) 10.5 => 2.585441
 * c.) 120.25 => 8.749487
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      01/04/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       teste lendo area e calculando raio de area * 2
 */
