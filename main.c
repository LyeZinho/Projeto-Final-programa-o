#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "menu.h"
#include "func_aux.h"



struct aluno{
  char nome[31];
  char turma[3];
  float notas[4];
  int idade;
  int numero;
  bool status;//Aprovado ou Reprovado
  bool registrado;
  struct aluno *var_proxima;//px 
};

typedef struct aluno ALUNOS;//typedef ALUNOS

ALUNOS *var_inicio;//Inicio das listas
ALUNOS *var_nova_lista;//Var para guardar nova listas (*px)
ALUNOS *var_lista_atual;//var para guardar as endereço das var atual (*seg)
ALUNOS *var_proxima;//Var para marcar o fim da celula e liga listas em listas (*px)




//Pre declaração das funções
int novo_aluno(ALUNOS *inicio_lista);
int nova_lista(int num_extra, ALUNOS *endereco_lista, bool contar_listas);
void ler_dados(ALUNOS* entrada);
//Pre declaração das funções






int main(void) {

  return 0;
}



/*
*📃Função para escrever novo alunos📃
*📌Nome da função: nova_lista
*📌Parametros:
*-> num_extra(quantidade de celulas a criar nota: cada lista tem que ter no minimo 2 celulas) [int]
*-> endereco_lista(endereço da lista que foi criada) [ALUNOS *]
*-> contar_lista(true / false ativa ou desativa a contagem de listas criadas) [bool]
*📌Retorno: caso (bool)contar_listas == true retorna o numero de listas
*/
int nova_lista(int num_extra, ALUNOS *endereco_lista, bool contar_listas){

  //✨Criando a priemira celula da lista
  var_nova_lista = (ALUNOS*) malloc(sizeof(ALUNOS));
  var_inicio = var_nova_lista;
  var_inicio -> var_proxima = var_nova_lista;
  //✨Criando a segunda celula da lista
  var_nova_lista = (ALUNOS*) malloc(sizeof(ALUNOS));
  var_lista_atual = var_nova_lista;
  var_lista_atual -> var_proxima = var_nova_lista;

  int i;
  int qtd_listas;

  if(num_extra != 0){
    
    for(i = 0; i <= num_extra; i++){

      var_nova_lista = (ALUNOS*) malloc(sizeof(ALUNOS));
      var_nova_lista -> registrado = false;

        var_lista_atual = var_nova_lista;

          if(i != num_extra){
            var_lista_atual -> var_proxima = var_nova_lista;
          }
          else if(i == num_extra){
            var_lista_atual -> var_proxima = NULL;
          }
      if(contar_listas == true){
        qtd_listas++;
      }
    }

  }
  return qtd_listas;
  /*To-do
  Fazer testes para verificar a funcionabilidade da função 
  e se caso algo estiver errado concertar
  */
}




/*
*📃Função para ler dados na lista📃
*📌Nome da função: ler_dados
*📌Parametros:entrada (ALUNOS)
*📌Retorno: void
*✨
*/


/*To-do
Completar a função de ler dados 
Status: Não testado pressisa ser testado
*/
void ler_dados(ALUNOS* entrada){
  ALUNOS *var_auxiliar = NULL;
  var_auxiliar = entrada;
  float media;
    do{
      printf("Nome: %s\n", var_auxiliar -> nome);
      printf("Numero: %d\n", var_auxiliar -> numero);
      printf("Idade: %d\n", var_auxiliar -> idade);
      printf("turma: %s\n", var_auxiliar -> turma);
      printf("Notas: \n Periodo 1: %f \n Periodo 2: %f \n Periodo 3: %f \n Periodo 4: %f\n", var_auxiliar -> notas[0],
      var_auxiliar -> notas[1], var_auxiliar -> notas[2], var_auxiliar -> notas[3]);
      media = f_media(var_auxiliar -> notas);
      printf("Media: %f\n", media);
      if(var_auxiliar -> status == true ) printf("Status: Aprovado\n");
      if(var_auxiliar -> status == false) printf("Status: Reprovado\n");
      var_auxiliar = var_auxiliar -> var_proxima;

    }while(var_auxiliar != NULL);
}




/*
*📃Função para ler dados na lista📃
*📌Nome da função: ler_dados
*📌Parametros:entrada (ALUNOS)
*📌Retorno: void
*✨
*/


/*To-do
Completar a função de ler dados 
Status: Não testado pressisa ser testado
*/
void ler_dados_alf(ALUNOS* entrada, char letra){
  ALUNOS *var_auxiliar = NULL;
  var_auxiliar = entrada;
  float media;
    do{
      char caracter = var_auxiliar -> nome[1];
        if(caracter == letra){
          printf("Nome: %s\n", var_auxiliar -> nome);
          printf("Numero: %d\n", var_auxiliar -> numero);
          printf("Idade: %d\n", var_auxiliar -> idade);
          printf("turma: %s\n", var_auxiliar -> turma);
          printf("Notas: \n Periodo 1: %f \n Periodo 2: %f \n Periodo 3: %f \n Periodo 4: %f\n", var_auxiliar -> notas[0],
          var_auxiliar -> notas[1], 
          var_auxiliar -> notas[2],
          var_auxiliar -> notas[3]);
          media = f_media(var_auxiliar -> notas);
          printf("Media: %f\n", media);
          if(var_auxiliar -> status == true ) printf("Status: Aprovado\n");
          if(var_auxiliar -> status == false) printf("Status: Reprovado\n");
          var_auxiliar = var_auxiliar -> var_proxima;
          }

    }while(var_auxiliar != NULL);

}




/*
*📃Função para escrever novo alunos📃
*📌Nome da função: novo_aluno
*📌Parametros: ALUNOS *dados_aluno
*📌Retorno: 0 (int)
*✨ [ https://replit.com/join/ttblpkww-lyezinho1 ] //
*/
int novo_aluno(ALUNOS *inicio_lista){
  ALUNOS *var_auxiliar = NULL;
  var_auxiliar = inicio_lista;

    do{
        if(var_auxiliar -> registrado == false){
    //Nome
            printf("Insira o nome do aluno: \n");
            fgets(var_inicio -> nome, sizeof(var_inicio -> nome), stdin);
    //Turma
            printf("Insira a turma do aluno: \n");
            fgets(var_inicio -> turma, sizeof(var_inicio -> turma), stdin);
    //Idade
            printf("Insira a idade do aluno: \n");
            scanf("%d",&var_inicio -> idade);
    //Numero
            printf("Insira o numero do aluno: \n");
            scanf("%d",&var_inicio -> numero);
    //Notas
            printf("Insira a nota do 1 Periodo: \n");
            scanf("%f",&var_inicio -> notas[0]);
            printf("Insira a nota do 2 Periodo: \n");
            scanf("%f",&var_inicio -> notas[1]);
            printf("Insira a nota do 3 Periodo: \n");
            scanf("%f",&var_inicio -> notas[2]);
            printf("Insira a nota do 3 Periodo: \n");
            scanf("%f",&var_inicio -> notas[2]);
          var_auxiliar = var_auxiliar -> var_proxima;
        }
        else if(var_auxiliar -> registrado == false){
          var_auxiliar = var_auxiliar -> var_proxima;
        }
    }while(var_auxiliar != NULL);
  return 0;
}
