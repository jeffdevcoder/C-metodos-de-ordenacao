#include <stdio.h>

#define TAM_A 10
#define TAM_B 7
#define TAM_C 15
#define TAM_D 9

void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(float arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        float temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int partition(float arr[], int low, int high) {
    float pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    float temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(float arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    float L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(float arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    float turmaA[TAM_A] = {7.8, 6.4, 9.0, 5.5, 8.2, 6.1, 7.7, 7.1, 9.3, 8.5};
    float turmaB[TAM_B] = {6.5, 7.2, 5.9, 8.0, 7.6, 8.8, 9.1};
    float turmaC[TAM_C] = {5.5, 6.2, 7.8, 6.9, 8.1, 7.2, 9.0, 5.4, 8.7, 6.3, 7.5, 7.9, 8.5, 6.6, 9.2};
    float turmaD[TAM_D] = {7.0, 8.4, 6.5, 7.7, 8.1, 9.0, 6.3, 7.9, 8.5};

    printf("Ordenando a Turma A (Insertion Sort):\n");
    insertionSort(turmaA, TAM_A);
    printArray(turmaA, TAM_A);

    printf("\nOrdenando a Turma B (Selection Sort):\n");
    selectionSort(turmaB, TAM_B);
    printArray(turmaB, TAM_B);

    printf("\nOrdenando a Turma C (Quick Sort):\n");
    quickSort(turmaC, 0, TAM_C - 1);
    printArray(turmaC, TAM_C);

    printf("\nOrdenando a Turma D (Merge Sort):\n");
    mergeSort(turmaD, 0, TAM_D - 1);
    printArray(turmaD, TAM_D);

    return 0;
}