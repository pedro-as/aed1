/*
 * Guia0202.cpp - v0.2 - 18/3/2021
 * Author: Pedro H. Amorim Sa - 742626
 * 
 * Para compilar em um terminal:
 * 
 * No Linux  : g++ -o Guia02E2 ./Guia02E2cpp
 * No Windows: g++ -o Guia02E2.exe ./Guia0202.cpp
 * 
 * Para executar em um terminal:
 * 
 * No Linux  : ./Guia0202
 * No Windows:   Guia0202
 * 
 */

// lista de dependencias
#include "karel.hpp"

// --------------------------- definicoes de metodos
/*
  decorateWorld - Metodo para preparar o cenario
  @param fileName - nome do arquivo para guardar a descricao
*/
void decorateWorld(const char* fileName)
{
    // colocar um marcador no mundo
    world->set(4, 4, BEEPER);

    // salvar a configuracao atual do mundo
    world->save(fileName);
}

/*
  Classe para definir robo particular (MyRobot),
  a partir do modelo generico (Robot)

  Nota: todas as definicoes irao valer para qualquer outro robo
  criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
{
public:
    /*
      turnRight - Procedimento para virar 'a direita
    */
   void turnRight()
   {
        //definir dado local
        int step = 0;

        //testar se o robo esta' ativo
        if (checkStatus())
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            for (step; step < 3; step++)
            {
                turnLeft();
            }
        }
    }

    /*
      moveN - Metodo para mover certa quantidade de passos
      @param steps - passos a serem dados
    */
    void moveN(int steps)
    {   
        // testar se a quantidade de passos e' maior que zero
        for (int step = steps; step > 0; step--)
        {
            // dar um passo
            move();
        }
    }

    /*
      doPartialTask - Metodo para especificar parte de uma tarefa
    */
    void doPartialTask()
    {
        // especificar acoes dessa parte da tarefa
        moveN(3);
        turnLeft();
    }

    /*
      doSquare - Metodo para especificar outro percurso
    */
    void doSquare()
    {
        // definir dado local
        int step = 4;

        // especificar acoes da tarefa
        while (step > 0)
        {
            // realizar uma parte da tarefa
            moveN(3);
            turnRight();
            // tentar passar 'a proxima
            step--;
        }
        turnOff();
    }

    /*
      doTask - Relacao de acoes para o robo executar
    */
    void doTask()
    {
        // definir dado local
        int step = 4;

        // especificar acoes da tarefa
        while (step > 0)
        {
            // realizar uma parte da tarefa
            doPartialTask();
            // tentar passar 'a proxima
            step--;
        }

        // encerrar
        turnOff();
    }
};

// --------------------------- acao principal
/*
  Acao principal: executar a tarefa descrita acima
*/

int main()
{
    // definir o contexto

    // criar o ambiente e decorar com objetos
    // OBS.: executar pelo menos uma vez,
    //       antes de qualquer outra coisa
    //       (depois de criado, podera' ser comentado)
    world->create("");            // criar o mundo
    decorateWorld("Guia0202.txt");
    world->show();

    // preparar o ambiente para uso
    world->reset();               // limpar configuracoes
    world->read("Guia0202.txt");  // ler configuracao atual para o ambiente
    world->show();                // mostrar a configuracao atual

    set_Speed(3);                 // definir velocidade padrao

    // criar robo
    MyRobot *robot = new MyRobot();

    // posicionar robo no ambiente (situacao inicial):
    // posicao (x=1, y=1), voltado para direita,
    // com zero marcadores, nome escolhido)
    robot->create(1, 1, NORTH, 0, "Karel");

    // executar tarefa
    robot->doSquare();

    // encerrar operacoes no ambiente
    world->close();

    // encerrar programa
    getchar();
    return(0);
}

// --------------------------------- testes
/*
------------------------------------ documentacao complementar
------------------------------------ notas / observacoes / comentarios
------------------------------------ historico
Versao    Data    Modificacao
 0.1     19/3/21    esboco
------------------------------------ testes
Versao    Teste
 0.1     01. (OK)    teste inicial
 0.2     01. (OK)    teste da repeticao de virar 'a direita
*/
