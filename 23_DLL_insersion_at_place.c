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
struct node *addafterpos(struct node *head, int data, int pos);
int main()
{
    struct node *head = NULL;
    struct node *ptr = NULL;
    int pos = 2;
    head = addtoEmpty(head, 20);
    head = addatbeg(head, 18);
    head = addatend(head, 45);
    head = addafterpos(head, 67, pos);
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
struct node *addafterpos(struct node *head, int data, int pos)
{
    struct node *newp = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newp = addtoEmpty(newp, data);
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    if (temp->next == NULL)
    {
        temp->next = newp;
        newp->prev = temp;
    }
    else
    {
        temp2 = temp->next;
        temp->next = newp;
        temp2->prev = newp;
        newp->prev = temp2;
        newp->next = temp;
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