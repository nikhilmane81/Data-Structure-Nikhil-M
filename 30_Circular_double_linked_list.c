#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;
node* circulardoubly(int data)
{
    node *temp = malloc((sizeof(struct node)));
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
}
int main()
{
    int data = 55;
    struct node *tail;
    tail = circulardoubly(data);
    printf("%d ", tail->data);
    return 0;
}

