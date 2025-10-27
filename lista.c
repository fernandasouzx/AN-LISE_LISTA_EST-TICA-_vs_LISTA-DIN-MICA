#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"
#define N 10000
//Função para inicializar a lista. Define o contador como zero.
void inicializaLista(tipo_lista *ls) {
    ls->contador = 0;
}
//Insere um elemento no final da lista, se houver espaço disponível.
int insereListaFim(tipo_lista *ls, int num) {
    if (ls->contador < N) {
        ls->lista[ls->contador++] = num;
        return -1;
    }
    return 0;
}
// Insere um elemento no início da lista, se houver espaço disponível e se um certo limite de inserção no início ainda não foi alcançado.
void insereListaInicio(tipo_lista *ls, int num, int *inicio, int *valores_inseridos) {
    if (ls->contador < N && *inicio < 3500) {
        if (!valores_inseridos[num]) {
            for (int i = ls->contador; i > 0; i--) {
                ls->lista[i] = ls->lista[i - 1];
            }
            ls->lista[0] = num;
            ls->contador++;
            (*inicio)++;
            valores_inseridos[num] = 1;
        }
    }
}
//Insere um elemento em uma posição aleatória da lista, se houver espaço disponível e se um certo limite de inserção em posições aleatórias ainda não foi alcançado.
void insereListaPosicao(tipo_lista *ls, int num, int *posicao, int *valores_inseridos) {
    if (ls->contador < N && *posicao < 3500) {
        if (!valores_inseridos[num]) {
            int posicao_inserir = rand() % (ls->contador + 1);
            for (int i = ls->contador; i > posicao_inserir; i--) {
                ls->lista[i] = ls->lista[i - 1];
            }
            ls->lista[posicao_inserir] = num;
            ls->contador++;
            (*posicao)++;
            valores_inseridos[num] = 1;
        }
    }
}
// Lê um arquivo de texto contendo uma quantidade específica de valores inteiros.Insere os valores lidos na lista utilizando as funções de inserção acima.
void ler_arquivo_e_inserir(tipo_lista *ls, char *caminho_arquivo, int *inicio, int *fim, int *posicao) {
    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    *inicio = 0;
    *fim = 0;
    *posicao = 0;
    int num_valores;
    fscanf(arquivo, "%d", &num_valores);
    int valores_inseridos[N] = {0}; 
    for (int i = 0; i < num_valores; i++) {
        int valor;
        fscanf(arquivo, "%d", &valor);
        int escolha = rand() % 3; 
        if (escolha == 0) {
            insereListaFim(ls, valor);
            (*fim)++; 
        } else if (escolha == 1) {
            insereListaInicio(ls, valor, inicio, valores_inseridos);
        } else {
            insereListaPosicao(ls, valor, posicao, valores_inseridos);
        }
    }
    fclose(arquivo);
}
//Retorna o tempo total de execução.
double medir_tempo_execucao(char *caminho_arquivo) {
    tipo_lista minha_lista;
    inicializaLista(&minha_lista);
    clock_t start, end;
    double tempo_total = 0.0;
    int inicio_total = 0, fim_total = 0, posicao_total = 0;
    start = clock(); 
    ler_arquivo_e_inserir(&minha_lista, caminho_arquivo, &inicio_total, &fim_total, &posicao_total);
    end = clock(); 
    tempo_total = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Total de valores inseridos no início: %d\n", inicio_total);
    printf("Total de valores inseridos no fim: %d\n", fim_total);
    printf("Total de valores inseridos em posicao aleatória: %d\n", posicao_total);
    return tempo_total; 
}
//Inicializa o gerador de números aleatórios.Chama a funçao acima para medir o tempo de execução de inserção para 10 arquivos diferentes
int main() {
    srand(time(NULL));
    double tempo_medio1 = medir_tempo_execucao("10000arq1.txt");
    printf("Tempo de execucao : %f segundos\n", tempo_medio1);
    double tempo_medio2 = medir_tempo_execucao("10000arq2.txt");
    printf("Tempo de execucao: %f segundos\n", tempo_medio2);
    double tempo_medio3 = medir_tempo_execucao("10000arq3.txt");
    printf("Tempo de execucao: %f segundos\n", tempo_medio3);
    double tempo_medio4 = medir_tempo_execucao("10000arq4.txt");
    printf("Tempo de execucao: %f segundos\n", tempo_medio4);
    double tempo_medio5 = medir_tempo_execucao("10000arq5.txt");
    printf("Tempo de execucao: %f segundos\n", tempo_medio5);
    double tempo_medio6 = medir_tempo_execucao("10000arq6.txt");
    printf("Tempo de execucao: %f segundos\n", tempo_medio6);
    double tempo_medio7 = medir_tempo_execucao("10000arq7.txt");
    printf("Tempo de execucao: %f segundos\n", tempo_medio7);
    double tempo_medio8 = medir_tempo_execucao("10000arq8.txt");
    printf("Tempo de execucao: %f segundos\n", tempo_medio8);
    double tempo_medio9 = medir_tempo_execucao("10000arq9.txt");
    printf("Tempo de execucao: %f segundos\n", tempo_medio9);
    double tempo_medio10 = medir_tempo_execucao("10000arq10.txt");
    printf("Tempo de execucao: %f segundos\n", tempo_medio10);
    double media_de_execucao = (tempo_medio1+tempo_medio2+tempo_medio3+tempo_medio4+tempo_medio5+tempo_medio6+tempo_medio7+tempo_medio8+tempo_medio9+tempo_medio10)/10;
    printf("Tempo Media de Todas as Execucoes: %f\n", media_de_execucao);
    return 0;
}
