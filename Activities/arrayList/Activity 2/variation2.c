#include <stdio.h>

#define MAX 10

typedef struct {
    char elem[MAX];
    int count;
} Etype, *Eptr;

void initialize(Eptr L);
void insertPos(Eptr L, char data, int pos);
void deletePos(Eptr L, int pos);
int locate(Eptr L, char data);
char retrieve(Eptr L, int pos);
void insertSorted(Eptr L, char data);
void makeNULL(Eptr L);

int main(){
    Eptr L;

    L->elem[0] = 'J';
    L->elem[1] = 'U';
    L->elem[2] = 'S';
    L->elem[3] = 'T';
    L->elem[4] = 'I';
    L->elem[5] = 'N';

    return 0;
}