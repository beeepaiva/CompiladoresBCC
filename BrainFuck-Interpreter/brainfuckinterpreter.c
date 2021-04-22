#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1024
struct node_t* p_atual;

struct node_t {
	struct node_t *prox;
	struct node_t *antes;
	int valor;
};

void interpretador(char* text){
  char t;

  while((t=*text++) != '\0'){
    if(t=='+')
      incrementar(p_atual);
    else if(t=='-')
      decrementar(p_atual);
    else if('>')
      direita(p_atual);
    else if('<')
      esquerda(p_atual);
    else if('.')
      printf("%c", getvalue(p_atual));
    else if('.')
      mudavalor(p_atual);
  }
  
}

int main(int argc, const char * argv[]) {
  
  FILE* file;

  char buffer[MAX_LINE_SIZE];
	int ponto = 0;
	char* bftext = (char*) malloc(sizeof(char) * MAX_LINE_SIZE);

  if((file = fopen(argv[1], "r")) != NULL){

    while (fgets(buffer, MAX_LINE_SIZE, file) != NULL) {
		  memcpy(bftext + ponto, buffer, MAX_LINE_SIZE);
		  ponto += strlen(buffer); 
		  bftext = realloc(bftext, ponto + MAX_LINE_SIZE);
	  }
  fclose(file);
  }
  interpretador(bftext);

}

