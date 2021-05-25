#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define _EXIT_CONST 923123
#define arrSize(entrada) sizeof(entrada)/sizeof(entrada[0])

struct alunos{
  char nome[101];
  char turma[3];
  float notas[4];
  int idade;
  int numero;
  bool status;//Aprovado ou Reprovado
  int registrado;
  struct alunos *var_proxima;//px 
};

typedef struct alunos ALUNOS;//typedef ALUNOS

ALUNOS *var_inicio;//Inicio das listas
ALUNOS *var_nova_lista;//Var para guardar nova listas (*px)
ALUNOS *var_lista_atual;//var para guardar as endereço das var atual (*seg)
ALUNOS *var_proxima;//Var para marcar o fim da celula e liga listas em listas (*px)


//Pre declaração das funções
int novo_aluno(ALUNOS *inicio_lista);
int nova_lista(int num_extra, bool contar_listas);
void aumentar_lista(ALUNOS *entrada, int num_listas);
void ler_dados(ALUNOS* entrada);
void ler_dados_alf(ALUNOS* entrada, char letra);
void ler_dados_num(ALUNOS* entrada, int busca_numero);
void ler_dados_nom(ALUNOS* entrada, char *busca_nome);
void func_del_list(ALUNOS *entrada, char numero_celula);
bool f_media(float *dados);
void purge();
void getstring(char *out);
void change(bool *input, ALUNOS *entrada);
//Pre declaração das funções



//Pre declaração das interfaces
void func_menu();
void func_gest_dados();
void func_list_dados();
void func_gest_list();
//Pre declaração das interfaces




int main(void) {
  func_menu();
  return 0;
}



//Função inutulizada 
/*
*📃Função para escrever novo alunos📃
*📌Nome da função: nova_lista
*📌Parametros:
*-> num_extra(quantidade de celulas a criar nota: cada lista tem que ter no minimo 2 celulas) [int]
*-> endereco_lista(endereço da lista que foi criada) [ALUNOS *]
*-> contar_lista(true / false ativa ou desativa a contagem de listas criadas) [bool]
*📌Retorno: caso (bool)contar_listas == true retorna o numero de listas
*/

/*
Erro atual incomplete type 'ALUNOS' (aka 'struct aluno')
*/

int nova_lista(int num_extra, bool contar_listas){

  //✨Criando a priemira celula da lista
  var_nova_lista = (ALUNOS* ) malloc( sizeof(ALUNOS) );
  var_inicio = var_nova_lista;
  var_inicio -> var_proxima = var_nova_lista;

  //✨Criando a segunda celula da lista
  var_nova_lista = (ALUNOS*) malloc(sizeof(ALUNOS*));
  var_lista_atual = var_nova_lista;
  var_lista_atual -> var_proxima = var_nova_lista;

  int i;
  int qtd_listas;

  if(num_extra != 0){
    
    for(i = 0; i <= num_extra; i++){

      var_nova_lista = (ALUNOS*) malloc(sizeof(ALUNOS));
      var_nova_lista -> registrado = 0;

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
void ler_dados(ALUNOS *entrada){
  ALUNOS *var_auxiliar = NULL;
  var_auxiliar = entrada;
  int controle;
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
      scanf("%d", &controle);
      func_list_dados();
    }while(var_auxiliar != NULL);
}




/*
*📃Função para ler dados na lista de uma letra📃
*📌Nome da função: ler_dados_alf
*📌Parametros:entrada (ALUNOS) letra (char)
*📌Retorno: void
*✨
*/
/*To-do
Completar a função de ler dados 
Status: Não testado pressisa ser testado
Fazer fluxograma
*/
void ler_dados_alf(ALUNOS* entrada, char busca_letra){
  ALUNOS *var_auxiliar = NULL;
  var_auxiliar = entrada;
  int controle;
  float media;
    do{

        if(var_auxiliar -> nome[1] == busca_letra){
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
          scanf("%d", &controle);
          func_list_dados();
          }
        else if(var_auxiliar -> nome[1] != busca_letra){
          var_auxiliar = var_auxiliar -> var_proxima;
        }
    }while(var_auxiliar != NULL);

}




/*
*📃Função para ler dados na lista de um numero📃
*📌Nome da função: ler_dados_num
*📌Parametros:entrada (ALUNOS) num (char)
*📌Retorno: void
*✨
*/
/*To-do
Completar a função de ler dados 
Status: Não testado pressisa ser testado
Fazer fluxograma
*/
void ler_dados_num(ALUNOS* entrada, int busca_numero){
  ALUNOS *var_auxiliar = NULL;
  var_auxiliar = entrada;
  int controle;
  float media;
    do{
        if(var_auxiliar -> numero == busca_numero){
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
          scanf("%d", &controle);
          func_list_dados();
          }
        else if(var_auxiliar -> numero != busca_numero){
          var_auxiliar = var_auxiliar -> var_proxima;
        }

    }while(var_auxiliar != NULL);

}




/*
*📃Função para ler dados na lista de um nome📃
*📌Nome da função: ler_dados_num
*📌Parametros:entrada (ALUNOS) num (char)
*📌Retorno: void
*✨
*/
/*To-do
Completar a função de ler dados 
Status: Não testado pressisa ser testado
Fazer fluxograma
*/
void ler_dados_nom(ALUNOS* entrada, char *busca_nome){
  ALUNOS *var_auxiliar = NULL;
  var_auxiliar = entrada;
  int controle;
  float media;
  int string;
    do{
      string = strcmp(var_auxiliar -> nome, busca_nome);
        if(string == 0){
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
          scanf("%d", &controle);
          func_list_dados();
          }
        else if(string != 0){
          var_auxiliar = var_auxiliar -> var_proxima;
        }

    }while(var_auxiliar != NULL);

}




/*
*📃Função para escrever novo alunos📃
*📌Nome da função: novo_aluno
*📌Parametros: ALUNOS *dados_aluno
*📌Retorno: 0 (int)
*/
int novo_aluno(ALUNOS *inicio_lista){
  ALUNOS *var_auxiliar = NULL;
  var_auxiliar = inicio_lista;
  int controle;
    do{
        if(var_auxiliar -> registrado == 0){
            purge();
            printf("Novo usuario?\n 1 -> sim \n 0 -> nao\n");
            scanf("%d", &controle);
            if(controle == false) func_gest_dados();
            if(controle == true){
              //Nome
              purge();
              printf("Insira o nome do aluno: \n");
              scanf("%s", var_auxiliar -> nome);
              //Turma
              printf("Insira a turma do aluno: \n");
              scanf("%s", var_auxiliar -> turma);
              //Idade
              printf("Insira a idade do aluno: \n");
              scanf("%d",&var_auxiliar -> idade);
              //Numero
              printf("Insira o numero do aluno: \n");
              scanf("%d",&var_auxiliar -> numero);
              //Notas
              printf("Insira a nota do 1 Periodo: \n");
              scanf("%f",&var_auxiliar -> notas[0]);
              printf("Insira a nota do 2 Periodo: \n");
              scanf("%f",&var_auxiliar -> notas[1]);
              printf("Insira a nota do 3 Periodo: \n");
              scanf("%f",&var_auxiliar -> notas[2]);
              printf("Insira a nota do 4 Periodo: \n");
              scanf("%f",&var_auxiliar -> notas[3]);
              var_auxiliar = var_auxiliar -> var_proxima;
            }
        }
        else if(var_auxiliar -> registrado == 1){
          var_auxiliar = var_auxiliar -> var_proxima;
        }
    }while(var_auxiliar != NULL);
  return 0;
}




/*
*📃Função para crescer lista📃
*📌Nome da função: size_list
*📌Parametros: ALUNOS *dados_aluno
*📌Retorno: 0 (int)
*/
//To do testar função caso tenha erro corrigir
void aumentar_lista(ALUNOS *entrada, int num_listas){
  
  int i;
  if(entrada -> var_proxima == NULL){
      for(i = 0; i <= num_listas; i++){
        var_nova_lista = (ALUNOS*) malloc(sizeof(ALUNOS));
        var_lista_atual = entrada;
        var_lista_atual -> var_proxima = var_nova_lista;
        var_nova_lista -> var_proxima = var_proxima;
      if(i == num_listas){
        var_lista_atual -> var_proxima = NULL;
      }
    }
  }
}

/*
*📃Função para deletar uma celula de uma lista📃
*📌Nome da função: func_del_list (ALUNOS)
*📌Parametros:entrada (ALUNOS) letra (char)
*📌Retorno: void
*✨
*/
void func_del_list(ALUNOS *entrada, char numero_celula){
  
  ALUNOS *var_mov = entrada;
  ALUNOS *var_anterior = NULL;
  ALUNOS *var_del = NULL;
  ALUNOS *var_prox = NULL;
  //var_proxima == px
  //var_prox endereco da proxima celula apenas nesta fução
  do{
    var_anterior = var_mov;
    var_mov = var_mov -> var_proxima;
    //
    if(var_mov -> numero == numero_celula){
      var_del = var_mov;//Celula atual e salva para ser deletada
      var_mov = var_mov -> var_proxima;//Avança pra proxima 
      var_prox = var_mov;//Salva o endereco da atual/proxima
        var_anterior -> var_proxima = var_prox -> var_proxima;
        free(var_del);
    }
  }while(var_mov -> var_proxima != NULL);
}




//Interfaces para menu principal
void func_menu(){
  int opcao;
  int num_cell;
  do{
      
      purge();
      printf("-------------(Menu)-------------\n");
      printf("1 = Inserir dados do aluno.\n");
      printf("2 = Gerir dados dos alunos.\n");
      printf("3 = Listar os dados dos alunos.\n");
      printf("0 = Sair\n");
      printf("--------------------------------\n");
      scanf("%d", &opcao);
      switch(opcao){
        case 1:
            func_gest_dados();
            break;
        case 2:
            func_gest_dados();
            break;
        case 3:
            func_list_dados();
            break;
        case 0:
            purge();
            printf("Finalizado!\n");
            break;
        default:
          purge();
          printf("Digite uma opção valida\n");
          scanf("%d", &num_cell);
            break;
      }
  }while(opcao != 0);
}

void func_gest_dados(){
  int opcao;
  int num_cell;
  int var_pause;

  do{
      num_cell = 0;
      purge();
      printf("-------------(Menu)-------------\n");
      printf("1 = Nova lista.\n");
      printf("2 = Inserir novo aluno.\n");
      printf("0 = voltar\n");
      printf("--------------------------------\n");
      scanf("%d", &opcao);
      switch(opcao){
        case 1:
              purge();
          	  printf("Quantas celulas?\n");
              scanf("%d", &num_cell);
              //Apenas mudar para true caso for testar
              num_cell = nova_lista(num_cell, false);
              func_gest_dados();
            break;
        case 2:
            purge();
            novo_aluno(var_inicio);
            func_gest_dados();
            break;
        case 0:
          func_menu();
            break;
        default:
          purge();
          printf("Digite uma opção valida\n");
          scanf("%d", &num_cell);
            break;
      }
  }while(opcao != _EXIT_CONST);
}

void func_list_dados(){
  int opcao;
  int num_cell;
  int var_pause;
  char nome[101];
  char letra;

  do{
    num_cell = 0;
      purge();
      printf("-------------(Menu)-------------\n");
      printf("1 = Listar todos os alunos.\n");
      printf("2 = Listar dados de um numero\n");
      printf("3 = Listar dados de um nome.\n");
      printf("4 = Listar dados por uma letra.\n");
      printf("0 = voltar\n");
      printf("--------------------------------\n");
      scanf("%d", &opcao);
      switch(opcao){
        case 1:
              purge();
              ler_dados(var_inicio);
              scanf("%d", &num_cell);
              func_list_dados();
            break;
        case 2:
              purge();
              printf("Digite um numero a ser listado: \n");
              scanf("%d", &num_cell);
              ler_dados_num(var_inicio, num_cell);
              scanf("%d", &num_cell);
              func_list_dados();
            break;
        case 3:
            purge();
            printf("Digite um nome a ser listado: \n");
            scanf("%s", nome);
            ler_dados_nom(var_inicio, nome);
            scanf("%d", &num_cell);
            func_list_dados();
            break;
        case 4:
            purge();
            printf("Digite uma letra a ser listada\n");
            scanf("%c", &letra);
            ler_dados_alf(var_inicio, letra);
            scanf("%d", &num_cell);
            func_list_dados();
        case 0:

            break;
        default: 
          purge();
          printf("Digite uma opção valida");
          scanf("%d", &num_cell);
            break;
      }
  }while(opcao != _EXIT_CONST);
}


//Faz gestão das listas
void func_gest_list(){
  int opcao;
  int num_cell;
  int var_pause;

  do{
      num_cell = 0;
      purge();
      printf("-------------(Menu)-------------\n");
      printf("1 = Ampliar lista.\n");
      printf("2 = Deletar lista / usuario.\n");
      printf("0 = voltar\n");
      printf("--------------------------------\n");
      scanf("%d", &opcao);
      switch(opcao){
        case 1:
              purge();
              printf("Digite o numero de listas a serem adcionadas\n");
              scanf("%d", &num_cell);
              aumentar_lista(var_inicio, num_cell);
              func_gest_list();
            break;
        case 2:
              purge();
              printf("Digite o numero do usuario que deseja deletar");
              scanf("%d", &num_cell);
              func_del_list(var_inicio, num_cell);
              func_gest_list();
            break;
        case 0:
            func_menu();
            break;
        default:
          purge();
          printf("Digite uma opção valida");
          scanf("%d", &num_cell);
            break;
      }
  }while(opcao != _EXIT_CONST);
}


//->Funções extras
/*
*->Função para media das notas📃   
*->Nome da função: 
*->Parametros: (float) dados 
*->Retorno: <retorno da função>
*/

bool f_media(float *dados){
  float med;
  int size = arrSize(dados);
  int i;
  
  for(i = 0; i <= size; i++){
    med = med + dados[i];
  }
  float media = med / size;
  if(media >= 50.0){
    return true;
  }
  else{
    return false;
  }
}

/*
*-> Função para o cls   
*-> Nome da função: purge
*-> Parametros: ()
*-> Retorno: ()
*/
void purge(){
  system("cls||clear");
    system("clear||cls");
}


void change(bool *input, ALUNOS *entrada){
  entrada -> registrado = true;
}