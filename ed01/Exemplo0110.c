/**
 * Exemplo0110 - v0.1 - 30/03/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: gcc -o Exemplo0110 Exemplo0110.c
 * Windows: gcc -o Exemplo0110.exe Exemplo0110.c
 * Para executar em terminal (janela de comandos):
 * Linux: ./Exemplo0110
 * Windows: Exemplo0110
*/

// dependencias
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
    int x = 5;      // definir variavel com valor inicial para guardar inteiro
    double y = 3.5; // definir variavel com valor inicial para guardar real
    char z  = 'A';  // definir variavel com valor inicial para guardar caractere
    bool w = TRUE; // definir variavel com valor inicial para guardar logico
    chars a = IO_new_chars(STR_SIZE); // definir variavel com tamanho inicial
    chars b = IO_new_chars(STR_SIZE); // definir variavel com tamanho inicial
    chars c = IO_new_chars(STR_SIZE); // definir variavel com tamanho inicial

    // identificar
    IO_id("Exemplo0110 - Programa = v0.1");

    // concatenar cadeias de caracteres
    strcpy(a, "abc"); // atribuir 'a variavel (a) o valor constante ("abc")
    strcpy(b, "def"); // OBS.: a atribuicao de cadeias de caracteres NAO usa (=)

    IO_printf("\na = %s b = %s\n", a, b);

    c = IO_concat(a, b); // alternativa melhor para a funcao nativa strcat(a, b)
    IO_printf("\nc = [%s]+[%s] = [%s]\n", a, b, c);

    strcpy(a, "c = ");
    strcpy(c, STR_EMPTY); // limpar a cadeia de caracteres

    IO_printf("%s\n", IO_concat(a, IO_toString_c(z)));
    IO_println(IO_concat("x = ", IO_toString_d(x)));
    IO_println(IO_concat("w = ", IO_toString_b(w)));

    strcpy(b, STR_EMPTY);
    IO_print("y = ");
    IO_print(IO_concat(b, IO_toString_f(y)));
    IO_print("\n");

    z = IO_readchar("char = ");
    IO_println(IO_concat(a, IO_toString_c(z)));

    y = IO_readdouble("double = ");
    IO_println(IO_concat(a, IO_toString_f(y)));

    x = IO_readint("int = ");
    IO_println(IO_concat(a, IO_toString_d(x)));

    w = IO_readbool("bool = ");
    IO_println(IO_concat(a, IO_toString_b(w)));

    b = IO_readstring("chars = ");
    IO_println(IO_concat(a, b));

    b = IO_readln("line = ");
    IO_println(IO_concat(a, b));

    // encerrar
    IO_pause("\n\nApertar ENTER para terminar.");
    
    //fflush (stdin);
    // limpar a entrada de dados
    // getchar();
    // getchar();
    return (0); // voltar ao SO (sem erros)
} // fim main( )

/**
 * ---------------------------------------------- documentacao complementar
 * ---------------------------------------------- notas / observacoes / comentarios
 * ---------------------------------------------- previsao de testes
 * a.) a
 * b.) 4.2
 * c.) 10
 * d.) 1
 * e.) abc def
 * f .) abc def
 * ---------------------------------------------- historico
 * Versao      Data        Modificacao
 *  0.1      30/03/21        esboco
 * ---------------------------------------------- testes
 * Versao      Teste
 *  0.1     01. (OK)       identificacao de programa
 */
