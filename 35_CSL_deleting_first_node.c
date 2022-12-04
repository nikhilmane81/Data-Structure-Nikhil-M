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
struct node *Delfirst(struct node *tail)
{
    if (tail == NULL)
    {
        return tail;
    }
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    struct node *temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return tail;
}
int main()
{
    struct node *tail;
    tail = addtoEmpty(45);
    tail = addatEnd(tail, 56);
    tail = addatEnd(tail, 46);
    tail = addatEnd(tail, 76);
    printlist(tail);
    tail = Delfirst(tail);
    printlist(tail);
    return 0;
}