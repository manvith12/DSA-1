#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define maximum size of the queue

typedef struct CQueue
{
    int front, rear, size;
    int arr[MAX];
} CQueue;

CQueue *create_queue()
{
    CQueue *queue = (CQueue *)malloc(sizeof(CQueue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int is_empty(CQueue *queue)
{
    return queue->size == 0;
}

int is_full(CQueue *queue)
{
    return queue->size == MAX;
}

void enqueue(CQueue *queue, int data)
{
    if (is_full(queue))
    {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) // First element case
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX;
    queue->arr[queue->rear] = data;
    queue->size++;
    printf("Enqueued: %d\n", data);
}

int dequeue(CQueue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->size--;
    if (queue->size == 0) // Reset when queue is empty
        queue->front = queue->rear = -1;
    return data;
}

int front(CQueue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->front];
}

int rear(CQueue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->rear];
}

void print_queue(CQueue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0, index = queue->front; i < queue->size; i++)
    {
        printf("%d ", queue->arr[index]);
        index = (index + 1) % MAX;
    }
    printf("\n");
}

void destroy_queue(CQueue *queue)
{
    if (queue == NULL)
        return;
    free(queue->arr); // Free the array if dynamically allocated
    free(queue);
}

int main()
{
    CQueue *queue = create_queue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    print_queue(queue);
    printf("Dequeued: %d\n", dequeue(queue));
    enqueue(queue, 60);
    print_queue(queue);
    destroy_queue(queue);
    return 0;
}