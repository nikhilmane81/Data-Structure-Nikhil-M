#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node* addtoEmpty(struct node *head, int data);
struct node* addatbeg(struct node *head, int data);
int main()
{
    struct node *head = NULL;
    struct node *ptr;
    head = addtoEmpty(head, 40);
    head = addatbeg(head, 99);
    head = addatbeg(head, 98);
    head = addatbeg(head, 101);
    head = addatbeg(head, 200);
    head = addatbeg(head, 333);
    ptr = head;
     while (ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    
return 0;
}
struct node* addtoEmpty(struct node *head, int data)
{
    struct node *temp = malloc((sizeof(struct node)));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}
struct node* addatbeg(struct node *head, int data)
{
    struct node *temp = malloc((sizeof(struct node)));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}
