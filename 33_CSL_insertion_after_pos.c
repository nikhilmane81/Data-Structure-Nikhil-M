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
struct node *addafterpos(struct node *tail, int data, int pos)
{
    struct node *newp = malloc((sizeof(struct node)));
    struct node *p = tail->next;
    newp->data = data;
    newp->next = NULL;
    while (pos > 1)
    {
        p = p->next;
        pos--;
    }
    newp->next = p->next;
    p->next = newp;
    if (p == tail)
    {
        tail = tail->next;
    }
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
int main()
{
    struct node *tail;
    tail = addtoEmpty(37);
    tail = addatBeg(tail, 45);
    tail = addatBeg(tail, 46);
    tail = addatBeg(tail, 49);
    tail = addatBeg(tail, 34);
    tail = addatEnd(tail, 56);
    tail = addatEnd(tail, 67);
    tail = addatEnd(tail, 1000);
    printlist(tail);
    tail = addafterpos(tail, 450, 6);
    printlist(tail);

    return 0;
}
