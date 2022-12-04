#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* circularsingly(int data)
{
    struct node *temp = malloc((sizeof(struct node)));
    temp->data = data;
    temp->next = temp;
    return temp;
}
int main()
{
    int data = 45;
    struct node *tail;
    tail = circularsingly(data);
    printf("%d ", tail->data);
    return 0;
}
