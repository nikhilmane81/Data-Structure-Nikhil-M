#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* add_at_end(struct node *ptr, int data);
struct node* reverse(struct node *head);

int main()
{
    struct node *head = (struct node *)malloc((sizeof(struct node)));
    head->data = 35;
    head->link = NULL;
    struct node *ptr = head;
    ptr = add_at_end(ptr, 45);
    ptr = add_at_end(ptr, 46);
    ptr = add_at_end(ptr, 47);
    ptr = add_at_end(ptr, 48);
    ptr = add_at_end(ptr, 49);
    ptr = add_at_end(ptr, 50);
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    head = reverse(head);
    ptr = head;
    while (ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    return 0;

}
struct node* add_at_end(struct node *ptr, int data)
{
    struct node *temp = (struct node *)malloc((sizeof(struct node)));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}
struct node* reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *next = NULL;
    while (head!=NULL)
    {
        next = head->link;
        head->link = prev;
        prev=head;
        head = next;
    }
    head=prev;
    return head;   
}