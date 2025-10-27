#ifndef __LISTA_ENC_H__
#define __LISTA_ENC_H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct est_no {
    int valor;
    struct est_no* prox;
};
typedef struct est_no No;
struct Lista_Enc {
    No* inicio;
    No* fim;
    int contador;
};
typedef struct Lista_Enc ListaEncadeada;
void inicializaLista(ListaEncadeada* );
void insereListaFim(ListaEncadeada* , int , int *) ;
void insereListaInicio(ListaEncadeada* , int , int *);
void insereListaPosicao(ListaEncadeada* , int , int *);
void limpaLista(ListaEncadeada* );
void ler_arquivo_e_inserir(ListaEncadeada* , char* , int *, int *, int *);
double medir_tempo_execucao(char*);
#endif