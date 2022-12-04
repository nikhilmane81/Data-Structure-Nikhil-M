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
    tail = addatBeg(tail, 67);
    tail = addatBeg(tail, 57);
    tail = addatBeg(tail, 77);
    tail = addatBeg(tail, 87);
    printlist(tail);
    return 0;
}