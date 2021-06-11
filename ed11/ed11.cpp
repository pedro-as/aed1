/**
 * ed11 - v0.1 - 10/06/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: g++ -o ed11 ed11.cpp
 * Windows: g++ -o ed11.exe ed11.cpp
 * Para executar em terminal (janela de comandos):
 * Linux: ./ed11
 * Windows: ed11
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
#include "myarray.hpp"
using namespace std;

// identificacao do programa
const char PROG_ID[5] = "ED11";

// metodos
void method01()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo01" << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method02()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo02" << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method03()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo03" << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method04()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo04" << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method05()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo05" << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method06()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo06" << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method07()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo07" << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method08()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo08" << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method09()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo09" << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method10()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo10" << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method11()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo11" << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method12()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo12" << endl;

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
        // identificar
        cout << PROG_ID << " - Programa - v0.1\n" << endl;

        // mostrar opcoes
        cout << "Opcoes" << endl;
        cout << "0 - Parar" << endl;
        cout << "1 - Metodo 1" << endl;
        cout << "2 - Metodo 2" << endl;
        cout << "3 - Metodo 3" << endl;
        cout << "4 - Metodo 4" << endl;
        cout << "5 - Metodo 5" << endl;
        cout << "6 - Metodo 6" << endl;
        cout << "7 - Metodo 7" << endl;
        cout << "8 - Metodo 8" << endl;
        cout << "9 - Metodo 9" << endl;
        cout << "10 - Metodo 10" << endl;
        cout << "11 - Metodo 11" << endl;
        cout << "12 - Metodo 12" << endl;

        // ler do teclado
        cout << endl <<  "Entrar com uma opcao";
        cin >> option;

        // escolher acao
        switch (option)
        {
          case 0:
            system("clear");
            cout << endl << "Encerrando" << endl;
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
    pause("<Enter> para terminar");
    return (0);
}

/**
 * ----------------------------------- documentacao complementar
 * ----------------------------------- notas / observacoes / comentarios
 * ----------------------------------- previsao de testes
 * ----------------------------------- historico
 * Versao       Data        Modificacao
 * 0.1          10/06       esboco
 * ----------------------------------- testes
 * Versao       Teste 
 * 0.1          01. (OK)    identificacao de programa
 */
