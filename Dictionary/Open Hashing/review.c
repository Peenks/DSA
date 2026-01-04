#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 10

typedef struct node {
    int data;
    struct node *next;
} *Nodetype;

typedef Nodetype Dictionary[MAX];

// dictionary functions
void initDict(Dictionary D);
int hash(int data);
void insert(Dictionary D, int data);
bool inDict(Dictionary D, int data);
void delete(Dictionary D, int data);
void printDict(Dictionary D);

// helper functions
int* getInput(int *size);
void populateDict(Dictionary D, int arr[], int size);
void askToAdd(Dictionary D);
void askToDelete(Dictionary D);
int cont();

int main() {
    printf("\033[H\033[J");

    Dictionary D;
    int size, choice;
    int *arr = getInput(&size);

    initDict(D);
    populateDict(D, arr, size);

    do {
        askToAdd(D);
        askToDelete(D);
        choice = cont();
    } while(choice != 0);

    printDict(D);

    return 0;
}

// ===========================
// FUNCTION DEFINITIONS (EMPTY)
// ===========================

int* getInput(int *size) {
    // TODO: Ask user for size, allocate memory for array, and return it
    printf("Enter size: ");
    scanf("%d", size);

    int *arr = malloc(sizeof(int) * (*size));

    for(int i = 0; i < *size; ++i){
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    


    return arr;
}

void populateDict(Dictionary D, int arr[], int size) {
    // TODO: Insert elements of arr into Dictionary
    for(int i = 0; i < size; ++i){
        insert(D, arr[i]);
    }
}

void initDict(Dictionary D) {
    // TODO: Initialize dictionary buckets to NULL
    for(int i = 0; i < MAX; ++i){
        D[i] = NULL;
    }
    
}

int hash(int data) {
    // TODO: Return hash index based on data
    return data % MAX;
    
}

void insert(Dictionary D, int data) {
    // TODO: Insert new data into the dictionary
    unsigned int index = hash(data);

    Nodetype *trav;

    for(trav = &D[index]; trav != NULL && (*trav)->data != data; trav = &(*trav)->next) {}

    if(*trav != NULL){
        Nodetype temp = maloc(sizeof(struct node));

        if(temp != NULL){
            temp->data = data;
            temp->next = NULL;
            *trav = temp;
        }

    }


}

void askToAdd(Dictionary D) {
    // TODO: Ask user for an element to find in dictionary
}

bool inDict(Dictionary D, int data) {
    // TODO: Search for element and return true/false

    int index = hash(data);

    Nodetype curr;

    for(curr = D[index]; curr != NULL && curr->data != data; curr = curr->next) {}

    return (curr != NULL) ? true : false;
    
}

void askToDelete(Dictionary D) {
    // TODO: Ask user for an element to delete
}

void delete(Dictionary D, int data) {
    // TODO: Delete element from dictionary
    unsigned int index = hash(data);

    Nodetype *trav;

    for(trav = &D[index]; trav != NULL & (*trav)->data != data; trav = &(*trav)->next) {}

    if(*trav != NULL){
        Nodetype temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

int cont() {
    // TODO: Ask user if they want to continue, return 1 (yes) or 0 (no)
    char c;

    printf("Do you want to continue? : ");
    scanf("%c", c);

    return (tolower(c) == 'y') ? 1 : 0;
}

void printDict(Dictionary D) {
    // TODO: Print all dictionary buckets
}