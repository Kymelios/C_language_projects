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
    return q->tail == QUEUE_SIZE - 1; // QUEUE_SIZE - 1 as with stuck we do -1 because array starts from 0 to 4
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

    q->tail++;
    q->queue[q->tail] = value;

    printf("INSERTED Value:%d - Head:%d - Tail:%d\n", value, q->head, q->tail);
}

void deQueue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty!");
        return;
    }

    printf("DELETED Value:%d - Head:%d - Tail:%d\n", q->queue[q->head], q->head, q->tail);
    q->head++;

    if (q->head > q->tail)
    {
        initQueue(q);
    }
}

void printQueue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Nothing to print, queue is empty!");
        return;
    }

    printf("\nQueue: ");

    for (int i = q->head; i <= q->tail; i++)
    {
        printf("_%d_", q->queue[i]);
    }

    printf("\n\n");
}

int main()
{
    Queue *q = malloc(sizeof(Queue)); // Creating a dynamic structure by allocating memory

    initQueue(q);

    enQueue(q, 10);

    enQueue(q, 12);

    enQueue(q, 14);

    printQueue(q);

    deQueue(q);

    deQueue(q);

    printQueue(q);

    free(q); // And of course we hava to free our memory to prevent memory leaks

    return 0;
}