# ANÁLISE DE LISTA ESTÁTICA X LISTA DINÂMICA
Universidade Federal de Mato Grosso – Campus do Araguaia  
Instituto de Ciências Exatas e da Terra  
Bacharelado em Ciência da Computação  

**Autores:** Fernanda Lima de Souza, Pedro Henrique Camelo de França  
**Disciplina:** Estrutura de Dados I  
**Ano:** 2025  
**Local:** Barra do Garças - MT  

---

## Descrição do Projeto

Comparação de desempenho e uso de memória entre **listas estática, encadeada e duplamente encadeada** em C, analisando tempo de inserção em diferentes posições.

O programa lê arquivos com números inteiros aleatórios e realiza inserções:

- No **início** da lista (~1/3 dos elementos)  
- No **fim** da lista (~1/3 dos elementos)  
- Em **posição aleatória** (~1/3 dos elementos)  

Cada teste é repetido **10 vezes** para calcular o tempo médio de execução.

---

## Funcionalidades

- Inserção em listas estática, encadeada e duplamente encadeada  
- Medição do tempo de execução usando `clock()`  
- Liberação de memória em listas dinâmicas  
- Cálculo do menor, maior e tempo médio  
- Avaliação da ocupação de memória de cada estrutura  

---

## Resultados Obtidos

| Estrutura | Qtd. Ins. Início | Qtd. Ins. Fim | Qtd. Ins. Posição | Menor Tempo (s) | Maior Tempo (s) | Tempo Médio (s) |
|-----------|----------------|---------------|-----------------|----------------|----------------|----------------|
| Lista Estática | 3343 | 3340 | 3317 | 0.039784 | 0.068792 | 0.054630 |
| Lista Encadeada | 3280 | 3398 | 3322 | 0.055171 | 0.078279 | 0.065164 |
| Lista Duplamente Encadeada | 3363 | 3403 | 3234 | 0.044342 | 0.088599 | 0.066090 |

---

## Análise de Memória

- **Lista Estática:** alocação contígua, memória fixa; mais eficiente em uso de memória  
- **Lista Encadeada:** cada nó contém ponteiro para o próximo; maior consumo  
- **Lista Duplamente Encadeada:** ponteiros para nós anterior e próximo; maior consumo ainda  

---

## Estrutura do Código

### Lista Estática
- Inicialização com contador zerado  
- Funções de inserção: `insereListaInicio()`, `insereListaFim()`, `insereListaPosicao()`  
- Leitura de arquivos e inserção aleatória  
- Medição de tempo com `medir_tempo_execucao()`  
- Execução para 10 arquivos e cálculo do tempo médio  

### Lista Encadeada
- Inicialização com ponteiros `inicio` e `fim` como `NULL`  
- Mesmas funções de inserção da lista estática  
- Liberação de memória com `limpaLista()`  
- Leitura de arquivos e medição de tempo similar à lista estática  

### Lista Duplamente Encadeada
- Inicialização com ponteiros `inicio` e `fim` como `NULL`  
- Inserções no início, fim e posição aleatória  
- Liberação de memória com `limpaLista()`  
- Medição de tempo igual às outras listas  

---

## Conclusão

- A **lista estática** foi a mais rápida, devido à alocação contígua e ausência de ponteiros  
- Listas encadeadas e duplamente encadeadas oferecem flexibilidade e alocação dinâmica, mas têm maior overhead de ponteiros, impactando o tempo de execução  
- Em termos de **uso de memória**, a lista estática é mais eficiente, seguida da lista encadeada e, por último, da lista duplamente encadeada  

---

## Compilação e Execução

O projeto inclui um **Makefile** que permite compilar os programas separadamente:

### Para compilar todos os programas
```bash
make all
```
---

## Compilação Individual
Para compilar individualmente cada programa, utilize:

```bash
make lista
make lista_enc
make lista_dupla_enc
```
---
## Execução dos Programas
Após a compilação, execute os programas gerados:
```bash
./lista
./lista_enc
./lista_dupla_enc
```
---
## Limpar Arquivos Compilados
Para remover os executáveis e arquivos objeto gerados:

```bash
make clean
```
---

#Estrutura do Repositório
```bash
/ANALISE_LISTA_ED
│
├─ lista.c
├─ lista.h
├─ lista_enc.c
├─ lista_enc.h
├─ lista_dupla_enc.c
├─ lista_dupla_enc.h
├─ Makefile
├─ dados/           # Arquivos com números aleatórios
└─ README.md
```
---

