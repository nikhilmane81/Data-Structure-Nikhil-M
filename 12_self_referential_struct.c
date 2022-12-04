//are those structure which one or more pointers point to
#include<stdio.h>
struct point
{
    int x;
    char c;
    struct point *ptr;
};
int main()
{
    struct point v1;
    struct point v2;
    v1.x = 34;
    v1.c = 'A';
    v1.ptr = NULL;
    v2.x = 22;
    v2.c = 'B';
    v2.ptr = NULL;

    v1.ptr = &v2; //assigning address of v2 variable of the structure to v1 ptr member
    printf("%d %c ", v1.ptr->x, v1.ptr->c); //using v1 member we are accessing values of members of v2 variable
    return 0;
}