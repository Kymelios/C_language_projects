#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5 // Stack size

int counter = 0; // Counter for quantity of elements in Stack

struct Stack
{
    int stack[STACK_SIZE];
    int TOP;
};
typedef struct Stack STACK;

void createStack(STACK *stk)
{
    stk->TOP = -1;
    printf("Stack Created!\n");
}

int isStackFull(STACK *stk)
{
    return stk->TOP == STACK_SIZE - 1;
}

int isStackEmpty(STACK *stk)
{
    return stk->TOP == -1;
}

void push(STACK *stk, int newValue)
{
    if (isStackFull(stk))
    {
        printf("Stack is full!\n");
        return;
    }

    stk->TOP++;
    stk->stack[stk->TOP] = newValue;
    counter++;
}

void peek(STACK *stk)
{
    if (isStackEmpty(stk))
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element of the stack: %d\n", stk->stack[stk->TOP]);
}

void pop(STACK *stk)
{
    if (isStackEmpty(stk))
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Element %d was popped\n", stk->stack[stk->TOP]);
    counter--;
    stk->TOP--;
}

void printStack(STACK *stk)
{
    for (int i = counter - 1; i != -1; i--)
    {
        printf("%d\n", stk->stack[i]);
    }
}

int main()
{
    STACK *stk = malloc(sizeof(STACK));

    createStack(stk);

    push(stk, 13);
    push(stk, 16);
    push(stk, 19);

    printStack(stk);

    peek(stk);

    pop(stk);

    peek(stk);

    printStack(stk);

    return 0;
}
