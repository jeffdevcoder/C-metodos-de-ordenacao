#include <stdio.h>
#define num_alunos 10

//Construa um programa em C que armazene o nome (vetor de char), numero do periodo (int) e CR (float) de 10 alunos. Crie as seguintes funções
// a) Preencher vetor;
// b) Ordenar vetor pelo campo CR - escolha o método Quick Sort;
// c) Retornar um valor float, que é a média da turma, pelo campo CR;
// d) Mostrar vetor

typedef struct {
    char nome[50];
    int periodo;
    float CR;
} Aluno;

void preencherAlunos(Aluno alunos[]) {
    for (int i = 0; i < num_alunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Digite o nome: ");
        scanf(" %s", alunos[i].nome);
        printf("Digite o número do período: ");
        scanf("%d", &alunos[i].periodo);
        printf("Digite o CR: ");
        scanf("%f", &alunos[i].CR);
        printf("\n");
    }
}

void trocar(Aluno *a, Aluno *b) {
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(Aluno alunos[], int low, int high) {
    float pivo = alunos[high].CR;
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (alunos[j].CR <= pivo) {
            i++;
            trocar(&alunos[i], &alunos[j]);
        }
    }
    trocar(&alunos[i + 1], &alunos[high]);
    return (i + 1);
}

void quickSort(Aluno alunos[], int low, int high) {
    if (low < high) {
        int pi = particionar(alunos, low, high);
        quickSort(alunos, low, pi - 1);
        quickSort(alunos, pi + 1, high);
    }
}

float calcularMediaCR(Aluno alunos[]) {
    float soma = 0;
    for (int i = 0; i < num_alunos; i++) {
        soma += alunos[i].CR;
    }
    return soma / num_alunos;
}

void mostrarAlunos(Aluno alunos[]) {
    printf("Lista de alunos:\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Número do Período: %d\n", alunos[i].periodo);
        printf("CR: %.2f\n", alunos[i].CR);
        printf("\n");
    }
}


int main() {
    Aluno alunos[num_alunos];

    preencherAlunos(alunos);

    quickSort(alunos, 0, num_alunos - 1);

    mostrarAlunos(alunos);

    float mediaCR = calcularMediaCR(alunos);
    printf("A média do CR da turma é: %.2f\n", mediaCR);

    return 0;
}