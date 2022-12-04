#include<stdio.h>
#include<stdlib.h>
//structure declaration
typedef struct node
{
    int info; //data part of the node
    struct node *next; // address part of the node
}NODE;
//Global pointers to store the starting and ending addressed
NODE *head=NULL;
//function declaration
void displayList(); //display all data in list
NODE* createNode(int val); //allocate node and initialize it
void addFirst(); // add the node at the start of the list
void addLast(); // add the node at the end of the list
void insert(int pos, int val); //add the node at the given position in list
int delFirst(); //delete the node at first position
void del(int pos); // Delete the node at given position
void delAll(); //delete all elements from the list
int main()
{
    int choice, value, pos;
    do
    {
        printf("1. Exit \n 2. display \n 3. add first \n 4. add last ");
        printf("4. insert at pos. \n 5. delete fist. \n 6.Delete at position \n 7. delete all");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: //display
            displayList();
            break;
        case 2: //add first
            printf("Enter a value");
            scanf("%d",&value);
            addFirst(value);
            break;
        case 3: // add last
            printf("Enter a value");
            scanf("%d",&value);
            printf("Enter a position");
            scanf("%d",&pos);
            insert(pos, value);
            break;
        case 5: //delete first
            delFirst();
            break;
        case 6: //delete at position
            printf("Enter the position");
            scanf("%d",&pos);
            del(pos);
            break;
        case 7: //delete all
            delAll();
            break;
        default:
            break;
        }
    }while(choice!=0);
delAll(); // to avoid memory leakage
}
//function defination, starting with display all the data in the list
void displayList()
{
    NODE *trav;
    printf("List :: ");
    trav=head; //initiating trav to start of the list
    while (trav!=NULL)
    {
        printf("%d --> ", trav->info); //print node data
        trav=trav->next;
    }
    printf("\n");
}
// allocate node and initiate it
NODE* createNode(int val)
{
    NODE *newnode;
    newnode=(NODE*)malloc(sizeof(NODE)); //allocate memory for the node
    newnode->info=val; //initiate node data
    newnode->next=NULL; // initiate next pointer to NULL
    return newnode;
}
//add the node at the start of the list
void addFirst(int val)
{
    NODE *newnode;
    newnode=createNode(val);
    if(head==NULL) //if the list is empty
        head=newnode; //newnode is first node
    else
    {
        newnode->next=head; //add the node before/first node
        head=newnode; //consider newnode as head now
    }
}
//add the node at the end of the list
void addLast(int val)
{
    NODE *newnode, *trav;
    newnode=createNode(val);
    if(head==NULL) //if the list is empty
        head=newnode; //newnode is first node
    else
    {
        trav=head;
        while(trav->next!=NULL)
            trav=trav->next;
        trav->next=newnode; //add the node after last/tail  node
    }
}
//add the node at any given position in the list
void insert(int pos, int val)
{
    int i;
    NODE *trav, *newnode;
    if(head==NULL || pos<=1) // if position is 1 or before
        addFirst(val); // add node at the start of the list
    else
    {
        trav=head; // init trav to start of the list
        //transverse to the node before given pos
        for (int  i = 0; i < pos-1; i++)
        {
            trav= trav->next;
            if(trav==NULL)
            {
                printf("Invalid position\n");
                return;
            }
        }
        newnode = createNode(val); //create new node
        //add the node after trav node
        newnode->next = trav->next;
        trav->next= newnode;
    }
}
//Delete the node at first position
int delFirst()
{
    NODE *temp;
    int val=0;
    if(head==NULL) //if list is empty
    {
        printf("List if empty");
        return 0;
    }
    val=head->info; //reads value of first node
    temp = head; //stores address of first node
    head = head->next; // takes head to the next node
    free(temp); //free memory of the first node
    return val; //return the value of deleted node
}
//delete the node at any position in the list
void del(int pos)
{
    int i;
    NODE *trav, *temp;
    if(head==NULL || pos<=1) //if pos is 1 or before
        delFirst(); // delete the node at the start of the list
    else
    {
        trav = head;
        //init trav to start of the list. transverse to the node before given pos
        for (int i = 0; i < pos-1; i++)
        {
            if(trav==NULL) //if reaches to end of the list
            {
                printf("invald position\n");
                return;
            }
            trav = trav->next;
        }
        temp=trav->next; //temp is the node to be deleted
        trav->next=temp->next; // link trav to the node after temp
        free(temp); //free mem of temp node
    }
}
//delete all the element in the list
void delAll()
{
    NODE *temp;
    while(head!=NULL) //repeats till all the nodes are not deleted
    {
        temp=head; //stores address of the first node
        head=head->next; // take head to next node
        free(temp); // delete the first node
    }
}
