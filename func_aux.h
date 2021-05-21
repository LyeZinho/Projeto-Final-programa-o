#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "main.c"
#define arrSize(entrada) sizeof(entrada)/sizeof(entrada[0])

/*
*📃Função para media das notas📃   
*📌Nome da função: 
*📌Parametros: (float) dados 
*📌Retorno: <retorno da função>
*✨ [ https://replit.com/join/ttblpkww-lyezinho1 ] //
*/

float f_media(float *dados){
  float med;
  int size = arrSize(dados);
  int i;
  
  for(i = 0; i <= size; i++){
    med = med + dados[i];
  }
  return med / size;
}


/*
*📃Função para comparar strings📃   
*📌Nome da função: 
*📌Parametros: (float) dados 
*📌Retorno: <retorno da função>
*✨ [ https://replit.com/join/ttblpkww-lyezinho1 ] //
*/
