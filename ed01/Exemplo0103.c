/**
 * Exemplo0103 - v0.1 - 30/03/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0103 Exemplo0103.c
 * Windows: gcc -o Exemplo0103.exe Exemplo0103.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0103
 * Windows: Exemplo0103
*/

// dependencias
#include <stdio.h>

// para as entradas e saidas
/**
 * Funcao principal.
 * @return codigo de encerramento
 * @param argc - quantidade de parametros na linha de comandos
 * @param argv - arranjo com o grupo de parametros na linha de comandos
 */
int main(int argc, char* argv[])
{
    // definir dado
    char x = 'A'; // definir variavel com valor inicial

    // identificar
    printf("%s\n", "Exemplo0103 - Programa = v0.1");
    printf("%s\n", "Autor: Pedro Henrique Amorim Sa");
    printf("\n");
    printf("\n");

    // mudar de linha
    // mostrar valor inicial
    printf ("%s%c\n", "x = ", x);
    // ler do teclado
    printf("Entrar com um caractere: ");
    scanf ("%c", &x);
    // OBS.: Necessario indicar o endereco -> &
    // mostrar valor lido
    printf ("%s%c\n", "x = ", x);
    // encerrar
    printf ("\n\nApertar ENTER para terminar.");
    //fflush (stdin);
    // limpar a entrada de dados
    getchar();
    getchar(); // aguardar por ENTER
    return (0); // voltar ao SO (sem erros)
} // fim main( )

/**
 * ---------------------------------------------- documentacao complementar
 * ---------------------------------------------- notas / observacoes / comentarios
 * ---------------------------------------------- previsao de testes
 * a.) B
 * b.) c
 * c.) deFG => resultado deve ser 'd'
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      30/03/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       identificacao de programa
 *                         leitura e exibicao de caractere
 */
