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

    // definir dados
    int n = 0;
    int value = 0;

    // ler quantidade do teclado
    cout << "\nEntre com quantidade inteira: ";
    cin >> n;
    cout << endl;

    // criar arranjo
    Array <int> int_array(n);

    // inserir valores aleatorios
    for (int i = 0; i < n; i++)
    {
        value = int_array.randInt(0, 31);
        int_array.set(i, value);
    }

    // gravar em arquivo
    int_array.fprint("dados.txt");

    // liberar espaco
    int_array.free();

    // encerrar
    pause("<Enter> para continuar");
}

void method02()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo02" << endl;

    // definir dados
    int max = 0;

    // iniciar arranjo e ler do arquivo
    Array <int> int_array(1);
    int_array.fread("dados.txt");

    // procurar valor maximo
    max = int_array.getMax();

    // mostrar
    cout << "max = " << max << endl;

    // liberar espaco
    int_array.free();

    // encerrar
    pause("<Enter> para continuar");
}

void method03()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo03" << endl;

    // definir dados
    int min = 0;

    // iniciar arranjo e ler do arquivo
    Array <int> int_array(1);
    int_array.fread("dados.txt");

    // procurar valor minimo
    min = int_array.getMin();

    // mostrar
    cout << "min = " << min << endl;

    // liberar espaco
    int_array.free();

    // encerrar
    pause("<Enter> para continuar");
}

void method04()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo04" << endl;

    // definir dados
    int soma = 0;

    // iniciar arranjo e ler do arquivo
    Array <int> int_array(1);
    int_array.fread("dados.txt");

    // obter soma do arranjo
    soma = int_array.sum();

    // mostrar
    cout << "soma = " << soma << endl;

    // liberar espaco
    int_array.free();

    // encerrar
    pause("<Enter> para continuar");
}

void method05()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo05" << endl;

    // definir dados
    double media = 0.0;

    // iniciar arranjo e ler do arquivo
    Array <int> int_array(1);
    int_array.fread("dados.txt");

    // obter media do arranjo
    media = int_array.avg();

    // mostrar
    cout << "media = " << media << endl;

    // liberar espaco
    int_array.free();


    // encerrar
    pause("<Enter> para continuar");
}

void method06()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo06" << endl;

    // definir dados
    bool zeros = false;

    // iniciar arranjo e ler do arquivo
    Array <int> int_array(1);
    int_array.fread("dados.txt");

    // obter media do arranjo
    zeros = int_array.allZero();

    // mostrar resultado
    if (zeros)
    {
        cout << "\nTodos os valores são iguais a zero" << endl;
    }
    else
    {
        cout << "\nPelo menos um valor e' diferente de zero" << endl;
    }

    // liberar espaco
    int_array.free();

    // encerrar
    pause("<Enter> para continuar");
}

void method07()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo07" << endl;

    // definir dados
    bool ordenado = false;

    // iniciar arranjo e ler do arquivo
    Array <int> int_array(1);
    int_array.fread("dados.txt");

    // obter media do arranjo
    ordenado = int_array.isSorted_desc();

    // mostrar resultado
    if (ordenado)
    {
        cout << "\nArranjo esta' em ordem decrescente" << endl;
    }
    else
    {
        cout << "\nArranjo NAO esta' em ordem decrescente" << endl;
    }

    // liberar espaco
    int_array.free();

    // encerrar
    pause("<Enter> para continuar");
}

void method08()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo08" << endl;

    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo07" << endl;

    // definir dados
    bool encontrado = false;
    int valor = 0;
    int inicio = 0;
    int fim = 0;

    // ler valor e intervalo do teclado
    cout << "Entre com valor procurado: ";
    cin >> valor;
    cout << "Entre com limite INFERIOR do intervalo: ";
    cin >> inicio;
    
    while (fim <= inicio)
    {
        cout << "Entre com limite SUPERIOR do intervalo: ";
        cin >> fim;
    }

    // iniciar arranjo e ler do arquivo
    Array <int> int_array(1);
    int_array.fread("dados.txt");

    // obter media do arranjo
    encontrado = int_array.findInRange(valor, inicio, fim);

    // mostrar resultado
    if (encontrado)
    {
        cout << "\nValor encontrado no intervalo" << endl;
    }
    else
    {
        cout << "\nValor NAO encontrado no intervalo" << endl;
    }

    // liberar espaco
    int_array.free();

    // encerrar
    pause("<Enter> para continuar");
}

void method09()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo09" << endl;

    // definir dados
    int k = 0;

    // ler constante do teclado
    cout << "Entre com constante: ";
    cin >> k;

    // iniciar arranjo original e ler do arquivo
    Array <int> int_array1(1);
    int_array1.fread("dados.txt");

    // gerar segundo arranjo
    Array <int> int_array2(int_array1, k);

    // mostrar resultado
    int_array2.print();

    // liberar espaco
    int_array1.free();
    int_array2.free();

    // encerrar
    pause("<Enter> para continuar");
}

void method10()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo10" << endl;

    // iniciar arranjo original e ler do arquivo
    Array <int> int_array(1);
    int_array.fread("dados.txt");

    // ordenar de forma decrescente
    int_array.quickSort_desc(0, int_array.getLength());

    // mostrar arranjo ordenado
    cout << "\nArranjo decrescente:" << endl;
    int_array.print();

    // liberar espaco
    int_array.free();

    // encerrar
    pause("<Enter> para continuar");
}

void method11()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo11" << endl;

    // iniciar arranjos e ler dos arquivos
    Array <int> int_array1(1);
    Array <int> int_array2(1);
    int_array1.fread("dados.txt");
    int_array2.fread("dados_alt.txt");

    // mostrar dados
    cout << "\nArray 1";
    int_array1.print();

    cout << "\nArray 2";
    int_array2.print();

    // mostrar comparacao
    cout << endl;

    if (int_array1!=int_array2)
    {
        cout << "Resultado = DIFERENTES" << endl;
    }
    else
    {
        cout << "Resultado = IGUAIS" << endl;
    }

    // liberar espaco
    int_array1.free();
    int_array2.free();

    // encerrar
    pause("<Enter> para continuar");
}

void method12()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo12" << endl;

    // iniciar arranjos
    Array <int> int_array1(1);
    Array <int> int_array2(1);
    Array <int> int_array3(1);

    // ler dados de arquivo
    int_array1.fread("dados.txt");
    int_array2.fread("dados_alt.txt");

    // subtrair dados
    int_array3 = int_array2 - int_array1;

    // mostrar subtracao
    cout << "\nSubtracao";
    int_array3.print();

    // liberar espaco
    int_array1.free();
    int_array2.free();
    int_array3.free();

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
 * 0.1          10/06       esboco
 * ----------------------------------- testes
 * Versao       Teste 
 * 0.1          01. (OK)    identificacao de programa
 */
