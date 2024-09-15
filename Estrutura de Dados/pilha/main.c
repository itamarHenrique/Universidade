#include <stdio.h>
#include <stdlib.h>

struct Pilha{
    int topo;
    int capacidade;
    int* proximo;
};

void criaPilha(struct Pilha* novaPilha, int capacidade){
    novaPilha->proximo = (int *)malloc(sizeof(int));
    novaPilha->topo = -1;
    novaPilha->capacidade = capacidade;    
}

int pilhaEstaCheia(struct Pilha* pilha){
    return pilha->topo == pilha->capacidade -1;

}

int pilhaEstaVazia(struct Pilha* pilha){

    return pilha->topo == -1;
}

void inserirNaPilha(struct Pilha* pilha, int valor){
    if(pilhaEstaCheia(pilha)){
        printf("A pilha está cheia!\n");
        return;
    }

    pilha->topo++;
    pilha->proximo[pilha->topo] = valor;
}

int removerDaPilha(struct Pilha* pilha){
    if(pilhaEstaVazia(pilha)){
        printf("A pilha está vazia.\n");
        return;
    }

    int auxiliar = pilha->proximo[pilha->topo];
    pilha->topo--;

    return auxiliar;
}


void imprimirPilha(struct Pilha* pilha){
    if(pilhaEstaVazia(pilha)){
        printf("A pilha está vazia.\n");
        return;
    }

    for(int i = pilha->topo; i >= 0; i--){
        printf("%d\n", pilha->proximo[i]);
    }
}

int main(){

    struct Pilha pilha;

    criaPilha(&pilha, 4);

    inserirNaPilha(&pilha, 3);
    inserirNaPilha(&pilha, 1);
    inserirNaPilha(&pilha, 0);
    inserirNaPilha(&pilha, 2);
    inserirNaPilha(&pilha, 10);
    inserirNaPilha(&pilha, 3);

    imprimirPilha(&pilha);

    printf("Agora vou remover o topo da pilha.\n");

    removerDaPilha(&pilha);
    removerDaPilha(&pilha);
    removerDaPilha(&pilha);
    removerDaPilha(&pilha);
    imprimirPilha(&pilha);

    return 0;
}