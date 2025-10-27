#ifndef __LISTA_DUPLA_ENC_H__
#define __LISTA_DUPLA_ENC_H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct est_no {
    int valor;
    struct est_no* prox;
    struct est_no* ant;
};
typedef struct est_no No;
struct Lista_dupla_enc {
    No* inicio;
    No* fim;
    int contador;
};
typedef struct Lista_dupla_enc ListaDuplaEncadeada;;
void inicializaLista(ListaDuplaEncadeada*);
void insereListaFim(ListaDuplaEncadeada*, int , int *);
void insereListaInicio(ListaDuplaEncadeada*, int , int *);
void insereListaPosicao(ListaDuplaEncadeada*, int, int*);
void limpaLista(ListaDuplaEncadeada* );
void ler_arquivo_e_inserir(ListaDuplaEncadeada* , char* , int *, int *, int *); 
double medir_tempo_execucao(char*);
#endif