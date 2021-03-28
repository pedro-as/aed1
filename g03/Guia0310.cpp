/**
 * Guia0310.cpp - v1.0 - 27/3/2021
 * Author: Pedro H. Amorim Sa - 742626
 * 
 * Para compilar em um terminal:
 * 
 * No Linux  : g++ -o Guia0310 ./Guia0310.cpp
 * No Windows: g++ -o Guia0310.exe ./Guia0310.cpp
 * 
 * Para executar em um terminal:
 * 
 * No Linux  : ./Guia0310
 * No Windows:   Guia0310
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
    // world->set(4, 4, VWALL);
    // world->set(4, 4, HWALL);

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

    /**
     * mapWorld - Metodo para o robo explorar o mundo
     * @param map - arranjo bidimensional (matriz)
     *              onde guardar o mapa
     */
    void mapWorld(int map [][WIDTH])
    {
        // definir dados locais
        int avenue = 0;
        int street = 0;
        int beepers = 0;
        char message[80];
        
        // correcao para funcionamento esperado
        /*
        // obter o tamanho do mundo, se existir
        if (world != nullptr)
        {
            // informar o tamanho do mundo
            message[0] = '\0'; // limpar a mensagem
            sprintf(message, "World is %dx%d",
                    world->avenues(), world->streets());
            show_Text(message);
        }
        */

        // percorrer o mundo procurando marcadores
        for (street = 1; street <= world->streets(); street++)
        {
            for (avenue = 1; avenue <= world->avenues(); avenue++)
            {
                // limpar posicao no mapa
                map[street - 1][avenue - 1] = 0;
                // se proximo a um marcador
                if (nextToABeeper())
                {
                    // informar marcador nessa posicao
                    message[0] = '\0';
                    sprintf(message, "Beeper at (%d,%d)", avenue, street);
                    show_Text(message);
                    // marcar posicao no mapa
                    map[street - 1][avenue - 1] = 1;
                    // encontrado mais um marcador
                    beepers++;
                }
                // mover para a proxima posicao
                if (avenue < world->avenues())
                {
                    move();
                }
                else // correcao para funcionamento esperado
                {
                    turnLeft();
                    turnLeft();
                    moveN(world->avenues() - 1);
                }
                /*
                turnLeft();
                turnLeft();
                moveN(world->avenues() - 1);
                if (street < world->streets())
                {
                    turnRight();
                    move();
                    turnRight();
                }
                */
            }
            // correcao para funcionamento esperado
            if (street < world->streets())
                {
                    turnRight();
                    move();
                    turnRight();
                }
        }
    }

    /**
     * saveMap - Metodo para guardar um mapa em arquivo
     * @param fileName - nome do arquivo onde guardar o mapa
     * @param map - arranjo bidimensional (matriz) com o mapa
     */
    void saveMap(const char *fileName, int map[][WIDTH])
    {
        // definir dados locais
        int avenue = 0;
        int street = 0;
        // abrir arquivo para gravacao
        std::ofstream archive(fileName);

        // testar se ha' informacao
        if (world != nullptr)
        {
            // guardar o tamando do mundo
            archive << world->avenues() << "\n";
            archive << world->streets() << "\n";

            // percorrer o mundo procurando beepers
            for (street = 1; street <= world->streets(); street++)
            {
                for (avenue = 1; avenue <= world->avenues(); avenue++)
                {
                    // guardar informacao no arquivo
                    if (map[street - 1][avenue - 1] == 1)
                    {
                        archive << avenue << std::endl;
                        archive << street << std::endl;
                        archive << map[street - 1][avenue - 1] << std::endl;
                    }
                }
            }
            // fechar arquivo
            archive.close();
        }
    }

    /**
     * showMap - Metodo para ler um mapa em arquivo
     * @param avenues - largura do mapa
     * @param streets - altura do mapa
     * @param map - arranjo bidimensional (matriz) com o mapa
     */
    void showMap(int avenues, int streets, char map[][HEIGHT])
    {
        // definir dados
        int x = 0;
        int y = 0;

        // percorrer o mundo procurando marcadores
        clrscr();
        std::cout << " Mapa de marcadores\n\n";

        std::cout << " ";
        for (x = 0; x < streets; x++)
        {
            std::cout << (x + 1);
        }
        std::cout << std::endl;
        for (y = 0; y < streets; y++)
        {
            std::cout << (y + 1);
            for(x = 0; x < avenues; x++)
            {
                std::cout << map[y][x];
            }
            std::cout << std::endl;
        }
        IO_pause (" Apertar ENTER para continuar.");
    }

    /**
     * readMap - Metodo para ler um mapa em arquivo
     * @param fileName - nome do arquivo com o mapa
     */
    void readMap(const char *fileName)
    {
        // definir dados
        int avenue = 0;
        int street = 0;
        int avenues = 0;
        int streets = 0;
        int x = 0;
        int y = 0;
        int z = 0;

        std::ifstream archive(fileName);

        // reservar area para guardar o maior mapa possivel
        char map[WIDTH][HEIGHT];

        // obter o tamanho do mundo
        archive >> avenues;
        archive >> streets;

        // testar configuracao do mapa
        if((0 < avenues && avenues <= world->width) &&
           (0 < streets && streets <= world->height))
        {
            // percorrer o mundo procurando marcadores
            for (y = 0; y < streets; y++)
            {
                for (x = 0; x < avenues; x++)
                {
                    map[y][x] = '.';
                }
            }

            // repetir enquanto houver dados
            archive >> avenue; // tentar ler a primeira linha
            while (! archive.eof())
            {
                // contar mais um comando
                archive >> street;
                archive >> z;
                // testar se informacoes validas
                if((1 <= avenue && avenue <= world->width) &&
                   (1 <= street && street <= world->height) &&
                   (z == 1))
                {
                    map[street - 1][avenue - 1] = 'X';
                }
                archive >> avenue; // tentar ler a proxima linha
            }
            // fechar o arquivo
            archive.close();

            // mostrar o mapa
            showMap(avenues, streets, map);
        }
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
    decorateWorld("Guia0310.txt");
    world->show();

    // preparar o ambiente para uso
    world->reset();               // limpar configuracoes
    world->read("Guia0310.txt");  // ler configuracao atual para o ambiente
    world->show();                // mostrar a configuracao atual

    set_Speed(1);                 // definir velocidade padrao

    // criar robo
    MyRobot *robot = new MyRobot();

    // posicionar robo no ambiente (situacao inicial):
    // posicao (x=1, y=1), voltado para direita,
    // com zero marcadores, nome escolhido)
    robot->create(1, 1, EAST, 0, "Karel");

    // definir armazenador para o mapa
    int map[HEIGHT][WIDTH]; // altura x largura

    // executar tarefas
    robot->mapWorld(map);
    robot->saveMap("Mapa0310.txt", map);
    robot->readMap("Mapa0310.txt");

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
 0.5     01. (OK)    teste com metodo doTask()
 0.6     01. (OK)    teste com metodo mapWorld()
 0.7     01. (NE)    teste procurando marcadores com mapWorld()
 0.7.1   01. (OK)    teste procurando marcadores com mapWorld(), corrigido
 0.8     01. (OK)    teste com metodo mapWorld() incrementado
 0.9     01. (OK)    teste com metodo saveMap()
 1.0     01. (OK)    teste com metodo readMap()
*/
