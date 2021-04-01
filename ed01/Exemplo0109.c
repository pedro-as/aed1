/**
 * Exemplo0109 - v0.1 - 30/03/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0109 Exemplo0109.c
 * Windows: gcc -o Exemplo0109.exe Exemplo0109.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0109
 * Windows: Exemplo0109
*/

// dependencias
#include <stdio.h>   // para entradas e saidas
#include <string.h> // para cadeia de caracteres
#include <math.h> // para funcoes matematicas
#include "stdbool.h" // para valores logicos, com biblioteca adaptada

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
    int x = 0;      // definir variavel com valor inicial para guardar inteiro
    double y = 3.5; // definir variavel com valor inicial para guardar real
    char z  = 'A';  // definir variavel com valor inicial para guardar caractere
    bool w = false; // definir variavel com valor inicial para guardar logico

    // definir dados com mais de um valor
    char s[80]; // definir espaco de armazenamento para ate' 80 caracteres
    
    // identificar
    printf("%s\n", "Exemplo0109 - Programa = v0.1");
    printf("%s\n", "Autor: Pedro Henrique Amorim Sa");
    printf("\n");
    printf("\n");

    // mostrar valores iniciais
    printf("01. %s%d\n", "x = ", x);
    printf("02. %s%lf\n", "y = ", y);
    printf("03. %s%c\n", "z = ", z);
    
    // converter entre tipos de dados (type casting)
    x = (int) z; // codigo inteiro equivalente ao caractere
    printf("04. %s%d -> %c\n", "x = ", x, z);

    x = (int) y; // parte inteira de real
    printf("05. %s%d -> %lf\n", "x = ", x, y);

    x = 97;
    z = (char) x; // caractere equivalente ao codigo inteiro
    printf("06. %s%c -> %d\n", "z = ", z, x);
    
    x = (int) '0'; // codigo inteiro equivalente ao caractere
    z = (char) x; // caractere equivalente ao codigo inteiro
    printf("07. %s%c -> %d\n", "z = ", z, x);

    x = w; // codigo inteiro equivalente ao logico
    printf("08. %s%d -> %d\n", "x = ", x, w);

    w = true;
    x = w; // codigo inteiro equivalente ao logico
    printf("09. %s%d -> %d\n", "x = ", x, w);

    x = (w == false); // equivalente 'a comparacao de igualdade (true == false)
    printf("10. %s%d -> %d\n", "x = ", x, w);

    x = !(w == false); // equivalente ao contrario da comparacao
                       // de igualdade (true == false)
    printf("11. %s%d -> %d\n", "x = ", x, w);

    x = (w != false); // equivalente 'a comparacao de
                      // diferenca (true != false)
    printf("12. %s%d -> %d\n", "x = ", x, w);

    w = (x < y); // equivalente 'a comparacao entre (x) e (y)
    printf("13. %s%d < %lf = %d\n", "x = ", x, y, w);

    w = (x <= y); // equivalente 'a comparacao entre (x) e (y)
    printf("14. %s%d <= %lf = %d\n", "x = ", x, y, w);

    w = (y > x); // equivalente 'a comparacao entre (x) e (y)
    printf("15. %s%lf > %d = %d\n", "x = ", y, x, w);

    w = (y >= x); // equivalente 'a comparacao entre (x) e (y)
    printf("16. %s%lf >= %d = %d\n", "x = ", y, x, w);

    x = 4;
    w = (x % 2 == 0); // equivalente a testar se e' par
    printf("17. %s(%d%%2) ? %d\n", "e' par ", x, w);

    x = 4;
    w = (x % 2 != 0); // equivalente a testar se e' impar
    printf("18. %s(%d%%2) ? %d\n", "e' impar ", x, w);

    z = 'x';
    w = ('a' <= z && z <= 'z'); // equivalente a testar se e' letra minuscula,
                                // pertence a ['a':'z'] (e' igual ou esta'
                                // entre 'a' e 'z')
    printf("19. %s (%c) ? %d\n", "e' minuscula ", z, w);

    z = 'X';
    w = (!('a' <= z && z <= 'z')); // equivalente a testar se NAO e' letra minuscula
    printf("20. %s (%c) ? %d\n", "nao e' minuscula ", z, w);

    z = 'x';
    w = ('A' <= z && z <= 'Z'); // equivalente a testar se e' letra maiuscula
    printf("21. %s (%c) ? %d\n", "e' maiuscula ", z, w);

    z = 'X';
    w = ((z < 'A') || ('Z' < z)); // equivalente a testar se NAO e' letra maiuscula
    printf("22. %s (%c) ? %d\n", "nao e' maiuscula ", z, w);

    z = '0';
    w = ('0' == z || '1' == z); // equivalente a testar se e' igual a '0' ou '1'
    printf("23. %s (%c) ? %d\n", "e' '0' ou '1' ", z, w);

    strcpy(s, "zero"); // copiar para (s) <- "zero" (NAO usar '=' com caracteres)
    printf("24. palavra = %s\n", s);

    w = (strcmp("zero", s) == 0); // comparar se caracteres iguais
                                  // Nota: o resultado da comparacao sempre
                                  // devera' ser avaliado em relacao a 0
                                  // e sera' igual caso coincida
    printf("25. palavra == %s ? %d\n", s, w);

    strcpy(s, "um e dois"); // copiar para (s) <- "outras palavras"
    printf("26. palavras = %s\n", s);

    w = (strcmp("zero", s) != 0); // resultado sera' diferente de 0 caso NAO coincida
    printf("27. palavras == %s ? %d\n", s, w);

    // encerrar
    printf ("\n\nApertar ENTER para terminar.");
    
    //fflush (stdin);
    // limpar a entrada de dados
    // getchar();
    getchar(); // aguardar por ENTER
    return (0); // voltar ao SO (sem erros)
} // fim main( )

/**
 * ---------------------------------------------- documentacao complementar
 * ---------------------------------------------- notas / observacoes / comentarios
 * ---------------------------------------------- previsao de testes
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      30/03/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       identificacao de programa
 */
