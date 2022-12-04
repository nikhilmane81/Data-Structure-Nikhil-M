#include<iostream>
using namespace std;
struct cvalue
{
    int x;
    int y;
};
void print(struct cvalue p)
{
    cout<<"The values are "<<p.x<<" "<<p.y<<endl;
}
int main()
{
    struct cvalue p1={23,45};
    struct cvalue p2={44,55};
    print(p1);
    print(p2);
    return 0;
}
