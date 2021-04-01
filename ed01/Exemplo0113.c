/**
 * Exemplo0113 - v0.1 - 01/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0113 Exemplo0113.c -lm
 * Windows: gcc -o Exemplo0113.exe Exemplo0113.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0113
 * Windows: Exemplo0113
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
    int h = 0; // definir variavel com valor inicial para altura do retangulo
    int b = 0; // definir variavel com valor inicial para base do retangulo
    long area = 0; // definir variavel com valor inicial para area do retangulo
    long triplo_area = 0; // definir variavel com valor inicial para triplo da area do retangulo

    // identificar
    IO_id("Exemplo0113 - Programa = v0.1");

    h = IO_readint("Altura do retangulo = "); // ler altura
    b = IO_readint("Base do retangulo = "); // ler base
    area = (h * b); // calcular area
    triplo_area = (area * 3); // calcular triplo da area

    // mostrar valor da area * 3
    IO_printf("Triplo da area (%li) = %li\n", area, triplo_area);

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
 * a.) 2 e 3 => 18
 * b.) 50 e 90 => 13500
 * c.) 1600 e 2450 => 11760000
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      01/04/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       teste lendo lado e calculando triplo da area
 */
