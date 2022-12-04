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
struct node *DeleteLast(struct node *tail)
{
    if (tail == NULL)
    {
        return tail;
    }
    struct node *temp = tail->next;
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
    return tail;
}
struct node *Deleteatpos(struct node *tail, int pos)
{
    if (tail == NULL)
    {
        return tail;
    }
    struct node *temp = tail->next;
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while (pos > 2)
    {
        temp = temp->next;
        pos--;
    }
    struct node *temp2 = temp->next;
    temp->next = temp2->next;
    // handling the case for deleting the last node
    if (temp2 == tail)
    {
        tail = temp;
        free(temp2);
        temp2 = NULL;
        return tail;
    }
}
int main()
{
    struct node *tail;
    tail = addtoEmpty(45);
    tail = addatEnd(tail, 56);
    tail = addatEnd(tail, 46);
    tail = addatEnd(tail, 76);
    tail = addatEnd(tail, 66);
    tail = addatEnd(tail, 86);
    tail = addatEnd(tail, 96);
    printlist(tail);
    // tail = Delfirst(tail);
    // printlist(tail);
    // tail = DeleteLast(tail);
    // printlist(tail);
    tail = Deleteatpos(tail, 5);
    printlist(tail);
    return 0;
}