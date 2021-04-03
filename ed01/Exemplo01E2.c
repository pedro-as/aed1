/**
 * Exemplo01E2 - v0.1 - 01/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo01E2 Exemplo01E2.c -lm
 * Windows: gcc -o Exemplo01E2.exe Exemplo01E2.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo01E2
 * Windows: Exemplo01E2
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
    double v = 0.0; // definir variavel com valor inicial para volume de esfera
    double r = 0.0; // definir variavel com valor inicial para raio
    double area = 0.0; // definir variavel com valor inicial para area
    double v_m = 0.0; // definir variavel com valor inicial para v/2

    // identificar
    IO_id("Exemplo01E2 - Programa = v0.1");

    v = IO_readdouble("Volume da esfera = "); // ler volume
    v_m = (v / 2.0); // calcular metade do volume informado
    r = (cbrt((3.0 * v_m) / (4.0 * M_PI))); // calcular raio
    area = (4.0 * M_PI * pow(r, 2.0)); // calcular area

    // mostrar valor do raio
    IO_printf("Raio de volume / 2 (%lf) = %lf\n", v_m, r);

    // mostrar valor da area
    IO_printf("Area superficial de volume / 2 (%lf) = %lf\n", v_m, area);

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
 * a.) 2 => r=0.620350, area=4.835976
 * b.) 10.5 => r=1.078177, area=14.607985
 * c.) 120.25 => r=2.430275, area=74.219983
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      01/04/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       teste lendo volume e calculando raio
 *                         e area da esfera (p/ v/2)
 */
