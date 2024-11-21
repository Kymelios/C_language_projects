#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int number;
    struct Node *next;
};

int countNodes(struct Node *head) // Counts how many nodes in list (start from the first node)
{
    int counter = 0;

    while (head != NULL)
    {
        printf("Node:%d  Value:%d\n", counter, head->number);
        counter++;
        head = head->next;
    }

    return counter;
}

struct Node *createNode(int numb) // Creates a new Node
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->number = numb;
    newNode->next = NULL;

    return newNode;
}

void findNodeValue(struct Node *head, int value) // Finds node velue (start from the first node)
{
    while (head != NULL)
    {
        if (head->number == value)
        {
            printf("Number was found! (%d)\n", head->number);
            return;
        }
        head = head->next;
    }

    printf("Number was not found!\n");
}

struct Node *insertNewNodeAtBeginning(struct Node *head, int value) // Inserts a new node at the beginning of list
{
    struct Node *newNode = createNode(value);

    newNode->next = head;

    head = newNode;

    return head;
}

struct Node *insertNewNodeAtTheEnd(struct Node *head, int value) // Inserts a new node at the end of list
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        return newNode;
    }

    while (head->next != NULL)
    {
        head = head->next;
    }

    head->next = newNode;

    return head;
}

struct Node *insertNewNode(struct Node *head, int targetValue, int newValue, bool insertAtTheBeginning) // Inserts a new node at the specified location 
{
    struct Node *newNode = createNode(newValue);

    struct Node *temp;

    if (insertAtTheBeginning)
    {
        newNode->next = head;

        head = newNode;

        return head;
    }

    while (head->number != targetValue)
    {
        head = head->next;

        if (head->number == targetValue)
        {
            break;
        }
        else if (head->number != targetValue && head->next == NULL)
        {
            printf("No such value in list!\n");
            return head;
        }
        
        
    }

    temp = head->next;

    head->next = newNode;

    newNode->next = temp;

    return head;
}

struct Node *deleteNode(struct Node *head, int targetValue, bool isAtTheBeginning) // Deletes a node at the specified location
{
    struct Node *deleteNode = NULL;

    struct Node *temp;

    if(isAtTheBeginning)
    {
        temp = head->next;

        head = deleteNode;

        head = temp;
        
        return head;
    }

    while (head != NULL)
    {
        if (head->next == NULL)
        {
            return head;
        }  
        if (head->next->number == targetValue)
        {
            break;
        }
        
        head = head->next;
    }

    if (head->next->next != NULL)
    {
        temp = head->next->next;
        head->next = temp;
    }
    else
    {
        head->next = deleteNode;
    }

    return head;
}

void freeList(struct Node *head) {  //Frees list from memory leaks
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = createNode(10);
    struct Node *second = createNode(20);
    struct Node *third = createNode(30);
    struct Node *fourth = createNode(40);

    head->next = second;
    second->next = third;
    third->next = fourth;

    countNodes(head);

    printf("\n");

    insertNewNode(head, 20, 45, false);

    deleteNode(head, 30, false);

    findNodeValue(head, 10);

    countNodes(head);

    return 0;
}