#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int main()
{
    //single linked list (single element)
    struct node *head = NULL;
    head = (struct node*)malloc((sizeof(struct node))); //typecasting is not mandetory
    head->data = 34;
    head->link = NULL;
    struct node *current = malloc((sizeof(struct node)));
    current->data = 45;
    current->link= NULL;
    head->link=current;
    current = malloc((sizeof(struct node)));
    current->data = 44;
    current->link = NULL;
    head->link->link=current;
    //printf("%d ", head->data);
    //printf("%d ", current->data);
    //printf("%d ", head->link);
    return 0;
}
