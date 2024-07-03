#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEDIDOS 100

#include "pizza.h"
#include "clientes.h"
// #include "relatorio.h"

typedef struct {
    Cliente cliente;
    Pizza pizza;
    char formaPagamento[20];
} Pedido;

int totalPedidos = 0;
Pedido pedidos[MAX_PEDIDOS];

void mostrar_menu();

int main() {
    int opcao;

    do {
        mostrar_menu();
        scanf("%i", &opcao);
        system("cls");

        switch(opcao) {
            case 1:
                listarPizzas();
                system("pause");
                break;
            case 2:
                listarClientes();
                system("pause");
                break;
            case 3:
                adicionarPizza();
                
                printf("Gostaria de adicionar mais pizza?  (1 - Sim / 2 - Nao)\n");
                scanf("%i", &opcao);
                if(opcao == 1) {
                    adicionarPizza();
                }
                break;
            case 4:
                atualizarPizza();

                printf("Gostaria de editar mais pizza?  (1 - Sim / 2 - Nao)\n");
                scanf("%i", &opcao);
                if(opcao == 1) {
                    atualizarPizza();
                }
                break;
            case 5:
                removerPizza();

                printf("Gostaria de remover mais pizza?  (1 - Sim / 2 - Nao)\n");
                scanf("%i", &opcao);
                if(opcao == 1) {
                    removerPizza();
                }
                break;
            case 6:
                adicionarCliente();

                printf("Gostaria de adicionar mais cliente?  (1 - Sim / 2 - Nao)\n");
                scanf("%i", &opcao);
                if(opcao == 1) {
                    adicionarCliente();
                }
                break;
            case 7:
                atualizarCliente();

                printf("Gostaria de editar mais cliente?  (1 - Sim / 2 - Nao)\n");
                scanf("%i", &opcao);
                if(opcao == 1) {
                    atualizarCliente();
                }
                break;
            case 8:
                removerCliente();

                printf("Gostaria de remover mais cliente?  (1 - Sim / 2 - Nao)\n");
                scanf("%i", &opcao);
                if(opcao == 1) {
                    removerCliente();
                }
                break;
            case 9:
                fazerPedido();

                printf("Gostaria de fazer mais um pedido?  (1 - Sim / 2 - Nao)\n");
                scanf("%i", &opcao);
                if(opcao == 1) {
                    removerCliente();
                }
            default:
                mostrar_menu();
        }
    } while (opcao != 0);
}

void mostrar_menu() {
    system("cls");

    printf("[===== Sistema pizzaria =====]\n");
    printf("1 - Ver Cardapio de Pizzas\n");
    printf("2 - Ver Listas de Clientes\n");
    printf("3 - Adicionar Nova Pizza\n");
    printf("4 - Atualizar Pizza\n");
    printf("5 - Excluir Pizza\n");
    printf("6 - Adicionar Novo Cliente\n");
    printf("7 - Atualizar Cliente\n");
    printf("8 - Excluir Cliente\n");
    printf("9 - Fazer pedido\n");
    printf("\n");
    printf("0 - Para sair\n");
    printf("\n");
    printf("[-] ");
}

void fazerPedido() {
    int clienteId, pizzaId, pagamento;

    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    if (totalPizzas == 0) {
        printf("Nenhuma pizza cadastrada.\n");
        return;
    }

    printf("Escolha o ID do cliente (ou 0 para voltar): ");
    scanf("%d", &clienteId);
    if (clienteId == 0) return;
    clienteId--;

    if (clienteId < 0 || clienteId >= totalClientes) {
        printf("Cliente n�o encontrado!\n");
        return;
    }

    printf("Escolha o ID da pizza (ou 0 para voltar): ");
    scanf("%d", &pizzaId);
    if (pizzaId == 0) return;
    pizzaId--; 

    if (pizzaId < 0 || pizzaId >= totalPizzas) {
        printf("Pizza nao encontrada!\n");
        return;
    }

    Pedido pedido;
    pedido.cliente = clientes[clienteId];
    pedido.pizza = pizzas[pizzaId];

    printf("Escolha a forma de pagamento:\n");
    printf("1. Dinheiro\n");
    printf("2. PIX\n");
    printf("3. Cartao\n");
    printf("Opcao: ");
    scanf("%d", &pagamento);

    switch (pagamento) {
        case 1:
            strcpy(pedido.formaPagamento, "Dinheiro");
            break;
        case 2:
            strcpy(pedido.formaPagamento, "PIX");
            break;
        case 3:
            strcpy(pedido.formaPagamento, "Cartao");
            break;
        default:
            printf("Opcao invalida!\n");
            return;
    }

    pedidos[totalPedidos++] = pedido;
    printf("Pedido realizado com sucesso!\n");

    char detalhes[300];
    snprintf(detalhes, sizeof(detalhes), "Cliente: %s, Pizza: %s, Forma de Pagamento: %s", pedido.cliente.nome, pedido.pizza.sabor, pedido.formaPagamento);
    registrarAcao("Pedido Realizado", detalhes);

    gerarNotaFiscal(pedido);
}

void registrarAcao(const char *acao, const char *detalhes) {
    FILE *arquivo = fopen("relatorio.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de relatorio!\n");
        return;
    }
    fprintf(arquivo, "%s: %s\n", acao, detalhes);
    fclose(arquivo);
}

void gerarNotaFiscal(Pedido pedido) {
    FILE *arquivo = fopen("notas_fiscais.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de notas fiscais!\n");
        return;
    }
    fprintf(arquivo, "------------------------------\n");
    fprintf(arquivo, "Nota Fiscal\n");
    fprintf(arquivo, "Cliente: %s\n", pedido.cliente.nome);
    fprintf(arquivo, "Pizza: %s (%s)\n", pedido.pizza.sabor, pedido.pizza.tamanho);
    fprintf(arquivo, "Valor: %.2f\n", pedido.pizza.preco);
    fprintf(arquivo, "Forma de Pagamento: %s\n", pedido.formaPagamento);
    fprintf(arquivo, "------------------------------\n");
    fclose(arquivo);
}