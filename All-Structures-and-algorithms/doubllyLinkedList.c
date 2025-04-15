#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

DNode* createDNode(int data){
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

DNode* insertAtend(DNode **head, int data)
{
    DNode *newNode = createNode(data);
    DNode *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

DNode* insertatBeginning(DNode **head, int data){
    DNode *newNode = createNode(data);
    newNode->prev = NULL;
    newNode->next = *head;

    if(*head != NULL){
        (*head)->prev = newNode;
    }

    *head = newNode;
    return  newNode;
}
DNode* insertatBeginning(DNode **head, int data){
    DNode *newNode = createNode(data);
    newNode->prev = NULL;
    newNode->next = head;
}

void deleteAtBeginning(DNode **head){
    if(*head == NULL) return;
    DNode *temp = *head;
   *head = temp->next;

    if(*head != NULL){
        (*head)->prev= NULL;
    }

    
    free(temp);
}

void deleteAtend(DNode **head){
    if(*head == NULL){
        return;
    }

    DNode *temp = *head;
    while(temp->next){
        temp = temp->next;
    }
    if(temp->prev){
        temp->prev->next = NULL;
    }

}

