#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <relatorio.h>

void fazerPedido() {
    int clienteId, pizzaId, pagamento;
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado. Por favor, adicione um cliente primeiro.\n");
        return;
    }
    if (totalPizzas == 0) {
        printf("Nenhuma pizza cadastrada. Por favor, adicione uma pizza primeiro.\n");
        return;
    }

    printf("Escolha o ID do cliente (ou 0 para voltar): ");
    scanf("%d", &clienteId);
    if (clienteId == 0) return;
    clienteId--; // Ajustando para �ndice 0

    if (clienteId < 0 || clienteId >= totalClientes) {
        printf("Cliente n�o encontrado!\n");
        return;
    }

    printf("Escolha o ID da pizza (ou 0 para voltar): ");
    scanf("%d", &pizzaId);
    if (pizzaId == 0) return;
    pizzaId--; // Ajustando para �ndice 0

    if (pizzaId < 0 || pizzaId >= totalPizzas) {
        printf("Pizza n�o encontrada!\n");
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
}