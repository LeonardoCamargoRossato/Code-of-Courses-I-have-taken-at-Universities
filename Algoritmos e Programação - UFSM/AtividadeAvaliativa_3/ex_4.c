//------------------------------------------------//
// Disciplina: Algoritmos e lógica de programação //
//------------------------------------------------//
// ATIVIDADE AVALIATIVA 3 //
// ALUNO: LEONARDO CAMARGO ROSSATO //
// MATRICULA: 2020520162 //
//------------------------------------------------//
// #####   E X E R C I C I O - 04 #####//
//------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define struct do tipo funcionários
struct funcionarios{
	char nome[50];
	int dia;
	int mes;
};
typedef	struct funcionarios func;


//Função que classifica e mostra os aniversariantes do mês
void aniver_mes(func *f, int n){

	//Declaração de variáveis
	int i,cont;
	int vet[n];
	
	//Algoritmo que filtra os funcionários que estão fazendo aniversário no mês especificado (de Janeiro = 1 até Dezembro = 12).
	cont = 0;
	printf("\n Janeiro: ");	
  for ( i=0; i<n; i++ ){
  	if( f[i].mes == 1){
  		vet[cont] = i; 
  		cont++;
		}
	}
	if(cont == 0){ printf("Não há aniversariantes.");}
	else{
		for ( i=0; i<cont; i++ ){
	 		if(i != (cont-1)){  printf("%d %s, ", f[vet[i]].dia, f[vet[i]].nome);}
			else{ printf("%d %s. ", f[vet[i]].dia, f[vet[i]].nome);}
		}
	}

	cont = 0;
	printf("\n Fevereiro: ");	
  for ( i=0; i<n; i++ ){
  	if( f[i].mes == 2){
  		vet[cont] = i; 
  		cont++;
		}
	}
	if(cont == 0){ printf("Não há aniversariantes.");}
	else{
		for ( i=0; i<cont; i++ ){
	 		if(i != (cont-1)){  printf("%d %s, ", f[vet[i]].dia, f[vet[i]].nome);}
			else{ printf("%d %s. ", f[vet[i]].dia, f[vet[i]].nome);}
		}
	}
	
	cont = 0;
	printf("\n Março: ");	
  for ( i=0; i<n; i++ ){
  	if( f[i].mes == 3){
  		vet[cont] = i; 
  		cont++;
		}
	}
	if(cont == 0){ printf("Não há aniversariantes.");}
	else{
		for ( i=0; i<cont; i++ ){
	 		if(i != (cont-1)){  printf("%d %s, ", f[vet[i]].dia, f[vet[i]].nome);}
			else{ printf("%d %s. ", f[vet[i]].dia, f[vet[i]].nome);}
		}
	}		
	
	cont = 0;
	printf("\n Abril: ");	
  for ( i=0; i<n; i++ ){
  	if( f[i].mes == 4){
  		vet[cont] = i; 
  		cont++;
		}
	}
	if(cont == 0){ printf("Não há aniversariantes.");}
	else{
		for ( i=0; i<cont; i++ ){
	 		if(i != (cont-1)){  printf("%d %s, ", f[vet[i]].dia, f[vet[i]].nome);}
			else{ printf("%d %s. ", f[vet[i]].dia, f[vet[i]].nome);}
		}
	}

	cont = 0;
	printf("\n Maio: ");	
  for ( i=0; i<n; i++ ){
  	if( f[i].mes == 5){
  		vet[cont] = i; 
  		cont++;
		}
	}
	if(cont == 0){ printf("Não há aniversariantes.");}
	else{
		for ( i=0; i<cont; i++ ){
	 		if(i != (cont-1)){  printf("%d %s, ", f[vet[i]].dia, f[vet[i]].nome);}
			else{ printf("%d %s. ", f[vet[i]].dia, f[vet[i]].nome);}
		}
	}
	
	cont = 0;
	printf("\n Junho: ");	
  for ( i=0; i<n; i++ ){
  	if( f[i].mes == 6){
  		vet[cont] = i; 
  		cont++;
		}
	}
	if(cont == 0){ printf("Não há aniversariantes.");}
	else{
		for ( i=0; i<cont; i++ ){
	 		if(i != (cont-1)){  printf("%d %s, ", f[vet[i]].dia, f[vet[i]].nome);}
			else{ printf("%d %s. ", f[vet[i]].dia, f[vet[i]].nome);}
		}
	}			

	cont = 0;
	printf("\n Julho: ");	
  for ( i=0; i<n; i++ ){
  	if( f[i].mes == 7){
  		vet[cont] = i; 
  		cont++;
		}
	}
	if(cont == 0){ printf("Não há aniversariantes.");}
	else{
		for ( i=0; i<cont; i++ ){
	 		if(i != (cont-1)){  printf("%d %s, ", f[vet[i]].dia, f[vet[i]].nome);}
			else{ printf("%d %s. ", f[vet[i]].dia, f[vet[i]].nome);}
		}
	}

	cont = 0;
	printf("\n Agosto: ");	
  for ( i=0; i<n; i++ ){
  	if( f[i].mes == 8){
  		vet[cont] = i; 
  		cont++;
		}
	}
	if(cont == 0){ printf("Não há aniversariantes.");}
	else{
		for ( i=0; i<cont; i++ ){
	 		if(i != (cont-1)){  printf("%d %s, ", f[vet[i]].dia, f[vet[i]].nome);}
			else{ printf("%d %s. ", f[vet[i]].dia, f[vet[i]].nome);}
		}
	}
	
	cont = 0;
	printf("\n Setembro: ");	
  for ( i=0; i<n; i++ ){
  	if( f[i].mes == 9){
  		vet[cont] = i; 
  		cont++;
		}
	}
	if(cont == 0){ printf("Não há aniversariantes.");}
	else{
		for ( i=0; i<cont; i++ ){
	 		if(i != (cont-1)){  printf("%d %s, ", f[vet[i]].dia, f[vet[i]].nome);}
			else{ printf("%d %s. ", f[vet[i]].dia, f[vet[i]].nome);}
		}
	}			
	
	cont = 0;
	printf("\n Outubro: ");	
  for ( i=0; i<n; i++ ){
  	if( f[i].mes == 10){
  		vet[cont] = i; 
  		cont++;
		}
	}
	if(cont == 0){ printf("Não há aniversariantes.");}
	else{
		for ( i=0; i<cont; i++ ){
	 		if(i != (cont-1)){  printf("%d %s, ", f[vet[i]].dia, f[vet[i]].nome);}
			else{ printf("%d %s. ", f[vet[i]].dia, f[vet[i]].nome);}
		}
	}

	cont = 0;
	printf("\n Novembro: ");	
  for ( i=0; i<n; i++ ){
  	if( f[i].mes == 11){
  		vet[cont] = i; 
  		cont++;
		}
	}
	if(cont == 0){ printf("Não há aniversariantes.");}
	else{
		for ( i=0; i<cont; i++ ){
	 		if(i != (cont-1)){  printf("%d %s, ", f[vet[i]].dia, f[vet[i]].nome);}
			else{ printf("%d %s. ", f[vet[i]].dia, f[vet[i]].nome);}
		}
	}
	
	cont = 0;
	printf("\n Dezembro: ");	
  for ( i=0; i<n; i++ ){
  	if( f[i].mes == 12){
  		vet[cont] = i; 
  		cont++;
		}
	}
	if(cont == 0){ printf("Não há aniversariantes.");}
	else{
		for ( i=0; i<cont; i++ ){
	 		if(i != (cont-1)){  printf("%d %s, ", f[vet[i]].dia, f[vet[i]].nome);}
			else{ printf("%d %s. ", f[vet[i]].dia, f[vet[i]].nome);}
		}
	}			
	printf("\n\n");
}


int main(void){

	//Declaração de variáveis
	int i,dia, mes,n;
	char nome[50];
	
	//nº de funcionários = n + 1
	n = 6;  
	
	//Declara e Aloca memória ao vetor f
  func *f = malloc(n*sizeof(func));
   
   
	/*
	Registro de Nomes e Data de aniversário - Leitura arquivo
	arq lido é "registro_func" - contém as informações dos funcionários
	*/
	char url[]= "registro_func.txt";
  FILE *arq;
  arq = fopen(url, "r"); //abre arquivo apenas para leitura
  if(arq == NULL) //testa se arquivo pode ser aberto
  	printf("Erro, nao foi possivel abrir o arquivo. \n");
  	
  //Lê os dados do arquivo; salva em variáveis locais; transforma em variáveis do tipo struct func;	
  else{
  	i = 0;
		while( (fscanf(arq,"%s %d %d \n", nome, &dia, &mes))!=EOF ){
			strcpy(f[i].nome, nome);  
			f[i].dia = dia;
			f[i].mes = mes;
			i++;
		}
  } 
	
	//Chama a função externa
	aniver_mes(f,n+1);
	
	//Limpa a memória do vetor f
	free(f);
	
	//--------------
	//	fclose(arq);   
	//--------------
	/*--> n sei pq mas se tenta fechar o arq dá o seguinte problema: 
	" munmap_chunk(): invalid pointer
    Abortado (imagem do núcleo gravada)" */
	
	return 0;
}

