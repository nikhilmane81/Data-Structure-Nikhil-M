#include<stdio.h>
#include<stdlib.h>
struct point
{
    int x;
    int y;
};
struct point* fun(int a,  int b)
{
    struct point *ptr = (struct point *)malloc(sizeof(struct point)); //using malloc as we need to pointer to retain heap memory else
    //stack memory will be deleted
    ptr->x=a;
    ptr->y=b;
    return ptr;
}
void display(struct point *ptr)
{
    printf("%d %d\n", ptr->x, ptr->y);
}
int main()
{
    struct point *ptr1, *ptr2;
    ptr1 = fun(23,56);
    ptr2 = fun(34,76);
    display(ptr1);
    display(ptr2);
    free(ptr1);
    free(ptr2);
    return 0;
}
