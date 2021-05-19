#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "menu.h"


//Pre declaração das funções

//Pre declaração das funções

struct aluno{
  char nome[31];
  char turma[3];
  float notas[4];
  int idade;
  int numero;
  bool aprovado;
  struct aluno *var_proxima;//px 
};

typedef struct aluno ALUNOS;//typedef ALUNOS

ALUNOS *var_inicio;//Inicio das listas
ALUNOS *var_nova_lista;//Var para guardar nova listas (*px)
ALUNOS *var_lista_atual;//var para guardar as endereço das var atual (*seg)
ALUNOS *var_proxima;//Var para marcar o fim da celula e liga listas em listas (*px)
//--------------------------------------------------------------//
//Main
int main(void) {

  return 0;
}
//--------------------------------------------------------------//






//--------------------------------------------------------------//
/*
*📃Função para escrever novo alunos📃
*
📌Nome da função: novalista
*
📌Parametros:
*
-> num_extra(quantidade de celulas a criar nota: cada lista tem que ter no minimo 2 celulas) [int]
*
-> endereco_lista(endereço da lista que foi criada) [ALUNOS *]
*
-> contar_lista(true / false ativa ou desativa a contagem de listas criadas) [bool]
*
📌Retorno: <retorno da função>
*
✨ [ https://replit.com/join/ttblpkww-lyezinho1 ]
*/


int nova_lista(int num_extra, ALUNOS *endereco_lista, bool contar_listas){

  //✨Criando a priemira celula da lista
  var_nova_lista = (ALUNOS*) malloc(sizeof(ALUNOS));//Aloca uma nova lista
  //📌Sem dado esta criando uma lista vazia
  var_inicio = var_nova_lista;// aux = Inicio
  var_inicio -> var_proxima = var_nova_lista;// Inicio -> px = aux


  //✨Criando a segunda celula
  var_nova_lista = (ALUNOS*) malloc(sizeof(ALUNOS));//aux = maloc() 
  //📌Sem dado esta criando uma lista vazia
  var_lista_atual = var_nova_lista;//seg = aux
  var_lista_atual -> var_proxima = var_nova_lista;//seg -> px = aux


  //📌var_auxiliares
  int i;
  int qtd_listas;

  if(num_extra != 0){
    
    for(i = 0; i <= num_extra; i++){

      var_nova_lista = (ALUNOS*) malloc(sizeof(ALUNOS));//aux = maloc()
        var_lista_atual = var_nova_lista;//seg = aux

          if(i != num_extra){
            var_lista_atual -> var_proxima = var_nova_lista;//seg -> px = aux
          }
          else if(i == num_extra){
            var_lista_atual -> var_proxima = NULL;//seg -> px = NULL 
          }
      if(contar_listas == true){
        qtd_listas++;
      }
    }

  }
  return qtd_listas;
}
//--------------------------------------------------------------//




//--------------------------------------------------------------//
/*
*📃Função para escrever novo alunos📃
*   
📌Nome da função: novo_aluno
📌Parametros:


📌Retorno: <retorno da função>
*
*✨ [ https://replit.com/join/ttblpkww-lyezinho1 ] //
*/


int novo_alun(ALUNOS *dados_aluno){

  printf("Insira o nome do aluno: \n");
  fgets(dados_aluno -> nome, sizeof(dados_aluno -> nome), stdin);//Substituto para o gets();

  printf("Insira a turma do aluno: \n");
  fgets(dados_aluno -> turma, sizeof(dados_aluno -> turma), stdin);//Substituto para o gets();

  //
  printf("Insira a idade do aluno: \n");
  scanf("%d",&dados_aluno -> idade);

  //Numero de aluno
  printf("Insira o numero do aluno: \n");
  scanf("%d",&dados_aluno -> numero);

  //Notas dos 4 periodos
  printf("Insira a nota do 1 Periodo: \n");
  scanf("%f",&dados_aluno -> notas[0]);
  printf("Insira a nota do 2 Periodo: \n");
  scanf("%f",&dados_aluno -> notas[1]);
  printf("Insira a nota do 3 Periodo: \n");
  scanf("%f",&dados_aluno -> notas[2]);
  printf("Insira a nota do 3 Periodo: \n");
  scanf("%f",&dados_aluno -> notas[2]);

  /*
    criar uma função abaixo dessa para fazer a media entre os
    4 bimestres e apos isso o valor (dados_aluno -> aprovao)
    possa passar para true caso o aluno tenha nota na media
    ou passe para false caso tenha nota abaixo da media 
  */
  return 0;
}
//--------------------------------------------------------------//



//--------------------------------------------------------------//




//--------------------------------------------------------------//