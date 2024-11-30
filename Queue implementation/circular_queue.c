#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5

typedef struct
{
    int queue[QUEUE_SIZE];
    int head;
    int tail;
} Queue;

void initQueue(Queue *q)
{
    q->head = -1;
    q->tail = -1;
}

int isQueueEmpty(Queue *q)
{
    return q->head == -1;
}

int isQueueFull(Queue *q)
{
    return q->head == (q->tail + 1) % QUEUE_SIZE;
}

void enQueue(Queue *q, int value)
{
    if (isQueueFull(q))
    {
        printf("Queue is full!\n");
        return;
    }

    if (isQueueEmpty(q))
    {
        q->head = 0;
    }

    printf("INSERTED Value:%d - Head:%d - Tail:%d\n", value, q->head, q->tail);
    q->tail = (q->tail + 1) % QUEUE_SIZE;
    q->queue[q->tail] = value;
}

void deQueue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("DELETED Value:%d - Head:%d - Tail:%d\n", q->queue[q->head], q->head, q->tail);

    if (q->head == q->tail)
    {
        printf("The last element was dequeued!\n");
        initQueue(q);
        return;
    }

    q->queue[q->head] = 0; //Assigning 0 to indicate an freed place in queue
    q->head = (q->head + 1) % QUEUE_SIZE;
}

void printQueue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Nothing to print, queue is empty!\n");
        return;
    }
    
    printf("\nQueue: ");

    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        printf("_%d_", q->queue[i]);
    }

    printf("\n\n");
}

int main()
{
    Queue *q = malloc(sizeof(Queue));
    initQueue(q);

    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);

    deQueue(q);

    printQueue(q);

    enQueue(q, 4);
    enQueue(q, 5);
    enQueue(q, 6);

    deQueue(q);

    printQueue(q);
    
    free(q);

    return 0;
}