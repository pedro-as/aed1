/**
 * Guia0305.cpp - v0.5 - 27/3/2021
 * Author: Pedro H. Amorim Sa - 742626
 * 
 * Para compilar em um terminal:
 * 
 * No Linux  : g++ -o Guia0305 ./Guia0305.cpp
 * No Windows: g++ -o Guia0305.exe ./Guia0305.cpp
 * 
 * Para executar em um terminal:
 * 
 * No Linux  : ./Guia0305
 * No Windows:   Guia0305
 * 
 */

// lista de dependencias
#include "karel.hpp"
#include "io.hpp"

// --------------------------- definicoes de metodos
/**
 * decorateWorld - Metodo para preparar o cenario
 * @param fileName - nome do arquivo para guardar a descricao
 */
void decorateWorld(const char* fileName)
{
    // colocar paredes no mundo
    world->set(4, 4, VWALL);
    world->set(4, 4, HWALL);

    // colocar um marcador no mundo
    world->set(4, 4, BEEPER);

    // salvar a configuracao atual do mundo
    world->save(fileName);
}

/**
 * Classe para definir robo particular (MyRobot),
 * a partir do modelo generico (Robot)
 *
 * Nota: todas as definicoes irao valer para qualquer outro robo
 * criado a partir dessa nova descricao de modelo.
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

    /**
     * moveN - Metodo para mover certa quantidade de passos
     * @param steps - passos a serem dados
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

    /**
     * countCommands - Metodo para contar comandos do arquivo
     * @return quantidade de comandos
     * @param fileName - nome do arquivo
     */
    int countCommands(const char *fileName)
    {
        // definir dados
        int x = 0;
        int length = 0;
        
        // abrir arquivo para leitura
        std::ifstream archive(fileName);
        
        // repetir enquanto houver dados
        archive >> x;
        while (! archive.eof())
        {
            // contar mais um comando
            length++;
            // tentar ler a proxima linha
            archive >> x;
        }
        // fechar o arquivo
        archive.close();

        // retornar resultado
        return (length);
    }
    /**
     * readCommands - Metodo para contar comandos do arquivo
     * @return grupo formado por todos os comandos
     * @param fileName - nome do arquivo
     */
    int readCommands(int commands[], const char *fileName)
    {
        // definir dados
        int x = 0;
        int action = 0;
        int length = 0;
        std::ifstream archive(fileName);

        // obter a quantidade de comandos
        length = countCommands(fileName);

        // criar um armazenador para os comandos
        if (length < MAX_COMMANDS)
        {
            for (x; x < length; x++)
            {
                // tentar ler a proxima linha
                archive >> action;
                // guardar um comando
                // na posicao (x) do armazenador
                commands[x] = action;
            }
            // fechar o arquivo
            archive.close();
        }
        // retornar quantidade de comandos lidos
        return (length);
    }

    /**
     * execute - Metodo para executar um comando
     * @param option - comando a ser executado
     */
    void execute(int option)
    {
        // executar a opcao de comando
        switch(option)
        {
            case 0: // terminar
                // nao fazer nada
                break;
            case 1: // virar para a esquerda
                if (leftIsClear())
                {
                    turnLeft();
                }
                break;
            case 2: // virar para o sul
                while (! facingSouth())
                {
                    turnLeft();
                }
                break;
            case 3: // virar para a direita
                if (rightIsClear())
                {
                    turnRight();
                }
                break;
            case 4: // virar para o oeste
                while (! facingWest())
                {
                    turnLeft();
                }
                break;
            case 5: // mover
                if(frontIsClear())
                {
                    move();
                }
                break;
            case 6: // virar para o leste
                while (! facingEast())
                {
                    turnLeft();
                }
                break;
            case 7: // pegar marcador
                if (nextToABeeper())
                {
                    pickBeeper();
                }
                break;
            case 8: // virar para o norte
                while (! facingNorth())
                {
                    turnLeft();
                }
                break;
            case 9: // colocar marcador
                if (beepersInBag())
                {
                    putBeeper();
                }
                break;
            default: // nenhuma das alternativas anteriores
                // comando invalido
                show_Error("ERROR: invalid command");
        }
    }

    /**
     * doCommands - Metodo para executar comandos do arquivo
     * @param length - quantidade de comandos
     * @param commands - grupo de comandos para executar
     */
    void doCommands(int length, int commands[])
    {
        // definir dados
        int action = 0;
        int x = 0;

        // repetir a quantidade de comandos
        for (x; x < length; x++)
        {
            // executar esse comando
            execute(commands[x]);
        }
    }

    /**
     * doTask - Metodo para executar comandos de arquivo
     * @param fileName - nome do arquivo
     */
    void doTask(const char *fileName)
    {
        // definir dados
        int quantidade = 0;
        int comandos[MAX_COMMANDS];
        char message[80];

        // ler quantidade e comandos
        quantidade = readCommands(comandos, "Tarefa0301.txt");
        message[0] = '\0'; // limpar mensagem
        sprintf(message, "Commands = %d", quantidade);
        show_Text(message);

        // executar comandos
        doCommands(quantidade, comandos);
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
    decorateWorld("Guia0305.txt");
    world->show();

    // preparar o ambiente para uso
    world->reset();               // limpar configuracoes
    world->read("Guia0305.txt");  // ler configuracao atual para o ambiente
    world->show();                // mostrar a configuracao atual

    set_Speed(3);                 // definir velocidade padrao

    // criar robo
    MyRobot *robot = new MyRobot();

    // posicionar robo no ambiente (situacao inicial):
    // posicao (x=1, y=1), voltado para direita,
    // com zero marcadores, nome escolhido)
    robot->create(1, 1, NORTH, 0, "Karel");

    // executar tarefa
    robot->doTask("Tarefa0301.txt");

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
 0.1     01. (OK)    identificacao de programa
 0.2     01. (OK)    teste com retorno na funcao countCommands()
 0.3     01. (OK)    teste com metodo readCommands()
 0.4     01. (OK)    teste com metodo doCommands()
*/
