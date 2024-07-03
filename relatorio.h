#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void registrarAcao(const char *acao, const char *detalhes) {
    FILE *arquivo = fopen("relatorio.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de relatorio!\n");
        return;
    }
    fprintf(arquivo, "%s: %s\n", acao, detalhes);
    fclose(arquivo);
}