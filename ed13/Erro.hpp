#ifndef _ERRO_H_
#define _ERRO_H_

/**
 * Tratamento de erro
 * Codigos de erro:
 * 0. Nao ha' erro
 */
class Erro
{

/**
 * atributos privados
 */
private:
    int erro;
  
/**
 * definicoes publicas
 */
public:

    /** 
     * Destrutor
     */
    ~Erro()
    {}

    /**
     * Construtor padrado
     */
    Erro()
    {
        erro = 0;
    }

    // metodos para acesso

    int getErro()
    {
        return(erro);
    }

// metodos para acesso restrito
protected:
    void setErro(int codigo)
    {
        erro = codigo;
    }
};

#endif