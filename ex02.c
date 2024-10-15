#include <stdio.h>
#define num_motos 4

// Construa um programa em C que armazene placa (vetor de char), ano de fabricação (int) e valor (float) de 8 motos. Crie as seguintes funções: 
// a) Preencher valor;
// b) Ordenar vetor pelo campo ano de fabricação - escolha entre os métodos Insertion ou Selection;
// c) Mostrar vetor

typedef struct  {
    char placa[8];
    int anoFabricacao;
    float valor;
} Moto;

void preencherMotos(Moto motos[]) {
    for (int i = 0; i < num_motos; i++) {
        printf("Moto %d:\n", i + 1);
        printf("Digite a placa: ");
        scanf("%s", motos[i].placa);
        printf("Digite o ano de fabricacao: ");
        scanf("%d", &motos[i].anoFabricacao);
        printf("Digite o valor: ");
        scanf("%f", &motos[i].valor);
        printf("\n");
    }
}

// Insertion Sort
void ordenarPorAno(Moto motos[]) {
    for (int i = 1; i < num_motos; i++) {
        Moto chave = motos[i];
        int j = i - 1;
        while (j >= 0 && motos[j].anoFabricacao > chave.anoFabricacao) {
            motos[j + 1] = motos[j];
            j--;
        }
        motos[j + 1] = chave;
    }
}

void mostrarMotos(Moto motos[]) {
    printf("Lista de motos:\n");
    for (int i = 0; i < num_motos; i++) {
        printf("Moto %d:\n", i + 1);
        printf("Placa: %s\n", motos[i].placa);
        printf("Ano de Fabricacao: %d\n", motos[i].anoFabricacao);
        printf("Valor: %.2f\n", motos[i].valor);
        printf("\n");
    }
}

int main() {
    Moto motos[num_motos];

    preencherMotos(motos);

    ordenarPorAno(motos);

    mostrarMotos(motos);

    return 0;
}