/**
 * Exercicio_A01 - v0.0 - 03/05/2021
 * Author: Pedro H. Amorim Sa - 742626
 */

// dependencias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define bool  int
#define false 0
#define true (!false)

 /*
  Funcao para determinar a casa de Hogwarts.
  Corvinal   [0.7:0.9]
  Grifinória [0.5:0.8]
  Lufa-Lufa  [0.2:0.5]
  Sonserina  [0.1:0.4]
 */
 int Chapeu_Seletor ( double x )
 {
     // CORRECAO: intervalos corrigidos para os limites corretos
     if (0.1 <= x && x <= 0.2)
     {
        return (4);
     }
     else if (0.2 < x && x <= 0.5)
     {
        return (3);
     }
     else if (0.5 < x && x <= 0.7)
     {
        return (2);
     }
     else if (0.7 < x && x <= 0.9)
     {
        return (1);
     }
     else
     {
        return (0);
     }
 }

 /*
   Questao_04.

   Exemplos:
   0.85 -> Corvinal
   0.63 -> Grifinória
   0.39 -> Lufa-Lufa
   0.18 -> Sonserina
 */
 void questao01 ( void )
 {
    double x = 0.0;
    int house = 0;

    printf ( "\nQuestao_01\n" );
    do
    {
      scanf ( "%lf", &x ); getchar( );
      printf ( "\nx = %lf", x );
    }
    while ( x == 0.0 );

    house = Chapeu_Seletor (x);

    if (house == 1)
    {
        printf("\n%lf -> Corvinal", x);
    }
    else if (house == 2)
    {
        printf("\n%lf -> Grifinoria", x);
    }
    else if (house == 3)
    {
        printf("\n%lf -> Lufa-Lufa", x);
    }
    else if (house == 4)
    {
        printf("\n%lf -> Sonserina", x);
    }
    else
    {
        printf("\nErro - (%lf) fora do intervalo", x);
    }
 }

  /*
    Questao_02.

    Exemplos:
    // nao ha' exemplos
  */
 void questao02 ( void )
 {
    int n = 0;
    int n1 = 0;
    int n2 = 0;
    int nm = 0;
    int sum = 0;
    int cat = 0;
    int square = 0;
    int count = 0;

    printf ( "\nQuestao_02\n" );
    for (n = 10000; n < 100000; n++)
    {
        n1 = floor(n / 1000);
        n2 = n % 100;
        nm = floor((n % 1000) / 100);
        sum = n1 + n2;
        cat = (n1 * 100) + n2;
        square = pow(sum, 2);

        if ((cat == square) && (n % 3 != 0) && (n1 > n2) && (nm % 2 != 0))
        {
            printf("\nn = %d", n);
            count = count + 1;
        }
        
    }
    printf("\nTotal de valores -> %d", count);
 }

 /*
   Funcao para contar vogais minusculas.
 */
 int vogais_minusculas ( char cadeia [ ] )
 {
    int vogaisMin = 0;
    int lenCadeia = strlen(cadeia);
    char symbol = '\0';

    for (int i = 0; i < lenCadeia; i++)
    {
      symbol = cadeia[i]; // CORRECAO: variavel atribuida para evitar que o
                          // caractere seja calculado a cada comparacao
      if ((symbol == 'a') || (symbol == 'e') || (symbol == 'i') || 
          (symbol == 'o') || (symbol == 'u'))
      {
          vogaisMin = vogaisMin + 1;
      }
    }

    return ( vogaisMin );
 }

 /*
   Questao_03

   Exemplos:
   abacate ? abacaxi   : 4 = 4 => ""
   melao   ? melancia  : 3 < 4 => "melao"
   banana  ? caju      : 3 > 2 => "caju"
 */
 void questao03 ( void )
 {
    char  sx [ 80 ];
    char  sy [ 80 ];
    int vx = 0;
    int vy = 0;
    
    printf ( "\nQuestao_03\n" );
    scanf  ( "%s", sx );
    scanf  ( "%s", sy );
    printf ( "\nsx = %s", sx );
    printf ( "\nsy = %s", sy );
    
    vx = vogais_minusculas ( sx );
    vy = vogais_minusculas ( sy );

    if (vx > vy)
    {
        printf("\n%s", sx);
    }
    else if (vy > vx)
    {
        printf("\n%s", sy);
    }
    else
    {
        printf("\n ");
    }
 }

/*
  _____________________________________

  ATENCAO: O codigo abaixo contem,
           intencionalmente,
           comandos que NAO funcionam!
  _____________________________________

*/
 bool f ( int x, double y )
 {
    double soma = 0.0;
    double k = 2.0;
    double d = 1.0;
    double res = 0.0;

    while ( x > 0 && 2.0 - soma >= y) // CORRECAO
    {
      soma = soma + 1.0/d;
      d = d + k;
      k = k + 1.0;
      x = x - 1;
    }
    res = 2.0 - soma;

    if (x < 0)
    {
        printf ( "\nLimite estourado!!!\n" );
    }

    return ( res < y );
  }

  /*
    Questao_04.

    Exemplos:
    10->0.5 = true (CERTO)
    10->0.1 = true (ERRADO !!!)
    10->0.00001 = ??? (loop???)
  */
  void questao04 ( void )
  {
    int    x = 0;
    double y = 0.0;
    printf ( "\nQuestao_04\n" );
    scanf  ( "%d", &x );
    scanf  ( "%lf", &y );
    printf ( "\n%d -> %lf", x, y );

    // OBS.: REMOVER O COMENTARIO ABAIXO PARA TESTAR.
    
    printf ( " = %d", f (x,y) );
 }

 /*
   Acao principal
 */
 int main ( void )
 {
     int option = 0;
     printf ( "A01 - 742626 - Pedro Henrique Amorim Sa" );
     do
     {
       printf ( "\n\nOption?\n" );
       scanf  ( "%d", &option ); getchar( );
       printf ( "option = %d", option );
       switch ( option )
       {
         case 0: break;
         case 1: questao01 ( ); break;
         case 2: questao02 ( ); break;
         case 3: questao03 ( ); break;
         case 4: questao04 ( ); break;
       }
     }
     while ( option != 0 );
     return ( 0 );
 }
 
 /*
     Testes e anotacoes
 */
