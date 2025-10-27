
#ifndef __LISTA_H__
#define __LISTA_H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000
struct est_lista {
    int lista[N];
    int contador;
};
typedef struct est_lista tipo_lista;

void inicializaLista(tipo_lista *);
int insereListaFim(tipo_lista *, int );
void insereListaInicio(tipo_lista *, int , int *, int *);
void ler_arquivo_e_inserir(tipo_lista *, char *, int *, int *, int *);
double medir_tempo_execucao(char *);
#endif
