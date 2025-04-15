// we will build a linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Node* insertNode(Node* head, int data)
{
    Node* newNode = createNode(data);
    if(head == NULL){
        return newNode;
    }

    else{
        Node* temp = head;
        temp->next = newNode;
        return head;
    }
}


Node* deleteNode(Node* head , int data){
    if(head == NULL){
        return NULL;
    }

    if(head->data == data){
        Node* temp = head->next;
        free(head);
        return temp;
    }
   else{
        Node* current = head;
        while(current->next != NULL && current->next->data != data){
            current = current->next;
        }
        if(current->next == NULL){
            return head;
        }
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        return head;
    }
 }


 void displayList(Node* head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
 }

Node* insertAtEnd(Node* head, int data){
    Node* newNode = createNode(data);
    while(head->next != NULL){
        head = head->next;
    }
    head->next = newNode;
    return head;
}

Node* insertAtPosition(Node* head, int data, int position){
    Node* newNode = createNode(data);
    if(position == 0){
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    for(int i = 0; i < position - 1 && current != NULL; i++){
        current = current->next;
    }
    if(current == NULL){
        printf("Position out of bounds\n");
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int length(Node* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

Node* reverseList(Node* head){
  Node* prev = NULL;
  Node* current = head;
  Node* next = NULL;
  while(current != NULL){
    next = current->next;
    current->next= prev;
    prev = current;
    current = next;
  }
}

Node* search(Node* head, int data){
    while(head != NULL){
        if(head->data == data){
            return head;
        }
    }
    return NULL;
}


int main(){
    // we dont talk about this 
}