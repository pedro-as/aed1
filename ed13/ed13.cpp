/**
 * ed13 - v0.1 - dd/MM/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Para compilar em terminal (janela de comandos):
 * Linux: g++ -o ed13 ed13.cpp
 * Windows: g++ -o ed13.exe ed13.cpp
 * Para executar em terminal (janela de comandos):
 * Linux: ./ed13
 * Windows: ed13
 */

// classes / pacotes
#include "Contato.hpp"

// definicoes globais
using namespace std;

// identificacao do programa
const char PROG_ID[5] = "ED13";

// metodos
void method01()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo01" << endl << endl;
    
    // definir dados
    Contato pessoa;
    pessoa.readNome("Nome: ");

    // mostrar resultado
    if (!pessoa.hasErro())
        cout << endl << "Nome = " << pessoa.getNome() << endl;
    else
        cout << endl << "Erro encontrado: " << pessoa.getErro() << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method02()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo02" << endl << endl;

    // definir dados
    Contato pessoa;
    pessoa.readFone("Fone: ");

    // mostrar resultado
    if (!pessoa.hasErro())
        cout << endl << "Fone = " << pessoa.getFone() << endl;
    else
        cout << endl << "Erro encontrado: " << pessoa.getErro() << endl;    

    // encerrar
    pause("<Enter> para continuar");
}

void method03()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo03" << endl << endl;

    // criar objeto
    Contato pessoa;

    // ler atributo
    pessoa.readFone("Fone: ");

    // mostrar resultado
    if (!pessoa.hasErro())
        cout << endl << "Fone = " << pessoa.getFone() << endl;
    else
        cout << endl << "Erro encontrado: " << pessoa.getErro() << endl; 

    // encerrar
    pause("<Enter> para continuar");
}

void method04()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo04" << endl << endl;

    // criar objeto
    Contato pessoa;

    // ler do arquivo
    pessoa.fromFile("contato.txt");

    // mostrar resultado
    if (!pessoa.hasErro())
    {
        cout << endl << "Nome = " << pessoa.getNome()
             << endl << "Fone = " << pessoa.getFone() << endl;
    }
    else
        cout << endl << "Erro encontrado: " << pessoa.getErro() << endl; 

    // encerrar
    pause("<Enter> para continuar");
}

void method05()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo05" << endl << endl;

    // criar objeto
    Contato pessoa;

    // ler dados
    pessoa.readNome("Nome: ");
    pessoa.readFone("Fone: ");

    // informar erro ao usuario, caso exista
    if (pessoa.hasErro())
    {
        cout << endl << "Erro encontrado: " << pessoa.getErro() << endl;
    }

    // gravar em arquivo
    pessoa.toFile("contato.txt");

    // encerrar
    pause("<Enter> para continuar");
}

void method06()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo06" << endl << endl;

    // criar objetos
    Contato contato1;
    ref_Contato contato2;
    ref_Contato contato3;

    contato1.readNome("Nome (1): ");
    contato1.readFone("Fone (1): ", 1);
    contato1.readFone("Fone 2 (1): ", 2);

    contato2 = new Contato("Nome2", "123-456", "789-012");
    contato3 = new Contato();

    contato3->setNome("Nome3");
    contato3->setFone("333-444", 2);
    contato3->setFone("333-333", 1);

    // mostrar dados
    cout << endl << "Contato 1";
    if (!contato1.hasErro())
    {
        cout << endl << "Nome = " << contato1.getNome()
             << endl << "Fone_1 = " << contato1.getFone()
             << endl << "Fone_2 = " << contato1.getFone(2) << endl;
    }
    else
    {
        cout << endl << "Erro encontrado: " << contato1.getErro() << endl; 
    }

    cout << endl << "Contato 2";
    if (!contato2->hasErro())
    {
        cout << endl << "Nome = " << contato2->getNome()
             << endl << "Fone_1 = " << contato2->getFone()
             << endl << "Fone_2 = " << contato2->getFone(2) << endl;
    }
    else
    {
        cout << endl << "Erro encontrado: " << contato2->getErro() << endl; 
    }

    cout << endl << "Contato 3";
    if (!contato3->hasErro())
    {
        cout << endl << "Nome = " << contato3->getNome()
             << endl << "Fone_1 = " << contato3->getFone()
             << endl << "Fone_2 = " << contato3->getFone(2) << endl;
    }
    else
    {
        cout << endl << "Erro encontrado: " << contato3->getErro() << endl; 
    }

    // encerrar
    pause("<Enter> para continuar");
}

void method07()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo07" << endl << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method08()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo08" << endl << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method09()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo09" << endl << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method10()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo10" << endl << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method11()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo11" << endl << endl;

    // encerrar
    pause("<Enter> para continuar");
}

void method12()
{
    // identificar metodo
    system("clear");
    cout << endl << "ED11 - Metodo12" << endl << endl;

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
        cout << endl <<  "Entrar com uma opcao: ";
        cin >> option;

        // escolher acao
        switch (option)
        {
          case 0:
            system("clear");
            cout << endl << "Programa encerrado" << endl;
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
    return (0);
}

/**
 * ----------------------------------- documentacao complementar
 * ----------------------------------- notas / observacoes / comentarios
 * ----------------------------------- previsao de testes
 * ----------------------------------- historico
 * Versao       Data        Modificacao
 * 0.1          dd/MM       esboco
 * ----------------------------------- testes
 * Versao       Teste 
 * 0.1          01. (OK)    identificacao de programa
 */
