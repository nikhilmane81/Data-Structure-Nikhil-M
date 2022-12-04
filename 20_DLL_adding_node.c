#include<stdio.h>
#include<stdlib.h>
typedef struct node //type def to struct node as NODE
{
    int data;
    struct node *prev;
    struct node *next;
}node;
node* addtoempty(node *head, int data);
int main()
{
    node *head = NULL;
    head = addtoempty(head, 56);
    printf("%d ", head->data);
    return 0;
}
node* addtoempty(node *head, int data)
{
    node *temp = (node*)malloc((sizeof(node)));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
    return head;
}