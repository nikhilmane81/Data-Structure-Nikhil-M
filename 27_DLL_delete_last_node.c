#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node* addatend(struct node *head, int data);
struct node* addtoEmpty(struct node *head, int data);
struct node* addatbeg(struct node *head, int data);
struct node* delFirst(struct node *head);
void printlist(struct node *head);
struct node* delLast(struct node *head);
int main()
{
    struct node *head= NULL;
    struct node *ptr=NULL;
    head = addtoEmpty(head, 23);
    //head = addatbeg(head, 22);
    head = addatend(head, 24);
    head = addatend(head, 25);
    head = addatend(head, 65);
    head = addatend(head, 75);
    printlist(head);
    head = delFirst(head);
    head = delLast(head);
    printlist(head);
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
struct node* addatend(struct node *head, int data)
{
    struct node *temp, *tp;
    temp = malloc((sizeof(struct node)));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    while (tp->next!=NULL)
    {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;  
}
void printlist(struct node *head)
{
    struct node *ptr = head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
struct node* delFirst(struct node *head)
{
    struct node *temp = head;
    head =temp->next;
    free(temp);
    temp = NULL;
    head->prev = NULL;
    return head;
}
struct node* delLast(struct node *head)
{
    struct node *temp = head;
    struct node *temp2;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
    temp = NULL;
    return head;
    
}