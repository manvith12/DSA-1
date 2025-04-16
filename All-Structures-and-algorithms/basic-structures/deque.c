#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Deque
{
    int arr[MAX];
    int front, rear;
} Deque;

Deque *create_deque()
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->front = -1;
    deque->rear = -1;
    return deque;
}

int is_empty(Deque *deque)
{
    return deque->front == -1;
}

int is_full(Deque *deque)
{
    return ((deque->rear + 1) % MAX) == deque->front;
}

void insert_front(Deque *deque, int data)
{
    if (is_full(deque))
    {
        printf("Deque overflow\n");
        return;
    }
    if (is_empty(deque))
    {
        deque->front = deque->rear = 0;
    }
    else
    {
        deque->front = (deque->front - 1 + MAX) % MAX;
    }
    deque->arr[deque->front] = data;
}

void insert_rear(Deque *deque, int data)
{
    if (is_full(deque))
    {
        printf("Deque overflow\n");
        return;
    }
    if (is_empty(deque))
    {
        deque->front = deque->rear = 0;
    }
    else
    {
        deque->rear = (deque->rear + 1) % MAX;
    }
    deque->arr[deque->rear] = data;
}

int delete_front(Deque *deque)
{
    if (is_empty(deque))
    {
        printf("Deque underflow\n");
        return -1;
    }
    int data = deque->arr[deque->front];
    if (deque->front == deque->rear)
    {
        deque->front = deque->rear = -1;
    }
    else
    {
        deque->front = (deque->front + 1) % MAX;
    }
    return data;
}

int delete_rear(Deque *deque)
{
    if (is_empty(deque))
    {
        printf("Deque underflow\n");
        return -1;
    }
    int data = deque->arr[deque->rear];
    if (deque->front == deque->rear)
    {
        deque->front = deque->rear = -1;
    }
    else
    {
        deque->rear = (deque->rear - 1 + MAX) % MAX;
    }
    return data;
}

int get_front(Deque *deque)
{
    if (is_empty(deque))
    {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->arr[deque->front];
}

int get_rear(Deque *deque)
{
    if (is_empty(deque))
    {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->arr[deque->rear];
}

void print_deque(Deque *deque)
{
    if (is_empty(deque))
    {
        printf("Deque is empty\n");
        return;
    }
    int i = deque->front;
    printf("Deque: ");
    while (1)
    {
        printf("%d ", deque->arr[i]);
        if (i == deque->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void destroy_deque(Deque *deque)
{
    free(deque);
}

int main()
{
    Deque *deque = create_deque();
    insert_rear(deque, 10);
    insert_rear(deque, 20);
    insert_front(deque, 5);
    print_deque(deque);
    printf("Front: %d, Rear: %d\n", get_front(deque), get_rear(deque));
    delete_front(deque);
    delete_rear(deque);
    print_deque(deque);
    destroy_deque(deque);
    return 0;
}