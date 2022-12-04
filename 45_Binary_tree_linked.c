#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int data)
{
    struct node* temp = (struct node*)malloc((sizeof(struct node)));
    temp->data= data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int main()
{
    struct node *root = createNode(23);
    struct node *p1 = createNode(25);
    struct node *p2 = createNode(25);
    //linking the parent to child
    root->left = p1;
    root->right = p2;
    //before creating function, tried manaually assigning all the nodes
    // which is repetative task
    //to avoid repetation we have functions in C
    //root = (struct node*)malloc((sizeof(struct node)));
    //root->left = NULL;
    //root->right = NULL;
    //root->data = 10;
    //struct node *p1;
    //p1 = (struct node*)malloc((sizeof(struct node)));
    //p1->left = NULL;
    //p1->right = NULL;
    //p1->data = 20;
    //struct node *p2;
    //p2 = (struct node*)malloc((sizeof(struct node)));
    //p2->left = NULL;
    //p2->right = NULL;
    //p2->data = 30;
    return 0 ;
}
