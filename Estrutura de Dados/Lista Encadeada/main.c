#include <stdio.h>
#include <stdlib.h>

struct No {
  int informacao;
  struct No *proximo;
};

struct No *criarNo(int informacao) {
  struct No *novoNo = (struct No *)malloc(sizeof(struct No));

  novoNo->informacao = informacao;
  novoNo->proximo = NULL;

  return novoNo;
};

void inserirNoInicioDaLista(struct No** cabeca, int informacao) {

  struct No *novoNo = criarNo(informacao);

  if (*cabeca == NULL) {
    *cabeca = novoNo;
  } else {
    struct No *temporario = novoNo;
    temporario->proximo = *cabeca;
    *cabeca = temporario;
  }
}

void inserirNoFinalDaLista(struct No** cabeca, int informacao){
  struct No* novoNo = criarNo(informacao);

  if(*cabeca == NULL){
    *cabeca = novoNo;
  }else{
    struct No* temporario = *cabeca;

    while(temporario->proximo != NULL){
      temporario = temporario->proximo;
    }

    temporario->proximo = novoNo;
  }
}

void imprimirLista(struct No** cabeca) {

  struct No *temporario = cabeca;

  while (temporario != NULL) {
    printf("%d -> ", temporario->informacao);
    temporario = temporario->proximo;
  }

  printf("NULL\n");
}

void removerDoInicio(struct No** cabeca){

  if(*cabeca == NULL){
    printf("A lista está vazia");

    return;
    }

    *cabeca = (*cabeca)->proximo;
}

int main() {

  struct No* cabeca = NULL;


  inserirNoInicioDaLista(&cabeca, 20);
  inserirNoInicioDaLista(&cabeca, 54);
  inserirNoInicioDaLista(&cabeca, 15);
  inserirNoInicioDaLista(&cabeca, 99);
  inserirNoFinalDaLista(&cabeca, 10);

  imprimirLista(cabeca);
  free(cabeca);

  return 0;
}





