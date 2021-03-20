/**
  * Guia0210.cpp - v1.0 - 18/3/2021
  * Author: Pedro H. Amorim Sa - 742626
  * 
  * Para compilar em um terminal:
  * 
  * No Linux  : g++ -o Guia02E2 ./Guia02E2cpp
  * No Windows: g++ -o Guia02E2.exe ./Guia0210.cpp
  * 
  * Para executar em um terminal:
  * 
  * No Linux  : ./Guia0210
  * No Windows:   Guia0210
  * 
  */

// lista de dependencias
#include "karel.hpp"
#include "io.hpp"    // para entradas e saidas

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
    /**
     * turnRight - Procedimento para virar 'a direita
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
     * doPartialTask - Metodo para especificar parte de uma tarefa
     */
    void doPartialTask()
    {
        // especificar acoes dessa parte da tarefa
        moveN(3);
        turnLeft();
    }
    /**
     * pickBeepers() - Metodo para coletar marcadores
     */
    int pickBeepers()
    {
        // definir dado local
        int n = 0;

        // repetir (com teste no inicio)
        // enquanto houver marcador proximo
        while (nextToABeeper())
        {
            // coletar um marcador
            pickBeeper();
            // contar mais um marcador coletado
            n++;
        }
        // retornar a quantidade de marcadores coletados
        return(n);
    }

    /**
     * doSquare - Metodo para especificar outro percurso
     */
    void doSquare()
    {
        // definir dado local
        int step = 1;
        int n = 0;

        // especificar acoes da tarefa
        while (step <= 4)
        {
            // realizar uma parte da tarefa
            moveN(3);
            n = pickBeepers();
            // testar se quantidade maior que zero
            if (n > 0)
            {
                // montar a mensagem para a saida
                sprintf(msg_txt, "Recolhidos = %d", n);
                // agendar a exibicao
                has_Text = true;
            }
            turnRight();
            // tentar passar 'a proxima
            step++;
        }
        turnOff();
    }

    /**
     * doTask - Relacao de acoes para o robo executar
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
     * moveI - Metodo para mover o robo interativamente
     * Lista de comandos disponiveis:
     * 0 - turnOff
     * 1 - turnLeft                2 - toSouth
     * 3 - turnRight               4 - toWest
     * 5 - move                    6 - toEast
     * 7 - pickBeeper              8 - toNorth
     * 9 - putBeeper
     */
    void moveI()
    {
        // definir dados
        int action;

        // repetir (com testes no fim)
        // enquanto opcao diferente de zero
        do
        {
            // ler opcao
            action = IO_readint("Command? ");

            // executar acao dependente da opcao
            execute(action);
        } while (action != 0);
    }

    /**
     * recordActions - Metodo para mover o robo interativamente
     * e guardar a descricao da tarefa em arquivo
     * @param fileName - nome do arquivo
     */
    void recordActions(const char *fileName)
    {
        // definir dados
        int action;
        // definir arquivo onde gravar comandos
        std::ofstream archive(fileName);
        // ler acao
        action = IO_readint("Command? ");
        // repetir enquanto diferente de 0
        while (action != 0)
        {
            // testar se opcao valida
            if (0 <= action && action <= 9)
            {
                // executar comando
                execute(action);
                // guardar o comando em arquivo
                archive << action << "\n";
            }
            // ler acao
            action = IO_readint("Command? ");
        }
        // fechar o arquivo
        archive.close();
    }
    /**
     * playActions - metodo para receber comandos de arquivo
     * @param fileName - nome do arquivo
     */
    void playActions(const char *fileName)
    {
        // definir dados
        int action;
        // definir arquivos de onde ler dados
        std::ifstream archive(fileName);

        // repetir enquanto houver dados
        archive >> action; // tentar ler a primeira linha
        while (! archive.eof()) // testar se nao encontrado o fim
        {
            // mostrar mais um comando
            IO_print(IO_toString(action));
            delay(stepDelay);
            // executar mais um comando
            execute(action);
            // tentar ler a proxima linha
            archive >> action; // tentar ler a proxima linha
        }
        // fechar o arquivo
        archive.close();
    }

    /**
     * dictionary - Metodo para traduzir um comando
     * @param action - comando a ser traduzido
     */
    chars dictionary(int action)
    {
        // definir dado
        static char word[80];
        strcpy(word, ""); // palavra vazia
        // identificar comando
        switch (action)
        {
            case 1: // virar para a esquerda
                strcpy(word, "turnLeft();");
                break;
            case 2: // virar para o sul
                strcpy(word, "faceSouth();");
                break;
            case 3: // virar para a direita
                strcpy(word, "turnRight();");
                break;
            case 4: // virar para o oeste
                strcpy(word, "faceWest();");
                break;
            case 5: // mover
                strcpy(word, "move();");
                break;
            case 6: // virar para o leste
                strcpy(word, "faceEast();");
                break;
            case 7: // pegar marcador
                strcpy(word, "pickBeeper();");
                break;
            case 8: // virar para o norte
                strcpy(word, "faceNorth();");
                break;
            case 9: // colocar marcador
                strcpy(word, "putBeeper();");
                break;
        }
        // retornar a palavra equivalente
        return(&(word[0]));
    }

    /**
     * translateActions - Metodo para receber comandos de arquivo e traduzi-los
     * @param fileName - nome do arquivo
     */
    void translateActions(const char *fileName)
    {
        // definir dados
        int action;
        // definir arquivo de onde ler dados
        std::ifstream archive(fileName);

        // repetir enquanto houver dados
        archive >> action; // tentar ler a primeira linha
        while (! archive.eof()) // testar se nao encontrado o fim
        {
            // tentar traduzir um comando
            IO_print(dictionary(action));
            getchar();
            // guardar mais um comando
            execute(action);
            // tentar ler a proxima linha
            archive >> action;
        }
        // fechar o arquivo
        archive.close();
    }

    /**
     * appendActions - Metodo para acrescentar comandos ao
     *                 arquivo e traduzi-los
     * @param fileName - nome do arquivo
     */
    void appendActions(const char *fileName)
    {
        // definir dados
        int action;
        // definir arquivo para receber acrescimos ao final
        std::fstream archive(fileName, std::ios::app);

        // repetir enquanto acao diferente de zero
        do
        {
            // ler acao
            action = IO_readint("Command? ");
            // testa se opcao valida
            if (0 <= action && action <= 9)
            {
                // executar comando
                execute(action);
                // guardar o comando em arquivo
                archive << action << "\n";
            }
        } while (action != 0);
        // fechar o arquivo
        archive.close();
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
    decorateWorld("Guia0210.txt");
    world->show();

    // preparar o ambiente para uso
    world->reset();               // limpar configuracoes
    world->read("Guia0210.txt");  // ler configuracao atual para o ambiente
    world->show();                // mostrar a configuracao atual

    set_Speed(3);                 // definir velocidade padrao

    // criar robo
    MyRobot *robot = new MyRobot();

    // posicionar robo no ambiente (situacao inicial):
    // posicao (x=1, y=1), voltado para direita,
    // com zero marcadores, nome escolhido)
    robot->create(1, 1, NORTH, 0, "Karel");

    // executar tarefa
    robot->recordActions("Tarefa0210.txt");

    // dar uma pausa na entrada de comandos
    show_Text("Pause on recording");

    // mostrar configuracao atual do mundo
    world->show();

    // retomar a entrada de comandos
    robot->appendActions("Tarefa0210.txt");

    // reproduzir todos os comandos
    robot->playActions("Tarefa0210.txt");

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
Versao 0.2, teste 01: o robo nao consegue completar a acao se
parte de (1, 1), ja que e' bloqueado ao tentar virar 'a direita.
------------------------------------ historico
Versao    Data    Modificacao
 0.1     19/3/21    esboco
------------------------------------ testes
Versao    Teste
 0.1     01. (OK)    teste inicial
 0.2     01. (OK)    teste da repeticao de virar 'a direita
 0.3     01. (OK)    teste da repeticao para percorrer um quadrado
 0.4     01. (OK)    teste pegando marcadores
 0.5     01. (OK)    teste exibindo numero de marcadores capturados
 0.6     01. (OK)    teste controlando o robo com comandos interativos
 0.7     01. (OK)    teste controlando o robo e gravando acoes
 0.8     01. (OK)    teste gravando tarefa e reproduzindo-a a seguir
 0.9     01. (OK)    teste gravando tarefa e traduzindo-as a seguir
 1.0     01. (OK)    teste gravando tarefa e traduzindo-as a seguir
*/
