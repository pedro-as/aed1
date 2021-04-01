/**
 * Exemplo0115 - v0.1 - 01/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0115 Exemplo0115.c -lm
 * Windows: gcc -o Exemplo0115.exe Exemplo0115.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0115
 * Windows: Exemplo0115
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
    double h = 0.0; // definir variavel com valor inicial para base do triangulo
    double b = 0.0; // definir variavel com valor inicial para base do triangulo
    double area_hd = 0.0; // definir variavel com valor inicial para area com altura (h * 2)

    // identificar
    IO_id("Exemplo0115 - Programa = v0.1");

    h = IO_readdouble("Altura do triangulo = "); // ler altura
    b = IO_readdouble("Base do triangulo = "); // ler base
    area_hd = (b * h); // calcular area do triangulo para altura (h * 2)
                       // OBS.: a formula (b * (h * 2) / 2) pode ser
                       // simplificada para (b * h)

    // mostrar valor da area
    IO_printf("Area para (b) e (h * 2) = %lf\n", area_hd);

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
 * a.) 2 e 3 => 6.000000
 * b.) 10.5 e 8.25 => 86.625000
 * c.) 120.25 e 77.1 => 9271.275000
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      01/04/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       teste lendo lado e calculando area para (h * 2)
 */
