/*
 * Guia0113.cpp - v1.3 - 12/3/2021
 * Author: Pedro H. Amorim Sá - 742626
 * 
 * Para compilar em um terminal:
 * 
 * No Linux  : g++ -o Guia0113 ./Guia0113.cpp
 * No Windows: g++ -o Guia0113.exe ./Guia0113.cpp
 * 
 * Para executar em um terminal:
 * 
 * No Linux  : ./Guia0113
 * No Windows:   Guia0113
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
    // colocar um marcador no mundo
    world->set ( 3, 3, BEEPER );
    world->set ( 6, 3, BEEPER );
    world->set ( 6, 6, BEEPER );
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
        // executar tres movimentos e pegar marcador
        moveN(3);
        pickBeeper();
        turnLeft();
    } // end doPartialTask()
    
    /*
      doTask - Relacao de acoes para o robo executar
    */
    void doTask ()
    {
        moveN(2);
        turnLeft();
        moveN(2);
        pickBeeper(); // pegar o primeiro marcador
        turnRight();
        doPartialTask(); // pegar o segundo marcador
        doPartialTask(); // pegar o terceiro marcador
        
        // iniciar retorno
        moveN(5);
        turnLeft();
        
        // descarregar os marcadores (repetir 3x)
        for (int m = 0; m < 3; m++)
        {
            move();
            putBeeper();
        }

        // voltar ao inicio e virar-se para o leste
        moveN(2);
        turnLeft();
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
    decorateWorld ( "Guia0113.txt" );
    world->show ( );
    // preparar o ambiente para uso
    world->reset ( );
    // limpar configuracoes
    world->read ( "Guia0113.txt" );// ler configuracao atual para o ambiente
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

*/
