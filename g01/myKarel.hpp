#include "karel.hpp"

/*
  Classe para definir metodos customizados (CustomRobot),
  tendo como base o modelo generico (Robot), para utilizacao
  em programas futuros
*/
class CustomRobot : public Robot
{
    public:
    /*
    moveN - Metodo para mover certa quantidade de passos
    @param steps - passos a serem dados
    */
    void moveN(int steps)
    {
        // testar se a quantidade de passos e' maior que zero
        for (int step = 0; step < steps; step++)
        {
            // dar um passo
            move();
        } // end for
    } // end moveN()

    /* 
    putBeepers - Metodo para descarregar multiplos marcadores
    @param n - numero de marcadores a descarregar
    */
    void putBeepers(int n)
    {
        while (n > 0 && nbeepers() > 0)
        {
            putBeeper();
            n -= 1;
        }
    } // end putBeepers()

    /* 
    pickBeepers - Metodo para pegar multiplos marcadores
    @param n - numero de marcadores a pegar
    */
    void pickBeepers(int n)
    {
        while (n > 0 && nextToABeeper())
        {
            pickBeeper();
            n -= 1;
        }
    } // end pickBeepers()
};