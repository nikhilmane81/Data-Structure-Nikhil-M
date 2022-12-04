#include<stdio.h>
struct pointerarg
{
    int x;
    int y;
    int z;
};
void print(struct pointerarg *ptr) //passing pointer which can store address of struct variable
{
    printf("%d %d %d \n", ptr->x, ptr->y, ptr->z);
}
int main()
{
    struct pointerarg p1 = {23,45,56};
    struct pointerarg p2 = {25,55,56};
    print(&p1);
    print(&p2);
    return 0;
}
