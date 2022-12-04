#include<stdio.h>
struct point
{
    int x;
    int y;
};
struct point edit(struct point p) //passing struct variable as argument
{
    (p.x)--;
    p.y=p.y + 10;
    return p; 
}
void display(struct point p)
{
    printf("%d %d \n", p.x, p.y);
}
int main()
{
    struct point p1 = {23,45};
    struct point p2 = {26,55};
    struct point p3;
    struct point p4;
    p3 = edit(p1);
    p4 = edit(p2);
    display(p1);
    display(p3);
    display(p2);
    display(p4);
    return 0;
}
