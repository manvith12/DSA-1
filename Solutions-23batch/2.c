// building a stack using 2 queues
// logic : 
// 1. Enqueue the new element to the first queue.
// 2. Move all elements from the first queue to the second queue.
// 3. Swap the names of the two queues.
// 4. Dequeue the front element from the first queue.
//
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct queue
{
    int data[MAX];
    int front;
    int rear;
    
} Queue;

void initQueue(Queue* queue)
{
    queue->front = -1;
    queue->rear = -1;
}
 

Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    initQueue(queue);
    return queue;
}
void enqueue(Queue* queue, int value){
    if(queue->rear == MAX - 1){
        printf("Queue is full\n");
        return;
    }

    if(queue->front == -1){
        queue->front = 0;
    }
    queue->rear++;
    queue->data[queue->rear] = value;
}
void dequeue(Queue* queue){
    if(queue->front == -1 || queue->front > queue->rear){
        printf("Queue is empty\n");
        return;
    }
    queue->front++;
}
int front(Queue* queue){
    if(queue->front == -1 || queue->front > queue->rear){
        printf("Queue is empty\n");
        return -1;
    }
    return queue->data[queue->front];
}
int isEmpty(Queue* queue){
    return (queue->front == -1 || queue->front > queue->rear);
}
int size(Queue* queue){
    if(queue->front == -1 || queue->front > queue->rear){
        return 0;
    }
    return queue->rear - queue->front + 1;
}
void display(Queue* queue){
    if(queue->front == -1 || queue->front > queue->rear){
        printf("Queue is empty\n");
        return;
    }
    for(int i = queue->front; i <= queue->rear; i++){
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}
void freeQueue(Queue* queue){
    free(queue);
}

void push(Queue* queue1, Queue* queue2, int value) {
    enqueue(queue2, value);
    while (!isEmpty(queue1)) {
        enqueue(queue2, front(queue1));
        dequeue(queue1);
    }
 
    Queue temp = *queue1;
    *queue1 = *queue2;
    *queue2 = temp;
}

int pop(Queue* queue1) {
    if (isEmpty(queue1)) {
        printf("Stack is empty\n");
        return -1;
    }
    int value = front(queue1);
    dequeue(queue1);
    return value;
}
int pop(Queue* queue){
    if(isEmpty(queue)){
        printf("Stack is empty\n");
        return -1;
    }
    int value = front(queue);
    dequeue(queue);
    return value;
}
int top(Queue* queue){
    if(isEmpty(queue)){
        printf("Stack is empty\n");
        return -1;
    }
    return front(queue);
}

void stackUsingQueues() {
    Queue* queue1 = createQueue();
    Queue* queue2 = createQueue();
    int choice, value;
    while (1) {
        printf("1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(queue1, queue2, value);
                break;
            case 2:
                value = pop(queue1);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = top(queue1);
                if (value != -1) {
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                display(queue1);
                break;
            case 5:
                freeQueue(queue1);
                freeQueue(queue2);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
int main(){
    stackUsingQueues();
    return 0;
}

