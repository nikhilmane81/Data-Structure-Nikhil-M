#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *addtoEmpty(int data)
{
    struct node *temp = (struct node *)malloc((sizeof(struct node)));
    temp->data = data;
    temp->prev = temp;
    temp->next = temp;
    return temp;
}
struct node *addatBeg(struct node *tail, int data)
{
    struct node *newp = addtoEmpty(data);
    if (tail == NULL)
    {
        return newp;
    }
    else
    {
        struct node *temp = tail->next;
        newp->next = temp;
        newp->prev = tail;
        temp->prev = newp;
        tail->next = newp;
        return tail;
    }
}
struct node* addatEnd(struct node * tail, int data)
{
    struct node* newp = addtoEmpty(data);
    if (tail == NULL)
    {
        return newp;
    }
    else
    {
        struct node *temp = tail->next;
        newp->next = temp;
        newp->prev = tail;
        tail->next = newp;
        temp->prev = newp;
        tail = newp;
        return tail;
    }
    
}
void printlist(struct node *tail)
{
    if (tail == NULL)
    {
        printf("No element in the list");
    }
    else
    {
        struct node *temp = tail->next;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
    }
    printf("\n");
}
int main()
{
    struct node *tail = NULL;
    tail = addtoEmpty(45);
    tail = addatEnd(tail, 67);
    tail = addatEnd(tail, 87);
    tail = addatEnd(tail, 47);
    tail = addatEnd(tail, 27);
    printlist(tail);
    return 0;
}