#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node* add_beg(struct node* head, int d) // for another way:- struct node* add_beg(struct node **head, int d)
{
    struct node *ptr = malloc((sizeof(struct node)));
    ptr->data = d;
    ptr->link = NULL;
    ptr->link = head;
    head = ptr;
    return head;
}
int main()
{
    struct node *head = malloc((sizeof(struct node)));
    head->data = 45;
    head->link = NULL;
    struct node *ptr = malloc((sizeof(struct node)));
    ptr->data = 55;
    ptr->link = NULL;
    head->link = ptr;
    head = add_beg(head, 25); //another way :- add_beg(&head, 25)
    ptr = head;
    while (ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}
