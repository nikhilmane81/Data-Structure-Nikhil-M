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
void preorder(struct node *root)
{
    if (root!=NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
}
void postorder(struct node *root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
    
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main()
{
    struct node *root = createNode(23);
    struct node *p1 = createNode(35);
    struct node *p2 = createNode(45);
    struct node *p3 = createNode(55);
    struct node *p4 = createNode(75);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    return 0 ;
}
