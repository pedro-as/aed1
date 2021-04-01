/**
 * Exemplo0118 - v0.1 - 01/04/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0118 Exemplo0118.c -lm
 * Windows: gcc -o Exemplo0118.exe Exemplo0118.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0118
 * Windows: Exemplo0118
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
    // definir dados correspondentes a um paralelepipedo
    double c = 0.0; // definir variavel com valor inicial para comprimento
    double h = 0.0; // definir variavel com valor inicial para altura
    double l = 0.0; // definir variavel com valor inicial para largura
    double v = 0.0; // definir variavel com valor inicial para volume

    // identificar
    IO_id("Exemplo0118 - Programa = v0.1");

    c = IO_readdouble("Comprimento do paralelepipedo = "); // ler comprimento
    h = IO_readdouble("Altura do paralelepipedo = "); // ler altura
    l = IO_readdouble("Largura do paralelepipedo = "); // ler largura
    v = ((c/5.0) * (h/5.0) * (l/5.0)); // calcular volume para 1/5 dos valores

    // mostrar valor do volume
    IO_printf("Volume para (%lf) * (%lf) * (%lf) = %lf\n",
              (c/5.0), (h/5.0), (l/5.0), v);

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
 * a.) 5, 2 e 3 => 0.24
 * b.) 14.125, 10.5 e 8.25 => 9.78863
 * c.) 365.4, 120.25 e 77.1 => 27101.79108
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      01/04/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       teste lendo medidas e calculando volume de paralelepipedo
 */
