#include<stdio.h>
struct charset
{
    char s;
    int i;
};
void setvalue(char* s, int* i) //passing address of variables of struct
{
    printf("Enter char and int now > ");
    scanf("%c %d", s,i);
}
int main()
{
    struct charset cs;
    setvalue(&cs.s, &cs.i);
    printf("%c %d", cs.s, cs.i);
    return 0;
}
