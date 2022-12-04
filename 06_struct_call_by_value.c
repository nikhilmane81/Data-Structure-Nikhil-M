#include<stdio.h>
struct cvalue
{
    int x;
    int y;
};
void print(struct cvalue p) //passing value of structure variable, basically makes copy of called variable
{
    printf("%d %d\n",p.x,p.y);
}
int main()
{
    struct cvalue p1 ={23,56};
    struct cvalue p2={45,78};
    print(p1);
    print(p2);
    return 0;
}