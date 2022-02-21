#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *vetor, int esq, int dir) {
    for (int i = esq; i < dir; i++) {
        int aux = vetor[i + 1];
        int j = i + 1;
        while (j > esq && vetor[j - 1] > aux) {
            vetor[j] = vetor[j - 1];
            j--;
        }
        vetor[j] = aux;
    }
}

void merge(int *vetor, int *aux, int esq, int meio, int dir){
    int i,j,k;

    for(i = meio + 1; i > esq; i--)
        aux[i-1] = vetor[i-1];
    for(j = meio; j < dir; j++)
        aux[dir+meio-j] = vetor[j+1];

    for(k = esq; k <= dir; k++){
        if(aux[j]<aux[i]) vetor[k] = aux[j--];
        else vetor[k] = aux[i++];
    }
}

void ordenar (int *vetor, int *aux, int esquerda, int direita) {
    int combo = direita-esquerda;
    if(combo < 10) {
        insertionSort(vetor, esquerda, direita);
        return;
    }
    int meio = (esquerda + direita) / 2;
    ordenar(vetor, aux, esquerda, meio);
    ordenar(vetor, aux, meio + 1, direita);

    if(vetor[meio] <= vetor[meio+1])
        return;

    merge(vetor, aux, esquerda, meio, direita);
}

void mergesort (int *vetor, int n) {
    int *aux = (int *)malloc(sizeof(int) * n);
    ordenar(vetor, aux, 0, n-1);
    free(aux);
}

int main(){
    int vetor[15] = {10,6,9,2,4,7,5,1,3,33,27,13,56,22,8};
    mergesort(vetor, 15);
    for(int i=0; i<15; i++)
        printf("%d ",vetor[i]);

    return 0;
}
