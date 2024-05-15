#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Exercício 1
void reverseName() {
    char name[MAX_SIZE];
    printf("Digite o nome: ");
    scanf("%s", name);

    printf("Nome invertido: ");
    for (int i = strlen(name) - 1; i >= 0; i--) {
        printf("%c", name[i]);
    }
    printf("\n");
}

// Exercício 2
void showVariableInfo(int *ptr) {
    printf("Conteúdo da variável: %d\n", *ptr);
    printf("Endereço da variável: %p\n", ptr);
    printf("Conteúdo do ponteiro: %p\n", (void *)&ptr);
}

// Exercício 3
void calculator(int *a, int *b, char op, int *result) {
    switch (op) {
        case '+':
            *result = *a + *b;
            break;
        case '-':
            *result = *a - *b;
            break;
        case '*':
            *result = *a * *b;
            break;
        case '/':
            *result = *a / *b;
            break;
        default:
            printf("Operador inválido!\n");
    }
}

// Exercício 4
void append(int arr[], int *size, int value) {
    if (*size < MAX_SIZE) {
        arr[*size] = value;
        (*size)++;
    } else {
        printf("Lista cheia, impossível adicionar elemento.\n");
    }
}

// Exercício 5
void insert(int arr[], int *size, int index, int value) {
    if (index >= 0 && index < *size && *size < MAX_SIZE) {
        for (int i = *size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        (*size)++;
    } else {
        printf("Índice inválido ou lista cheia, impossível inserir elemento.\n");
    }
}

// Exercício 6
int pop(int arr[], int *size) {
    if (*size > 0) {
        int poppedElement = arr[*size - 1];
        (*size)--;
        return poppedElement;
    } else {
        printf("Lista vazia, impossível remover elemento.\n");
        return -1; // Indica que não há elemento para ser removido
    }
}

// Exercício 7
void removeElement(int arr[], int *size, int value) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (arr[i] == value) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            i--; // Para verificar possíveis ocorrências subsequentes do mesmo valor
        }
    }
    if (!found) {
        printf("Elemento não encontrado na lista.\n");
    }
}

// Função auxiliar para imprimir lista
void printList(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int list[MAX_SIZE] = {5, 3, 7};
    int size = 3; // Tamanho inicial da lista

    // Testando as funções
    printf("Count of 3: %d\n", count(list, size, 3)); // Função do Lab anterior
    printf("Index of 7: %d\n", index(list, size, 7)); // Função do Lab anterior

    printf("Lista com inserção: ");
    insert(list, &size, 1, 2); // Inserindo o valor 2 na posição 1
    printList(list, size);

    printf("Popped element: %d\n", pop(list, &size)); // Removendo o último elemento
    printf("Lista com pop: ");
    printList(list, size);

    printf("Lista com remoção: ");
    removeElement(list, &size, 2); // Removendo o elemento 2
    printList(list, size);

    printf("Lista com reversão: ");
    reverse(list, size); // Função do Lab anterior
    printList(list, size);

    printf("Lista com ordenação: ");
    sort(list, size); // Função do Lab anterior
    printList(list, size);

    return 0;
}