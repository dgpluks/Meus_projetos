#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
typedef struct{
        bool tip;
        int value;
        struct No *dir;
        struct No *esq;
}No;
typedef struct{
        struct No *raiz;
}Arvore;
void newNode(int v, No **pos){
        No *aux = malloc(sizeof(No));
        aux->value = v;
        aux->tip = true;
        *pos= aux;
}
*Arvore newArv(){
        struct Arvore *arv = malloc(sizeof(Arvore));
       return arv;
}
void insert(No **){

}
int main(){
        No *teste;
        newNode(5, &teste);
        printf("%d", teste->value);
}
