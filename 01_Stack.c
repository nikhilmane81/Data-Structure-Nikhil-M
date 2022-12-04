#include<stdio.h>
#define MAX 5
int info[MAX]; //to store the elements
int top; // to maintain top of the stack
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
                printf("Stack is full\n");
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
                printf("Stack is empty \n");
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
    int top = -1; //to initialize top to -1
    for (int i = 0; i < MAX; i++) //or
    {
        info[i] = -1;
    }
    
}
//to check if stack is full
int isFull()
{
    if(top == MAX-1)
        return 1; //full
    else
        return 0; // not full
}
//to check if stack is empty
int isEmpty()
{
    if(top == -1)
        return 1; // stack is empty
    else
        return 0; //stack is not empty
}
// to enter the element in the stack
void push(int data)
{
    top = top + 1; //increment to top
    info[top]= data; //add data to array
}
// to delete the elements in the que
void pop()
{
    info[top]= -1; // optional
    top = top - 1 ; 
}
//to get the top element without deleting 
int peek()
{
    return info[top]; //returns the top most value of the stack
}