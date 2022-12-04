#include<stdio.h>
#include<stdlib.h>
int *input()
{
    int *ptr, i;
    ptr = (int*)malloc(5*sizeof(int)); //allocating 5 block of int memory, typecasted to int
    printf("Enter 5 numbers ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", ptr + i);
    }
    return ptr;   
}
int main()
{
    int sum=0;
    int *ptr = input();
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(ptr+i));
        sum += *(ptr+i);
    }
    printf("Sum is %d ", sum);
    free(ptr); // releasing the memory
    return 0;
}