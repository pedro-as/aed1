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

#include <string>


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
    string fone2;

    bool validFone(std::string fone)
    {
        bool result = true;
        int len = fone.size();
        int i = 0;
        int c = '\0';

        while (result && i < len)
        {
            c = fone[i];
            result = result && (('0' <= c && c <= '9') || (c == '-'));
            i++;
        }
        return result;
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
        fone2 = "";
    }

    /**
     * Construtor alternativo
     */
    Contato(std::string nome_inicial, std::string fone_inicial,
            std::string fone_alt)
    {
        setErro(0);
        nome = nome_inicial;
        fone = fone_inicial;
        fone2 = fone_alt;
    }

    /**
     * Construtor alternativo baseado em copia
     */
    Contato(Contato const &another)
    {
        setErro(0);
        setNome(another.nome);
        setFone(another.fone);
        setFone(another.fone2, 2);
    }

    // metodos para acesso
    void setNome(std::string nome)
    {
        if (nome.empty())
            setErro(1);
        else
            this->nome = nome;
    }

    void setFone(std::string fone, int opt=1)
    {
        if (fone.empty() || !this->validFone(fone))
            setErro(2);
        else
        {
            switch (opt)
            {
            case 1:
                this->fone = fone;
                break;
            case 2:
                this->fone2 = fone;
                break;
            default:
                setErro(6);
                break;
            }
        }
    }

    std::string getNome()
    {
        return (this->nome);
    }

    std::string getFone(int opt=1)
    {
        switch (opt)
        {
        case 1:
            return this->fone;
            break;
        case 2:
            return this->fone2;
            break;
        default:
            return "";
            break;
        }
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

    void readFone(std::string text, int opt=1)
    {
        std::string fone = "";

        cout << text;
        cin >> fone;

        if (fone.empty() || !this->validFone(fone))
            setErro(4);
        else
        {
            switch (opt)
            {
            case 1:
                this->fone = fone;
                break;
            case 2:
                this->fone2 = fone;
                break;
                break;
            default:
                setErro(6);
                break;
            }
        }
    }

    void fromFile(std::string fileName)
    {
        std::ifstream afile;
        std::string nome = "";
        std::string fone = "";

        afile.open(fileName);

        // testar se arquivo existe
        if (!afile.is_open())
        {
            setErro(5);
        }
        else
        {
            afile >> nome;
            afile >> fone;
            this->setNome(nome);
            this->setFone(fone); // possibilita validar formato
        }
        afile.close();
    }

    void toFile(std::string fileName)
    {
        std::ofstream afile;

        afile.open(fileName);

        afile << this->nome << endl;
        afile << this->fone << endl;

        afile.close();
    }
};

using ref_Contato = Contato*;

#endif