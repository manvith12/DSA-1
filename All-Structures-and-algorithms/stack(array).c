#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
}Stack;

void initStack(Stack *s){
    s->top = -1;
}

int isEmptyStack(Stack *s){
    return s->top == -1;
}

int isFullStack(Stack *s){
    return s->top == MAX - 1;
}

void pushStack(Stack *s, int val){
    if(isFullStack(s)) return;
    s->data[++s->top] = val;
}

int popStack(Stack *s){
    if(isEmptyStack(s)) return -1;
    return s->data[s->top--];
}
int peekStack(Stack *s){
    if(isEmptyStack(s)) return -1;
    return s->data[s->top];
}
void deleteStack(Stack *s){
    s->top = -1;
}
void printStack(Stack *s){
    if(isEmptyStack(s)){
        printf("Stack is empty\n");
        return;
    }
    for(int i = s->top; i >= 0; i--){
        printf("%d ", s->data[i]);
    }
    printf("\n");
}