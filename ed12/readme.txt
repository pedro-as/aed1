Prezado professor, tive alguns problemas na execução de alguns métodos e
não consegui determinar a causa dos erros. Abaixo, detalho as ocorrências.


method4()
*********
O método executa normalmente. Ao apertar "Enter" após o procedimento pause(),
o seguinte erro é retornado:

free(): double free detected in tcache 2
Aborted (core dumped)


method5()
*********
O método executa normalmente até mostrar as matrizes matrix1 e matrix2.
Depois, retorna o seguinte erro:

free(): double free detected in tcache 2
Aborted (core dumped)


Informações do sistema
**********************
compiler: gcc v: 9.3.0 Distro: Linux Mint 20.1 Ulyssa base: Ubuntu 20.04 focal
