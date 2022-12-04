#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* add_at_end(struct node *ptr, int data);
struct node* add_at_pos(struct node* head, int data, int pos);
int main()
{
    int data = 45, pos = 2;
    struct node *head = (struct node*)malloc((sizeof(struct node)));
    head->data = 30;
    head->link = NULL;
    struct node *ptr = head;
    ptr = add_at_end(ptr,35);
    ptr = add_at_end(ptr,45);
    ptr = add_at_end(ptr,55);
    ptr = add_at_end(ptr,65);
    ptr = head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
    add_at_pos(head, data, pos);
    ptr = head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0; 
}
struct node* add_at_end(struct node *ptr, int data)
{
    struct node *temp =  (struct node*)malloc((sizeof(struct node)));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}
struct node* add_at_pos(struct node* head, int data, int pos) //adding node at given position
{
    struct node *ptr = head; 
    struct node *ptr2 = (struct node*)malloc((sizeof(struct node))); //creating node which is to be added
    ptr2->data = data;
    ptr2->link = NULL;
    pos--;
    while(pos!=1)
    {
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}
