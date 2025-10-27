#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_enc.h"
//Função para inicializar a lista. Define o contador como zero.
void inicializaLista(ListaEncadeada* lst) {
    lst->inicio = NULL;
    lst->fim = NULL;
    lst->contador = 0;
}
//Insere um elemento no final da lista, se houver espaço disponível.
void insereListaFim(ListaEncadeada* lst, int num, int *fim_total) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        perror("Erro ao alocar memória para novo nó");
        exit(EXIT_FAILURE);
    }
    novoNo->valor = num;
    novoNo->prox = NULL;

    if (lst->inicio == NULL) {
        lst->inicio = novoNo;
    } else {
        lst->fim->prox = novoNo;
    }
    lst->fim = novoNo;
    lst->contador++;
    (*fim_total)++;
}
// Insere um elemento no início da lista, se houver espaço disponível e se um certo limite de inserção no início ainda não foi alcançado.
void insereListaInicio(ListaEncadeada* lst, int num, int *inicio_total) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        perror("Erro ao alocar memória para novo nó");
        exit(EXIT_FAILURE);
    }
    novoNo->valor = num;
    novoNo->prox = lst->inicio;
    lst->inicio = novoNo;
    if (lst->fim == NULL) {
        lst->fim = novoNo;
    }
    lst->contador++;
    (*inicio_total)++;
}
//Insere um elemento em uma posição aleatória da lista, se houver espaço disponível e se um certo limite de inserção em posições aleatórias ainda não foi alcançado.
void insereListaPosicao(ListaEncadeada* lst, int num, int *posicao_total) {
    int posicao_inserir = rand() % (lst->contador + 1);
    if (posicao_inserir == 0) {
        insereListaInicio(lst, num, posicao_total);
    } else if (posicao_inserir == lst->contador) {
        insereListaFim(lst, num, posicao_total);
    } else {
        No* novoNo = (No*)malloc(sizeof(No));
        if (novoNo == NULL) {
            perror("Erro ao alocar memória para novo nó");
            exit(EXIT_FAILURE);
        }
        novoNo->valor = num;
        No* atual = lst->inicio;
        for (int i = 0; i < posicao_inserir - 1; i++) {
            atual = atual->prox;
        }
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
        lst->contador++;
        (*posicao_total)++;
    }
}
//Libera toda a memória alocada dinamicamente para armazenar os nós da lista 
void limpaLista(ListaEncadeada* lst) {
    No* atual = lst->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lst->inicio = NULL;
    lst->fim = NULL;
    lst->contador = 0;
}
// Lê um arquivo de texto contendo uma quantidade específica de valores inteiros.Insere os valores lidos na lista utilizando as funções de inserção acima.
void ler_arquivo_e_inserir(ListaEncadeada* lst, char* caminho_arquivo, int *inicio, int *fim, int *posicao) {
    FILE* arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    *inicio = 0;
    *fim = 0;
    *posicao = 0;
    int num_valores;
    fscanf(arquivo, "%d", &num_valores);
    for (int i = 0; i < num_valores; i++) {
        int valor;
        fscanf(arquivo, "%d", &valor);
        int escolha = rand() % 3;
        if (escolha == 0) {
            insereListaFim(lst, valor, fim);
        } else if (escolha == 1) {
            insereListaInicio(lst, valor, inicio);
        } else {
            insereListaPosicao(lst, valor, posicao);
        }
    }
    fclose(arquivo);
}
//Retorna o tempo total de execução.
double medir_tempo_execucao(char* caminho_arquivo) {
    ListaEncadeada lst;
    inicializaLista(&lst);
    clock_t start, end;
    double tempo_total = 0.0;
    int inicio_total = 0, fim_total = 0, posicao_total = 0;
    start = clock();
    ler_arquivo_e_inserir(&lst, caminho_arquivo, &inicio_total, &fim_total, &posicao_total);
    end = clock();
    tempo_total = ((double)(end - start)) / CLOCKS_PER_SEC;
    limpaLista(&lst);
    printf("Total de valores inseridos no início: %d\n", inicio_total);
    printf("Total de valores inseridos no fim: %d\n", fim_total);
    printf("Total de valores inseridos em posicao aleatória: %d\n", posicao_total);
    return tempo_total;
}
//Inicializa o gerador de números aleatórios.Chama a funçao acima para medir o tempo de execução de inserção para 10 arquivos diferentes
int main() {
    srand(time(NULL));
    double tempo_medio1 = medir_tempo_execucao("10000arq1.txt");
    printf("Tempo médio de execucao: %f segundos\n", tempo_medio1);
    double tempo_medio2 = medir_tempo_execucao("10000arq2.txt");
    printf("Tempo médio de execucao: %f segundos\n", tempo_medio2);
    double tempo_medio3 = medir_tempo_execucao("10000arq3.txt");
    printf("Tempo médio de execucao: %f segundos\n", tempo_medio3);
    double tempo_medio4 = medir_tempo_execucao("10000arq4.txt");
    printf("Tempo médio de execucao: %f segundos\n", tempo_medio4);
    double tempo_medio5 = medir_tempo_execucao("10000arq5.txt");
    printf("Tempo médio de execucao: %f segundos\n", tempo_medio5);
    double tempo_medio6 = medir_tempo_execucao("10000arq6.txt");
    printf("Tempo médio de execucao: %f segundos\n", tempo_medio6);
    double tempo_medio7 = medir_tempo_execucao("10000arq7.txt");
    printf("Tempo médio de execucao: %f segundos\n", tempo_medio7);
    double tempo_medio8 = medir_tempo_execucao("10000arq8.txt");
    printf("Tempo médio de execucao: %f segundos\n", tempo_medio8);
    double tempo_medio9 = medir_tempo_execucao("10000arq9.txt");
    printf("Tempo médio de execucao: %f segundos\n", tempo_medio9);
    double tempo_medio10 = medir_tempo_execucao("10000arq10.txt");
    printf("Tempo médio de execucao: %f segundos\n", tempo_medio10);
    double media_de_execucao = (tempo_medio1+tempo_medio2+tempo_medio3+tempo_medio4+tempo_medio5+tempo_medio6+tempo_medio7+tempo_medio8+tempo_medio9+tempo_medio10)/10;
    printf("Tempo Media de Todas as Execucoes: %f segundos\n", media_de_execucao);
    return 0;
}