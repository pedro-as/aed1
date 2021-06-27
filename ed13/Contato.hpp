#ifndef _CONTATO_H_
#define _CONTATO_H_

// dependencias

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;


// outras dependencias
void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
}

#include "Erro.hpp"

// definicao de classe

/**
 * Classe para tratar contatos, derivada da classe Erro
 */
class Contato : public Erro
{
private:
    string nome;
    string fone;

    bool validFone(std::string fone)
    {
        
    }

public:
    /**
     * Destrutor
     */
    ~Contato()
    {}

    /**
     * Construtor padrao
     */
    Contato()
    {
        setErro(0);
        nome = "";
        fone = "";
    }

    /**
     * Construtor alternativo
     */
    Contato(std::string nome_inicial, std::string fone_inicial)
    {
        setErro(0);
        nome = nome_inicial;
        fone = fone_inicial;
    }

    /**
     * Construtor alternativo baseado em copia
     */
    Contato(Contato const &another)
    {
        setErro(0);
        setNome(another.nome);
        setFone(another.fone);
    }

    // metodos para acesso
    void setNome(std::string nome)
    {
        if (nome.empty())
            setErro(1);
        else
            this->nome = nome;
    }

    void setFone(std::string fone)
    {
        if (fone.empty())
            setErro(2);
        else
            this->fone = fone;
    }

    std::string getNome()
    {
        return (this->nome);
    }

    std::string getFone()
    {
        return (this->fone);
    }

    std::string toString()
    {
        return ("{" + getNome() + ", " + getFone() + "}");
    }

    bool hasErro()
    {
        return (getErro() != 0);
    }

    void readNome(std::string text)
    {
        std::string nome = "";

        cout << text;
        cin >> nome;

        if (nome.empty())
            setErro(3);
        else
            this->nome = nome;
    }

    void readFone(std::string text)
    {
        std::string fone = "";

        cout << text;
        cin >> fone;

        if (fone.empty())
            setErro(4);
        else
            this->fone = fone;
    }
};

using ref_Contato = Contato*;

#endif