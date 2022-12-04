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
    while (temp != tail)
    {
        count++;
        temp = temp->next;
    }
    count++;
    printf("Total nodes in the list are %d ", count);
}
int searchtheElement(struct node *tail, int element)
{
    struct node *temp;
    int index = 0;
    if (tail == NULL)
    {
        return -2;
    }
    temp = tail->next;
    do
    {
        if (temp->data == element)
            return index;
        temp = temp->next;
        index++;
    } while (temp != tail->next);
    return -1;
}
int main()
{
    struct node *tail;
    int element;
    tail = addtoEmpty(37);
    tail = addatEnd(tail, 56);
    tail = addatEnd(tail, 67);
    tail = addatEnd(tail, 1000);
    tail = addatEnd(tail, 10);
    tail = addatEnd(tail, 20);
    printf("Enter the element to be searched ");
    scanf("%d", &element);
    int index = searchtheElement(tail, element);
    if (index == -1)
        printf("Element not found");
    else if (index == -2)
        printf("Linked list is empty");
    else
        printf("Element %d is at index %d ", element, index);
    return 0;
}
