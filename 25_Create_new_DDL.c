#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node* addtoEmpty(struct node *head, int data);
struct node* addatend(struct node *head, int data);
struct node *createList(struct node *head);
int main()
{
    struct node *head = NULL;
    struct node *ptr;
    head = createList(head);
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
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
struct node *createList(struct node *head)
{
    int n, data, i;
    printf("Enter the number of nodes ");
    scanf("%d", &n);
    if (n==0)
    {
        return head;
    }
    printf("Enter the element for node 1 ");
    scanf("%d", data);
    head = addtoEmpty(head, data);
    for (i = 1; i < n; i++)
    {
        printf("Enter the number of node %d ", i+1);
        scanf("%d",&data);
        head = addatend(head, data);
    }
    return head;
}
struct node* addatend(struct node *head, int data)
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
