#include<stdio.h>
struct point
{
    int x;
    int y;
};
void display(struct point arr[]);

int main()
{
    struct point arr[2]= {{2,3},{7,8}};
    display(arr);
    return 0;
}
void display(struct point arr[]) //passing array of structure as argument
{
    for (int i = 0; i < 2; i++)
    {
        printf("%d %d \n", arr[i].x,arr[i].y);
    }
    
}