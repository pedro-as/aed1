/**
 * Exemplo0116 - v0.1 - 01/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0116 Exemplo0116.c -lm
 * Windows: gcc -o Exemplo0116.exe Exemplo0116.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0116
 * Windows: Exemplo0116
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
    double l = 0.0; // definir variavel com valor inicial para lado
    double l_m = 0.0; // definir variavel com valor inicial para (l/2)
    double h = 0.0; // definir variavel com valor inicial para altura com (l/2)
    double area = 0.0; // definir variavel com valor inicial para area com (l/2)
    double perim = 0.0; // definir variavel com valor inicial para perimetro com (l/2)

    // identificar
    IO_id("Exemplo0116 - Programa = v0.1");

    l = IO_readdouble("Lado do triangulo equilatero = "); // ler lado
    l_m = (l / 2.0); // calcular metade de l
    h = (l_m * sqrt(3.0) / 2.0); // calcular altura
    area = (pow(l_m, 2.0) * sqrt(3.0) / 4.0); // calcular area
    perim = (l_m * 3); // calcular perimetro

    // mostrar valor da area
    IO_printf("Altura para (l / 2) = %lf\n", h);
    IO_printf("Area para (l / 2) = %lf\n", area);
    IO_printf("Perimetro para (l / 2) = %lf\n", perim);

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
 * a.) 3 => h=1.29904, A=0.974279, P=4.5
 * b.) 8.25 => h=3.57235, A=7.36798, P=12.375
 * c.) 77.1 => h=33.3853, A=643.501, P=115.65
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      01/04/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       teste lendo lado de triangulo equilatero
                           e calculando altura, area e perimetro
 */
