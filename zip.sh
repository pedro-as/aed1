#!/bin/bash
# AEDZIP - v0.1
# Programa para facilitar e agilizar a compactacao
# de arquivos de exercicios da disciplina de Algoritmos
# e Estruturas de Dados I - ICEI PUC Minas
#
# Instrucoes de utilizacao (somente em Linux):
# O script deve receber permissao para ser executavel
# antes de sua primeira utilizacao, por meio do comando:
# chmod a+x ./zip.sh
#
# Para execucao:
# OPCAO 1:
# ./zip.sh ARQUIVOS
#             V
#          nome e extensao do(s) arquivo(s) a compactar
#
# OPCAO 2:
# Desativar a opcao 1 e ativar os comandos da opcao 2
# Executar no terminal:
# ./zip.sh
#
# Copyleft Pedro Henrique Amorim Sa - 26/mai/2021

# Altere a variavel ID para constar
# sua matricula e seu nome completo

ID="999999_XXX_YYY_ZZZ"

# OPCAO 1
#
# Informar os nomes e extensoes dos
# arquivos na linha de comando
# Ex: ./zip.sh ed00.c io.h DADOS.txt

## INICIO OPCAO 1
zip -v $ID.zip $@
##    FIM OPCAO 1

# OPCAO 2
# Todos os arquivos com as extensoes
# presentes em EXT serao compactadas
# Padrao: '.c', '.h' e '.txt'
# (diferencia maiusculas de minusculas)
#
# O arranjo pode ser modificado para
# incluir ou remover extensoes

################ INICIO OPCAO 2
#EXT=("*.c" "*.h" "*.txt")
#zip -rv $ID.zip . -i /dev/null
#for i in "${EXT[*]}"
#    do zip -vu $ID.zip $i
#done
################    FIM OPCAO 2
