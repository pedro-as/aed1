/*
 * Guia0114.cpp - v1.4 - 12/3/2021
 * Author: Pedro H. Amorim Sá - 742626
 * 
 * Para compilar em um terminal:
 * 
 * No Linux  : g++ -o Guia0114 ./Guia0114.cpp
 * No Windows: g++ -o Guia0114.exe ./Guia0114.cpp
 * 
 * Para executar em um terminal:
 * 
 * No Linux  : ./Guia0114
 * No Windows:   Guia0114
 * 
 */

// lista de dependencias
#include "karel.hpp"

// ---------------------------definicoes de metodos

/*
  decorateWorld - Metodo para preparar o cenario.
  @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
    // colocar tres marcadores no mundo
    world->set ( 2, 6, BEEPER );
    world->set ( 5, 2, BEEPER );
    world->set ( 5, 7, BEEPER );
    
    // configurar paredes verticais
    for (int i = 3; i <= 5; i++)
    {
        world->set ( 2, i, VWALL );
        world->set ( 5, i, VWALL );
    }
    world->set ( 2, 6, VWALL );
    
    // configurar paredes horizontais
    for (int j = 3; j <= 5; j++)
    {
        world->set ( j, 2, HWALL );
        world->set ( j, 6, HWALL );
    }
    
    // salvar a configuracao atual do mundo
    world->save( fileName );
} // decorateWorld ( )

/*
  Classe para definir robo particular (MyRobot),
  a partir do modelo generico (Robot)
  Nota: Todas as definicoes irao valer para qualquer outro robo
  criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
{
    public:
    /*
    turnRight - Procedimento para virar 'a direita.
    */
    void turnRight ( )
    {
        // testar se o robo esta' ativo
        if ( checkStatus ( ) )
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            turnLeft ( );
            turnLeft ( );
            turnLeft ( );
        }   // end if
    }   // end turnRight ( )
    
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
      doPartialTask - Metodo para especificar parte de uma tarefa
    */
    void doPartialTask()
    {
        // retornar ao inicio
        turnLeft();
        turnLeft();
        moveN(3);
        turnRight();
        move();
        turnRight();
        moveN(5);
        turnRight();
        moveN(5);
        turnLeft();
        turnLeft();
    } // end doPartialTask()
    
    /*
      doTask - Relacao de acoes para o robo executar
    */
    void doTask ()
    {
        moveN(4);
        turnLeft();
        move();
        pickBeeper();
        turnLeft();
        moveN(3);
        turnRight();
        moveN(4);
        pickBeeper();
        move();
        turnRight();
        moveN(3);
        pickBeeper();
        move();
        turnRight();
        move();
        turnRight();
        move();
        turnLeft();
        moveN(3);
        for (int beepers = 3; beepers > 0; beepers--)
        {
            putBeeper();
        }
        doPartialTask();
        // encerrar
        turnOff();      // desligar-se
    } //end doTask()
}; // end class MyRobot

// --------------------------- acao principal

/*
  Acao principal: executar a tarefa descrita acima.
*/

int main ( )
{
    // definir o contexto
    // criar o ambiente e decorar com objetos
    // OBS.: executar pelo menos uma vez,
    // antes de qualquer outra coisa
    // (depois de criado, podera' ser comentado)
    world->create ( "" );
    // criar o mundo
    decorateWorld ( "Guia0114.txt" );
    world->show ( );
    // preparar o ambiente para uso
    world->reset ( );
    // limpar configuracoes
    world->read ( "Guia0114.txt" );// ler configuracao atual para o ambiente
    world->show ( );
    // mostrar a configuracao atual
    set_Speed ( 3 );
    // definir velocidade padrao
    // criar robo
    MyRobot *robot = new MyRobot( );
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido
    robot->create ( 1, 1, EAST, 0, "Karel" );
    // executar tarefa
    robot->doTask();
    // encerrar operacoes no ambiente
    world->close ( );
    // encerrar programa
    getchar ( );
    return ( 0 );
} // end main ( )

// ------------------------------------------- testes

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao      Data        Modificacao
 0.1       12/3/21       esboco

 ---------------------------------------------- testes
Versao      Teste
 0.1        01.(OK)     teste inicial
 0.2        01.(OK)     teste da tarefa
 0.3        01.(OK)     teste da tarefa parcial
 0.4        01.(OK)     teste do apanhar marcador
 0.5        01.(OK)     teste do colocar marcador
 0.6        01.(OK)     teste da repeticao do movimento
 0.7        01.(OK)     teste com marcador na posicao (4,4)
            02.(OK)     teste sem marcador na posicao (4,4)
 0.8        01.(OK)     teste com a quantidade de marcadores
 0.9        01.(OK)     teste com outra forma de repeticao
 1.0        01.(OK)     teste com outra forma de alternativa
 1.1        01.(OK)     teste colocando tres marcadores e retornando ao inicio
 1.2        01.(OK)     teste pegando tres marcadores em ordem inversa e retornando ao inicio
 1.3        01.(OK)     teste pegando tres marcadores, descarregando-os e retornando ao inicio
 1.4        01.(OK)     teste pegando tres marcadores, descarregando-os e retornando ao inicio, com paredes

*/
