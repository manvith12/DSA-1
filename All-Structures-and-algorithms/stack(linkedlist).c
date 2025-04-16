#include <stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode *next;

}StackNode;

void pushLL(StackNode **top, int val){
    StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int popLL(StackNode **top){
    if(*top == NULL) return -1;
    StackNode *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int peekLL(StackNode *top){
    if(top == NULL)return -1;
    return top->data;
}

void deleteStackLL(StackNode **top){
    while(top != NULL){
        StackNode *temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}