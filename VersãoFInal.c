#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calcular_media(float nota1, float nota2) {
    return (nota1 + nota2) / 2;

}

typedef struct {
    char nome[50];
    char curso[50];
    int prefixo, telefone1, telefone2;
    float nota1, nota2, media;
    char situacao[50];
} Aluno;

int main() {
    FILE *arquivo_entrada, *arquivo_saida;
    Aluno alunos[95];
    int i;

    arquivo_entrada = fopen("DadosEntrada.csv", "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        exit(1);
    }

    arquivo_saida = fopen("SituacaoFinal.csv", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(arquivo_entrada);
        return 1;
    }

    for (i = 0; i < 94; i++) {
        fscanf(arquivo_entrada, "%[^,], (%d) %d-%d,%[^,],%f,%f\n", alunos[i].nome, &alunos[i].prefixo, &alunos[i].telefone1, &alunos[i].telefone2, alunos[i].curso, &alunos[i].nota1, &alunos[i].nota2);
        alunos[i].media = calcular_media(alunos[i].nota1, alunos[i].nota2);
        if(alunos[i].media >= 7){
            strcpy(alunos[i].situacao, "APROVADO");
        } else {
            strcpy(alunos[i].situacao, "REPROVADO");
        }
        fprintf(arquivo_saida, "%s, %.2f, %s\n", alunos[i].nome, alunos[i].media, alunos[i].situacao);
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("O arquivo 'SituacaoFinal.csv' foi criado com sucesso.\n");

    return 0;
}
