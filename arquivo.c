#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void embaralhar(int arr[], int n) {
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void gerar_arquivo(char *caminho_arquivo, int num_valores) {
    FILE *arquivo = fopen(caminho_arquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Escrever o total de números no início do arquivo
    fprintf(arquivo, "%d\n", num_valores);

    int *valores = malloc(num_valores * sizeof(int));
    if (valores == NULL) {
        perror("Erro de alocação de memória");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    // Seed para a geração de números aleatórios (inicializar apenas uma vez)
    static int seed_inicializada = 0;
    if (!seed_inicializada) {
        srand(time(NULL));
        seed_inicializada = 1;
    }

    // Inicializar conjunto para garantir números únicos
    int *conjunto = malloc(10000 * sizeof(int));
    for (int i = 0; i < 10000; ++i) {
        conjunto[i] = i + 1;
    }

    // Preencher array de valores garantindo números únicos
    for (int i = 0; i < num_valores; ++i) {
        int indice = rand() % (10000 - i);
        valores[i] = conjunto[indice];
        conjunto[indice] = conjunto[10000 - i - 1]; // Substituir o escolhido pelo último não escolhido
    }

    free(conjunto);

    // Embaralhar os valores
    embaralhar(valores, num_valores);

    // Escrever valores no arquivo
    for (int i = 0; i < num_valores; ++i) {
        fprintf(arquivo, "%d\n", valores[i]);
    }

    free(valores);
    fclose(arquivo);
}

int main() {
    int num_arquivos_por_quantidade = 10;
    int quantidades[] = {10000};

    for (int i = 0; i < sizeof(quantidades) / sizeof(quantidades[0]); ++i) {
        for (int num_arquivo = 1; num_arquivo <= num_arquivos_por_quantidade; ++num_arquivo) {
            char caminho_arquivo[20];
            sprintf(caminho_arquivo, "%darq%d.txt", quantidades[i], num_arquivo);
            gerar_arquivo(caminho_arquivo, quantidades[i]);
            printf("Arquivo %s gerado.\n", caminho_arquivo);
        }
    }

    return 0;
}
