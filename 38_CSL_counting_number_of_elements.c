#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *addtoEmpty(int data)
{
    struct node *temp = malloc((sizeof(struct node)));
    temp->data = data;
    temp->next = temp;
    return temp;
}
struct node *addatBeg(struct node *tail, int data)
{
    struct node *newp = malloc((sizeof(struct node)));
    newp->data = data;
    newp->next = NULL;
    newp->next = tail->next;
    tail->next = newp;
    return tail;
}
struct node *addatEnd(struct node *tail, int data)
{
    struct node *newp = malloc((sizeof(struct node)));
    newp->data = data;
    newp->next = NULL;
    newp->next = tail->next;
    tail->next = newp;
    tail = tail->next;
    return tail;
}
void printlist(struct node *tail)
{
    struct node *p = tail->next;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("\n");
}
void counter(struct node *tail)
{
    struct node *temp = tail->next;
    int count = 0;
    while (temp!=tail)
    {
        count++;
        temp = temp->next;
    }
    count++;
    printf("Total nodes in the list are %d ", count);
}
int main()
{
    struct node *tail;
    tail = addtoEmpty(37);
    tail = addatEnd(tail, 56);
    tail = addatEnd(tail, 67);
    tail = addatEnd(tail, 1000);
    tail = addatEnd(tail, 10);
    tail = addatEnd(tail, 20);
    printlist(tail);
    counter(tail);
    return 0;
}
