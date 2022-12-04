#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *addtoEmpty(struct node *head, int data);
struct node *addatend(struct node *head, int data);
struct node *addatbeg(struct node *head, int data);
struct node *addbeforepos(struct node *head, int data, int pos);
int main()
{
    struct node *head = NULL;
    struct node *ptr = NULL;
    int pos = 2;
    head = addtoEmpty(head, 20);
    head = addatbeg(head, 18);
    head = addatend(head, 45);
    head = addbeforepos(head, 67, pos);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}
struct node *addtoEmpty(struct node *head, int data)
{
    struct node *temp = malloc((sizeof(struct node)));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}
struct node *addatend(struct node *head, int data)
{
    struct node *temp, *tp;
    temp = malloc((sizeof(struct node)));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    while (tp->next != NULL)
    {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
}
struct node *addbeforepos(struct node *head, int data, int pos)
{
    struct node *newp = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newp = addtoEmpty(newp, data);
    while (pos > 2)
    {
        temp = temp->next;
        pos--;
    }
    if (pos == 1)
    {
        head = addatbeg(head, data);
    }
    else
    {
        temp2 = temp->next;
        temp->next = newp;
        temp2->prev = newp;
        newp->next = temp2;
        newp->prev = temp;
    }
    return head;
}
struct node *addatbeg(struct node *head, int data)
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