#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "menu.h"
#include "func_aux.h"
#include "main.c"


//Pre declaração das funções
void func_menu();
void func_list();
//Pre declaração das funções




void func_menu(){
int opcao;

  do{
      printf("Menu\n");
      printf("1 = Inserir dados do aluno.\n");
      printf("2 = Calculo da média final do aluno.\n");
      printf("3 = Listar os dados dos alunos.\n");
      printf("4 = algo.\n");
      printf("0 = Sair\n");

      switch(opcao){
        case 1:
          //faz algo
            break;
        case 2:
          //faz algo
            break;
        case 3:
          //faz algo
            break;
        case 4:
          //faz algo
            break;
        default: 
          printf("Digite uma opção valida");
            break;
      }
  }while(opção != 0)

}



//✨Funções para listagem
void func_list(){
int opcao;
//To do fazer funções para fazer listagem especificas
  do{
      printf("Listagem de usuarios\n");
      printf("1 = Mostrar usuarios especificos\n");
      printf("2 = Listar todos os usuarios\n");
      printf("4 = Sair\n");

      switch(opcao){
        case 1:
          //faz algo
            break;
        case 2:
          //faz algo
            break;
        default: 
          printf("Digite uma opção valida");
            break;
      }
  }while(opção != 0)
func_menu();
}

void func_list_espec(){
int opcao;

  do{
      printf("Menu\n");
      printf("1 = Listar usuario por letra \n");
      printf("2 = Listar usuario por numero\n");
      printf("3 = Mostrar usuario por nome\n");
      printf("0 = Sair\n");

      switch(opcao){
        case 1:
          //Fun list por 
            break;
        case 2:
          //faz algo
            break;
        case 3:
          //faz algo
            break;
        default: 
          printf("Digite uma opção valida");
            break;
      }
  }while(opção != 0)

}


void func_list(){
int opcao;
//To do fazer funções para fazer listagem especificas
  do{
      printf("Listagem de usuarios\n");
      printf("1 = Mostrar um usuario especifico\n");
      printf("2 = Listar todos os usuarios\n");
      printf("3 = Mostrar os usuarios por letra\n");
      printf("4 = Sair\n");

      switch(opcao){
        case 1:
          //faz algo
            break;
        case 2:
          //faz algo
            break;
        case 3:
          //faz algo
            break;
        case 4:
          //faz algo
            break;
        default: 
          printf("Digite uma opção valida");
            break;
      }
  }while(opção != 0)

}
//✨Funções para listagem