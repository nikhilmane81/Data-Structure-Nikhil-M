#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* add_at_end(struct node *ptr, int data);
void del_pos(struct node **head, int pos);
int main()
{
    int pos = 2;
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
    del_pos(&head, pos);
    ptr = head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0 ;
}
struct node* add_at_end(struct node *ptr, int data)
{
    struct node *temp =  (struct node*)malloc((sizeof(struct node)));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}
void del_pos(struct node **head, int pos)
{
    struct node *current = *head;
    struct node *previous = *head;
    if (head==NULL)
    {
        printf("List is empty");
    }
    else if (pos == 1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while (pos != 1)
        {
            previous = current;
            current = current->link;
            pos--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
        
    }
       
}