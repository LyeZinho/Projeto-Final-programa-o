#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Macro arrSize determina o tamanha de um array
//int arr[10];
//int i = arrSize(arr);
//printf("[%d]", i);
//output> [10]
#define arrSize(entrada) sizeof(entrada)/sizeof(entrada[0])

/*
*📃Função para media das notas📃   
*📌Nome da função: 
*📌Parametros: (float) dados 
*📌Retorno: <retorno da função>
*✨ [ https://replit.com/join/ttblpkww-lyezinho1 ] //
*/

float media(float dados){
  int num = arrSize(dados);
  int i;
  float media;
  for(i = 0; i <= num; i++){
    media += dados;
  }
  media = media / num;
  return media;
}