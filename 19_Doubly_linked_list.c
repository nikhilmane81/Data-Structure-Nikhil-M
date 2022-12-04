//simple representation of doubly linked list which has prev pointer, data and next pointer
#include<stdio.h>
#include<stdlib.h>
typedef struct node //type def to struct node as NODE
{
    int data;
    struct node *prev;
    struct node *next;
}node;
int main()
{
    node *head = (node*)malloc((sizeof(node)));
    head->prev = NULL;
    head->data = 10;
    head->next = NULL;
    return 0;
}

