#include <stdio.h>
#include <stdlib.h>


struct No{
  int informacao;
  struct No* anterior;
  struct No* proximo;
};

struct No* criarNo(int informacao){
  struct No* novoNo = (struct No*) malloc(sizeof(struct No));

  novoNo->informacao = informacao;
  novoNo->anterior = NULL;
  novoNo->proximo = NULL;

   return novoNo;
}

void inserirInicio(struct No** cabeca,struct No** ponta, int informacao){

  struct No* noInicio = criarNo(informacao);

  if(*cabeca == NULL){
     *cabeca = noInicio;
     *ponta = noInicio;
  }else{
    struct No* cabecaLista = *cabeca;
    noInicio->proximo = cabecaLista;
    cabecaLista->anterior = noInicio;
    *cabeca = noInicio;
  }

}

void removerNoInicio(struct No** cabeca){

  if(*cabeca == NULL){
    return;
  }

  struct No* cabecalista = *cabeca;
  struct No* novoCabeca = cabecalista->proximo;

  if(novoCabeca != NULL){
  novoCabeca->anterior = NULL;
  }

  *cabeca = novoCabeca;

}

void inserirFim(struct No** ponta, int informacao){

   struct No* NoFinal = criarNo(informacao);

   if(*ponta == NULL){
      *ponta = NoFinal;
      return;
   }

  struct No* pontaDaLista = *ponta;
  pontaDaLista->proximo = NoFinal;
  NoFinal->anterior = pontaDaLista;
  *ponta = NoFinal;
}

void inseriorPosicaoDeterminada(struct No** cabeca, struct No** ponta, int informacao, int posicao){

    struct No* novoNo = criarNo(informacao);
    struct No* temporario = *cabeca;
    int contador = 0;

    if(posicao == 0){
        inserirInicio(cabeca, ponta, informacao);
        return;
    }

    if(posicao < 0){
        printf("Você esta tentando inserir em uma posição menor que a posição inicial. Por favor tente realizar a operação novamente.\n");
        return;
    }

    if(posicao == 1){
        *cabeca = novoNo;
    }

    while(temporario != NULL && contador < posicao -1){ // Não sei pq quando não coloco o -1, está inserindo na proxima posição ao inves da informada.
        temporario = temporario->proximo;
        contador++;
    }

    if(temporario == NULL){
        inserirFim(ponta, informacao);
        free(novoNo);
        return;
    }

    novoNo->proximo = temporario->proximo;
    novoNo->anterior = temporario;

    if(temporario->proximo != NULL){
        temporario->proximo->anterior = novoNo;
    }

    temporario->proximo = novoNo;

    if(novoNo->proximo == NULL){
        *ponta = novoNo;
    }

}

void removerNoFinal(struct No** ponta){

  if(*ponta == NULL){
    return;
  }

  struct No* pontaDaLista = *ponta;

   if(pontaDaLista->anterior == NULL){
     *ponta = NULL;
     free(pontaDaLista);
     return;
   }

   struct No* novaPonta = pontaDaLista->anterior;
   pontaDaLista->proximo = NULL;
   free(pontaDaLista);
   *ponta = novaPonta;
}

void imprimirListaAPartirDaPonta(struct No* ponta, int posicao) {
    if (ponta == NULL) {
        return;
    }

    struct No* percorrerPonta = ponta;

    while (percorrerPonta != NULL) {
        printf("%d -> ", percorrerPonta->informacao);

        if (posicao == 1) {
            percorrerPonta = percorrerPonta->proximo;
        } else {
            percorrerPonta = percorrerPonta->anterior;
        }
    }

    printf("NULL.\n");
}

void imprimirLista(struct No* cabeca){
    if(cabeca == NULL){
        printf("A lista esta vazia.\n");
        return;
    }

    struct No* temporario = cabeca;

    while(temporario != NULL){
        printf("%d -> ", temporario->informacao);
        temporario = temporario->proximo;
    }

    printf("NULL.\n");
}

int main(){

     struct No* cabeca = NULL;
     struct No* ponta = NULL;

    inserirInicio(&cabeca,&ponta, 10);
    inserirInicio(&cabeca,&ponta, 20);
    printf("Abaixo está a inserção do informacao no inicio da lista.\n");
    imprimirLista(cabeca);


    inserirFim(&ponta, 30);
    inserirFim(&ponta, 40);
    printf("Lista após inserção no fim.\n");
    imprimirLista(cabeca);

    printf("E agora será realizada a impressão da lista de trás para frente.\n");
    imprimirListaAPartirDaPonta(ponta, 0);

    inseriorPosicaoDeterminada(&cabeca, &ponta, 87, 2);
    imprimirLista(cabeca);
}
