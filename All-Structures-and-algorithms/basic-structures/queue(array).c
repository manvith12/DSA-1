#define QMAX 100

typedef struct {
    int data[QMAX];
    int front, rear, size;
}Queue;

void initQueue(Queue *q){
    q->front = q->rear = q->size = 0;
}

int isEmptyQueue(Queue *q){

    return q->size == 0;

}

int isFullQueue(Queue *q){

    return q->size == QMAX;

}

void enqueue(Queue *q, int val){
    if(isFullQueue(q)) return;
    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % QMAX;
    q->size++;
}

void dequeue(Queue *q){
    if (isEmptyQueue(q)) return;
    int val = q->data[q->front];
    q->front = (q->front+1)% QMAX;
    q->size--;
    return val;
}

int peekQueue(Queue *q){
    if(isEmptyQueue(q)) return -1;
    return q->data[q->front];
}
void displayQueue(Queue *q){
    if(isEmptyQueue(q)) return;
    int i = q->front;
    for(int j = 0; j < q->size; j++){
        printf("%d ", q->data[i]);
        i = (i + 1) % QMAX;
    }
    printf("\n");
}
