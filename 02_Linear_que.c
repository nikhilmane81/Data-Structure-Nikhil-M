#include<stdio.h>
#define MAX 5
int info[MAX]; //to store the elements
int front; //to maintain front end of the que
int rear; // to maintain rear end of the que
void init();
int isFull();
int isEmpty();
void push(int);
void pop();
int peek();
int main()
{
    int choice, value;
    init();
    do
    {
        printf("Press 0 to exit \n Press 1 for push \n press 2 for pop ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if(isFull())
                printf("que is full\n");
            else
            {
                printf("Enter the value to push ");
                scanf("%d", &value);
                push(value);
                printf("Value pushed is : %d \n", value);
            }
            break;
        case 2:
            if(isEmpty())
                printf("que is empty \n");
            else
            {
                value = peek();
                pop();
                printf("value poped : %d \n", value);
            }
            break;
        default:
            break;
        }
    } while (choice=!0);
    
return 0;
}
void init()
{
    int i;
    rear = -1; // rear end to -1 
    front = -1; // front end to -1
    for (int i = 0; i < MAX; i++) // or you can make entire array to -1
    {
        info[i]= -1;
    }
    
    
}
//to check if que is full
int isFull()
{
    if(rear == MAX-1)
        return 1; //full
    else
        return 0; // not full
}
//to check if que is empty
int isEmpty()
{
    if(rear == front)
        return 1; // que is empty
    else
        return 0; //que is not empty
}
// to enter the element in the que
void push(int data)
{
    rear = rear + 1; //increment to top
    info[rear]= data; //add data to array
}
// to delete the elements in the que
void pop()
{
    info[front]= -1;
    front = front + 1 ;
}
//to get the top element without deleting 
int peek()
{
    return info[front+1]; //returns the front end value of the que
}