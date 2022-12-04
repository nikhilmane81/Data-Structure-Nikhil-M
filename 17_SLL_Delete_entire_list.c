#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* add_at_end(struct node *ptr, int data);
struct node* del_list(struct node *head);
int main()
{
    struct node *head = (struct node*)malloc((sizeof(struct node)));
    head->data = 35;
    head->link = NULL;
    struct node *ptr = head;
    ptr = add_at_end(ptr, 45);
    ptr = add_at_end(ptr, 55);
    ptr = add_at_end(ptr, 78);
    ptr = head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    head = del_list(head);
    if (head==NULL)
    {
        printf("List deleted successfully");
    }
return 0 ;  
    
}
struct node* add_at_end(struct node *ptr, int data)
{
    struct node *temp = (struct node*)malloc((sizeof(struct node)));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}
struct node* del_list(struct node *head)
{
    struct node *temp = head;
    while (temp!=NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    return head;  
}