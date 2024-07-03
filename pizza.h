#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include <relatorio.h>

#define MAX_PIZZAS 100

typedef struct {
    char sabor[50];
    char tamanho[20];
    float preco;
} Pizza;

Pizza pizzas[MAX_PIZZAS];
int totalPizzas = 0;

void adicionarPizza() {
    if (totalPizzas >= MAX_PIZZAS) {
        printf("Limite de pizzas atingido!\n");
        return;
    }

    Pizza p;
    printf("Digite o sabor da pizza: ");
    scanf(" %[^\n]%*c", p.sabor);
    printf("Digite o tamanho da pizza: ");
    scanf(" %[^\n]%*c", p.tamanho);
    printf("Digite o preco da pizza: ");
    scanf("%f", &p.preco);

    pizzas[totalPizzas] = p;
    printf("Pizza adicionada com sucesso! ID: %d\n", totalPizzas + 1);
    totalPizzas++;

    char detalhes[150];
    snprintf(detalhes, sizeof(detalhes), "Sabor: %s, Tamanho: %s, Preco: %.2f", p.sabor, p.tamanho, p.preco);
    registrarAcao("Pizza Adicionada", detalhes);
}

void listarPizzas() {
    int i;
    if (totalPizzas == 0) {
        printf("Nenhuma pizza cadastrada.\n");
        return;
    }
    for (i = 0; i < totalPizzas; i++) {
        printf("Pizza %d:\n", i + 1);
        printf("ID: %d\n", i + 1);
        printf("Sabor: %s\n", pizzas[i].sabor);
        printf("Tamanho: %s\n", pizzas[i].tamanho);
        printf("Preco: %.2f\n", pizzas[i].preco);
    }
}

void atualizarPizza() {
    int id;
    printf("Digite o ID da pizza a ser atualizada (ou 0 para voltar): ");
    scanf("%d", &id);
    if (id == 0) return;
    id--; // Ajustando para �ndice 0

    if (id < 0 || id >= totalPizzas) {
        printf("Pizza n�o encontrada!\n");
        return;
    }

    printf("Digite o novo sabor da pizza: ");
    scanf(" %[^\n]%*c", pizzas[id].sabor);
    printf("Digite o novo tamanho da pizza: ");
    scanf(" %[^\n]%*c", pizzas[id].tamanho);
    printf("Digite o novo preco da pizza: ");
    scanf("%f", &pizzas[id].preco);

    printf("Pizza atualizada com sucesso!\n");

    char detalhes[150];
    snprintf(detalhes, sizeof(detalhes), "ID: %d, Novo Sabor: %s, Novo Tamanho: %s, Novo Preco: %.2f", id + 1, pizzas[id].sabor, pizzas[id].tamanho, pizzas[id].preco);
    registrarAcao("Pizza Atualizada", detalhes);
}

void removerPizza() {
    int id;
    printf("Digite o ID da pizza a ser removida (ou 0 para voltar): ");
    scanf("%d", &id);
    if (id == 0) return;
    id--; // Ajustando para �ndice 0

    if (id < 0 || id >= totalPizzas) {
        printf("Pizza n�o encontrada!\n");
        return;
    }

    char detalhes[150];
    snprintf(detalhes, sizeof(detalhes), "ID: %d, Sabor: %s, Tamanho: %s, Preco: %.2f", id + 1, pizzas[id].sabor, pizzas[id].tamanho, pizzas[id].preco);

    int i;
    for (i = id; i < totalPizzas - 1; i++) {
        pizzas[i] = pizzas[i + 1];
    }
    totalPizzas--;

    printf("Pizza removida com sucesso!\n");

    registrarAcao("Pizza Removida", detalhes);
}