/**
 * ed12 - v0.1 - 19/06/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: g++ -o ed12 ed12.cpp
 * Windows: g++ -o ed12.exe ed12.cpp
 * Para executar em terminal (janela de comandos):
 * Linux: ./ed12
 * Windows: ed12
 */

// dependencias
#include <iostream>
#include <limits>
#include <string>

// definicoes globais
void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
}

// classes / pacotes
#include "mymatrix.hpp"
using namespace std;

// identificacao do programa
const char PROG_ID[5] = "ED12";

// metodos
void method01()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED12 - Metodo01" << endl;

    // definir dados
    int m = 0;
    int n = 0;

    // ler dimensoes do teclado
    cout << endl << "Linhas: ";
    cin >> m;
    cout << "Colunas: ";
    cin >> n;

    // inicializar matriz
    Matrix <int> matrix(m, n, 0);

    // adicionar valores aleatorios
    matrix.genRandom(0, 10);

    // gravar em arquivo e mostrar na tela
    matrix.fprint_alt("dados.txt");
    matrix.print();

    // encerrar
    pause("<Enter> para continuar");
}

void method02()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED12 - Metodo02" << endl;

    // definir dados
    int k = 0;

    // inicializar matriz e ler dados do arquivo
    Matrix <int> matrix(1, 1, 0);
    matrix.fread("dados1.txt");

    // ler constante do teclado
    cout << endl << "Constante: ";
    cin >> k;

    // escalar matriz pela constante
    matrix.scale(k);

    // mostrar matriz
    matrix.print();

    // encerrar
    pause("<Enter> para continuar");
}

void method03()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED12 - Metodo03" << endl;

    // inicializar matrizes
    Matrix <int> matrix1(1, 1, 0);
    Matrix <int> matrix2(1, 1, 0);
    matrix1.fread("dados1.txt");
    matrix2.fread("identity.txt");

    // mostrar resultado
    cout << endl << "Resultado matrix1: "
         << matrix1.isIdentity()
         << endl << "Resultado matrix2: "
         << matrix2.isIdentity() << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method04()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED12 - Metodo04" << endl;

    // inicializar matrizes
    Matrix <int> matrix1(1, 1, 0);
    Matrix <int> matrix2(1, 1, 0);
    Matrix <int> matrix3(1, 1, 0);

    matrix1.fread("dados1.txt");
    matrix2.fread("dados1-cp.txt");
    matrix3.fread("dados2.txt");

    // mostrar matrizes
    cout << endl << "Matriz 1";
    matrix1.print();
    cout << endl << "Matriz 2";
    matrix2.print();
    cout << endl << "Matriz 3";
    matrix3.print();

    // mostrar resultado
    cout << endl << "Matriz 1 == Matriz 2: " << (matrix1 == matrix2)
         << endl << "Matriz 1 == Matriz 3: " << (matrix1 == matrix3) << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method05()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED12 - Metodo05" << endl;

    // inicializar matrizes
    Matrix <int> matrix1(1, 1, 0);
    Matrix <int> matrix2(1, 1, 0);
    Matrix <int> sumMatrix(1, 1, 0);

    matrix1.fread("dados1.txt");
    matrix2.fread("dados1-cp.txt");

    // mostrar matrizes
    cout << endl << "Matriz 1";
    matrix1.print();
    cout << endl << "Matriz 2";
    matrix2.print();

    // operar dados
    sumMatrix = matrix1 + matrix2;

    // mostrar resultado
    cout << endl << "Soma";
    sumMatrix.print();

    // encerrar
    pause("<Enter> para continuar");
}

void method06()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED12 - Metodo06" << endl;
    
    // inicializar matriz
    Matrix <int> matrix(1, 1, 0);
    matrix.fread("dados1.txt");

    // mostrar matriz original
    cout << endl << "Matriz original:";
    matrix.print();

   // operar matriz
    matrix.addRows(0, 1, (-1));

    // mostrar matriz modificada
    cout << endl << "Matriz modificada:";
    matrix.print();

    // encerrar
    pause("<Enter> para continuar");
}

void method07()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED12 - Metodo07" << endl;

    // inicializar matriz
    Matrix <int> matrix(1, 1, 0);
    matrix.fread("dados1.txt");

    // mostrar matriz original
    cout << endl << "Matriz original:";
    matrix.print();

   // operar matriz
    matrix.subRows(0, 1, 2);

    // mostrar matriz modificada
    cout << endl << "Matriz modificada:";
    matrix.print();

    // encerrar
    pause("<Enter> para continuar");
}

void method08()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED12 - Metodo08" << endl;

    // definir dados
    int value = 0;

    // inicializar matriz
    Matrix <int> matrix(1, 1, 0);
    matrix.fread("dados1.txt");

    // ler valor do teclado
    cout << endl << "Valor: ";
    cin >> value;

    // mostrar matriz
    matrix.print();

    // procurar valor
    cout << endl << "Linha: " << matrix.searchValue(value) << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method09()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED12 - Metodo09" << endl;

    // definir dados
    int value = 0;

    // inicializar matriz
    Matrix <int> matrix(1, 1, 0);
    matrix.fread("dados1.txt");

    // ler valor do teclado
    cout << endl << "Valor: ";
    cin >> value;

    // mostrar matriz
    matrix.print();

    // procurar valor
    cout << endl << "Coluna: " << matrix.searchValue(value, 1) << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method10()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED12 - Metodo10" << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method11()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED12 - Metodo11" << endl;

    // inicializar matrizes
    Matrix <int> matrix1(1, 1, 0);
    Matrix <int> matrix2(1, 1, 0);
    matrix1.fread("seq.txt");
    matrix2.fread("seq-not.txt");

    // mostrar resultado
    cout << endl << "Resultado matrix1: "
         << matrix1.isSequential()
         << endl << "Resultado matrix2: "
         << matrix2.isSequential() << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method12()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED12 - Metodo12" << endl;

    // inicializar matriz
    Matrix <int> matrix(5, 5, 0);
    
    // gerar sequencia transposta
    matrix.genSequential_transp();

    // mostrar matriz
    matrix.print();

    // encerrar
    pause("<Enter> para continuar");
}

int main(int argc, char **argv)
{
    // definir opcao do menu
    int option = 0;

    // repetir ate receber comando de parada
    do
    {
        // limpar tela
        system("clear");

        // identificar
        cout << PROG_ID << " - Programa - v0.1" << endl;
        cout << "Autor: Pedro Henrique Amorim Sa - 742626\n" << endl;

        // mostrar opcoes
        cout << "Opcoes:\n" << endl;
        cout << "0  -> Parar" << endl;
        cout << "1  -> Metodo 1" << endl;
        cout << "2  -> Metodo 2" << endl;
        cout << "3  -> Metodo 3" << endl;
        cout << "4  -> Metodo 4" << endl;
        cout << "5  -> Metodo 5" << endl;
        cout << "6  -> Metodo 6" << endl;
        cout << "7  -> Metodo 7" << endl;
        cout << "8  -> Metodo 8" << endl;
        cout << "9  -> Metodo 9" << endl;
        cout << "10 -> Metodo 10" << endl;
        cout << "11 -> Metodo 11" << endl;
        cout << "12 -> Metodo 12" << endl;

        // ler do teclado
        cout << endl <<  "Entrar com uma opcao: ";
        cin >> option;

        // escolher acao
        switch (option)
        {
          case 0:
            break;
          case 1:
            method01();
            break;
          case 2:
            method02();
            break;
          case 3:
            method03();
            break;
          case 4:
            method04();
            break;
          case 5:
            method05();
            break;
          case 6:
            method06();
            break;
          case 7:
            method07();
            break;
          case 8:
            method08();
            break;
          case 9:
            method09();
            break;
          case 10:
            method10();
            break;
          case 11:
            method11();
            break;
          case 12:
            method12();
            break;
          default:
            cout << endl << "ERRO: valor invalido" << endl;
        }

    } while (option != 0);

    // encerrar
    system("clear");
    cout << endl << "Encerrando programa..." << endl;
    pause("<Enter> para sair");
    system("clear");
    return (0);
}

/**
 * ----------------------------------- documentacao complementar
 * ----------------------------------- notas / observacoes / comentarios
 * ----------------------------------- previsao de testes
 * ----------------------------------- historico
 * Versao       Data        Modificacao
 * 0.1          19/06       esboco
 * ----------------------------------- testes
 * Versao       Teste 
 * 0.1          01. (OK)    identificacao de programa
 */
