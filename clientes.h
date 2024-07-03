#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include <relatorio.h>

#define MAX_CLIENTES 100

typedef struct {
    char nome[100];
    char telefone[15];
    char endereco[200];
} Cliente;

Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;

void adicionarCliente() {
    if (totalClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    Cliente c;
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]%*c", c.nome);
    printf("Digite o telefone do cliente: ");
    scanf(" %[^\n]%*c", c.telefone);
    printf("Digite o endereco do cliente: ");
    scanf(" %[^\n]%*c", c.endereco);

    clientes[totalClientes] = c;
    printf("Cliente adicionado com sucesso! ID: %d\n", totalClientes + 1);
    totalClientes++;

    char detalhes[300];
    snprintf(detalhes, sizeof(detalhes), "Nome: %s, Telefone: %s, Endereco: %s", c.nome, c.telefone, c.endereco);
    registrarAcao("Cliente Adicionado", detalhes);
}

void listarClientes() {
    int i;
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    for (i = 0; i < totalClientes; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("ID: %d\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("Endereco: %s\n", clientes[i].endereco);
    }
}

void atualizarCliente() {
    int id;
    printf("Digite o ID do cliente a ser atualizado (ou 0 para voltar): ");
    scanf("%d", &id);
    if (id == 0) return;
    id--; // Ajustando para �ndice 0

    if (id < 0 || id >= totalClientes) {
        printf("Cliente n�o encontrado!\n");
        return;
    }

    printf("Digite o novo nome do cliente: ");
    scanf(" %[^\n]%*c", clientes[id].nome);
    printf("Digite o novo telefone do cliente: ");
    scanf(" %[^\n]%*c", clientes[id].telefone);
    printf("Digite o novo endereco do cliente: ");
    scanf(" %[^\n]%*c", clientes[id].endereco);

    printf("Cliente atualizado com sucesso!\n");

    char detalhes[300];
    snprintf(detalhes, sizeof(detalhes), "ID: %d, Novo Nome: %s, Novo Telefone: %s, Novo Endereco: %s", id + 1, clientes[id].nome, clientes[id].telefone, clientes[id].endereco);
    registrarAcao("Cliente Atualizado", detalhes);
}

void removerCliente() {
    int id;
    printf("Digite o ID do cliente a ser removido (ou 0 para voltar): ");
    scanf("%d", &id);
    if (id == 0) return;
    id--; // Ajustando para �ndice 0

    if (id < 0 || id >= totalClientes) {
        printf("Cliente n�o encontrado!\n");
        return;
    }

    char detalhes[300];
    snprintf(detalhes, sizeof(detalhes), "ID: %d, Nome: %s, Telefone: %s, Endereco: %s", id + 1, clientes[id].nome, clientes[id].telefone, clientes[id].endereco);

    int i;
    for (i = id; i < totalClientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }
    totalClientes--;

    printf("Cliente removido com sucesso!\n");

    registrarAcao("Cliente Removido", detalhes);
}