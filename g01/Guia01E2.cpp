/*
 * Guia01E2.cpp - v1.e1 - 13/3/2021
 * Author: Pedro H. Amorim Sá - 742626
 * 
 * Para compilar em um terminal:
 * 
 * No Linux  : g++ -o Guia01E2 ./Guia01E2.cpp
 * No Windows: g++ -o Guia01E2.exe ./Guia01E2.cpp
 * 
 * Para executar em um terminal:
 * 
 * No Linux  : ./Guia01E2
 * No Windows:   Guia01E2
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
    // colocar marcadores no mundo, sendo:
    // 3 marcadores
    world->set ( 5, 2, BEEPER );
    world->set ( 5, 2, BEEPER );
    world->set ( 5, 2, BEEPER );
    // + 2 marcadores
    world->set ( 2, 6, BEEPER );
    world->set ( 2, 6, BEEPER );
    // + 1 marcador
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
    
    /*
      doTask - Relacao de acoes para o robo executar
    */
    void doTask ()
    {
        turnLeft();
        moveN(6);
        turnRight();
        moveN(4);
        // pegar 1 marcador
        pickBeeper();
        turnLeft();
        turnLeft();
        moveN(3);
        turnLeft();
        move();
        // pegar 2 marcadores
        pickBeepers(2);
        moveN(4);
        turnLeft();
        moveN(3);
        // pegar 1 marcador na ultima posicao
        pickBeepers(3);
        move();
        turnLeft();
        moveN(4);
        turnLeft();
        move();
        turnLeft();
        moveN(3);
        // descarregar 6 marcadores
        putBeepers(6);
        // retornar ao inicio
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
    decorateWorld ( "Guia01E2.txt" );
    world->show ( );
    // preparar o ambiente para uso
    world->reset ( );
    // limpar configuracoes
    world->read ( "Guia01E2.txt" );// ler configuracao atual para o ambiente
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
 1.5        01.(OK)     teste pegando marcadores em quantidades decrescentes, descarregando-os e retornando ao inicio, com paredes
 1.e1       01.(OK)     teste conforme v1.5, usando novas funcoes
            02.(OK)     teste da condicao nextToABeeper(), passando 1 marcador a mais como parametro para pickBeepers()
            03.(OK)     teste da condicao estabelecida pelo param n, com 1 marcador a mais em (5,2)
            04.(OK)     teste da teste da condicao nbeepers(), passando 1 marcador a mais como parametro para putBeepers()
            05.(OK)     teste da condicao estabelecida pelo param n, passando 1 marcador a menos para descarregar
 1.e2       01.(OK)     teste usando variacao crescente
*/
