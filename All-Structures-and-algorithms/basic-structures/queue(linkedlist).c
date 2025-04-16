#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int data;
    struct Queue* next;
}Queue;

typedef struct{
    Queue* front;
    Queue* rear;

}QueueLL;

void enqueueLL(QueueLL *q , int val){
    Queue* newNode = (Queue*)malloc(sizeof(Queue));
    newNode->data = val;
    newNode->next = NULL;
    if(!q->rear){
        q->front = q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeueLL(QueueLL *q){
    if(!q->front) return -1;
    Queue* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if(!q->front) q->rear = NULL;
    free(temp);
    return val;
}

int peakLLQueue(QueueLL *q){
    if(!q->front) return -1;
    return q->front->data;
}



