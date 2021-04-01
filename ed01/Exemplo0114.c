/**
 * Exemplo0114 - v0.1 - 01/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0114 Exemplo0114.c -lm
 * Windows: gcc -o Exemplo0114.exe Exemplo0114.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0114
 * Windows: Exemplo0114
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
    double h_t = 0.0; // definir variavel com valor inicial para 1/3 da altura do retangulo
    double b_t = 0.0; // definir variavel com valor inicial para 1/3 da base do retangulo
    double area_t = 0.0; // definir variavel com valor inicial para area de 1/3 do tamanho dos lados
    double perim_t = 0.0; // definir variavel com valor inicial para perimetro de 1/3 do tamanho dos lados

    // identificar
    IO_id("Exemplo0114 - Programa = v0.1");

    h = IO_readint("Altura do retangulo = "); // ler altura
    b = IO_readint("Base do retangulo = "); // ler base
    h_t = (h / 3.0); // calcular 1/3 da altura
    b_t = (b / 3.0); // calcular 1/3 da base
    area_t = (h_t * b_t); // calcular area
    perim_t = ((h_t * 2.0) + (b_t * 2.0)); // calcular perimetro

    // mostrar valor da area * 3
    IO_printf("Area para (h/3) (%lf) e (b/3) (%lf) = %lf\n", h_t, b_t, area_t);
    IO_printf("Perimetro para (h/3) (%lf) e (b/3) (%lf) = %lf\n", h_t, b_t, perim_t);

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
 * a.) 2 e 3 => 0.666667, 3.333333
 * b.) 50 e 90 => 500.000000, 93.333333
 * c.) 1600 e 2450 => 435555.555556, 2700.000000
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      01/04/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       teste lendo lado e calculando area e perimetro de (lados/3)
 */
