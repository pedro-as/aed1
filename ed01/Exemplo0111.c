/**
 * Exemplo0111 - v0.1 - 30/03/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0111 Exemplo0111.c -lm
 * Windows: gcc -o Exemplo0111.exe Exemplo0111.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0111
 * Windows: Exemplo0111
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
    int lado_i = 0; // definir variavel com valor inicial para o lado do quadrado
    double lado_f = 0.0; // definir variavel com valor inicial para converter lado em real
    double area = 0.0; // definir variavel com valor inicial para area do quadrado
    double area_q = 0.0; // definir variavel com valor inicial para 1/4 da area do quadrado

    // identificar
    IO_id("Exemplo0111 - Programa = v0.1");

    lado_i = IO_readint("Lado do quadrado = ");
    lado_f = (double) lado_i; // converter lado em real
    area = pow(lado_f, 2.0); // calcular area
    area_q = (area / 4.0); // calcular 1/4 de area

    IO_printf("1/4 da area (%.0lf) de um quadrado de lado (%d) = %.4lf\n", area, lado_i, area_q);

    // encerrar
    IO_pause("\n\nApertar ENTER para terminar.");
    
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
 * a.) 2 => 1.0
 * b.) 3 => 2.25
 * c.) 9 => 20.25
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      30/03/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       teste lendo lado e calculando area e 1/4 de area
 */
