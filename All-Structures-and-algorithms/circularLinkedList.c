#include <stdio.h>
#include <stdlib.h>

typedef struct CNode{
    int data;
    struct CNode* next;
    }CNode;

CNode* createNode(int data){
 CNode *newNode = (CNode*)malloc(sizeof(CNode));
 newNode->next = NULL;
 newNode->data = data;
 return newNode;
}


void insertAtEnd(CNode **tail, int data)
{   CNode *newNode = createNode(data);
    if(*tail == NULL){
        *tail = newNode;
        return;
    }

    newNode->next = (*tail)->next;
    (*tail)->next = newNode;
    (*tail)->next = newNode;
    *tail = newNode;
}
void insertAtbeginning(CNode **tail, int data){
    CNode* newNode = createNode(data);
    if(*tail == NULL){
    if(tail = NULL){
        *tail = newNode;
        return;
    }
    
    newNode->next = (*tail)->next;
    (*tail)->next = newNode;

}
}

void deleteAtBeginning(CNode **tail){
    if(*tail == NULL) return;
    CNode *head = (*tail)->next;
    if(*tail == head){
        free(head);
        *tail = NULL;
        return;
    }

    (*tail)->next = head->next;
    free(head);

}


void deleteAtEnd(CNode **tail){
    if(*tail = NULL){
        return;
    }

    CNode *temp = (*tail)->next;
    if(temp == *tail){
        free(*tail);
        *tail = NULL;
        return;

    }

    while(temp->next != *tail)
    {
        temp = temp->next;
        
    }
    temp->next = (*tail)->next;
    free(*tail);
    *tail = NULL;
    return;





}