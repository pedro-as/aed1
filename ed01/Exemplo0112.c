/**
 * Exemplo0112 - v0.1 - 01/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0112 Exemplo0112.c -lm
 * Windows: gcc -o Exemplo0112.exe Exemplo0112.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0112
 * Windows: Exemplo0112
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
    int lado = 0; // definir variavel com valor inicial para o lado do quadrado
    double lado_metade = 0.0; // definir variavel com valor inicial para metado do lado do quadrado
    double area_metade = 0.0; // definir variavel com valor inicial para area do quadrado
    double perim_metade = 0.0; // definir variavel com valor inicial para perimetro do quadrado

    // identificar
    IO_id("Exemplo0112 - Programa = v0.1");

    lado = IO_readint("Lado do quadrado = ");
    lado_metade = lado / 2.0; // calcular metade do lado
    area_metade = pow(lado_metade, 2.0); // calcular area para lado/2
    perim_metade = (lado_metade * 4.0); // calcular perimetro para lado/2

    IO_printf("Metade do lado = %.1lf \n", lado_metade);
    IO_printf("Area para lado (%.1lf) = %.4lf \n", lado_metade, area_metade);
    IO_printf("Perimetro para lado (%.1lf) = %.4lf \n", lado_metade, perim_metade);

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
 * a.) 2 => 1.0, 1.0000, 4.0000
 * b.) 3 => 1.5, 2.2500, 6.0000
 * c.) 9 => 4.5, 20.2500, 18.0000
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      01/04/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       teste lendo lado e calculando area e perimetro de (lado/2)
 */
