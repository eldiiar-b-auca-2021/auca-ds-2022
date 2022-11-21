#include <stdio.h>

#define N 10
#define M 10
int a[N];
void readArray(int *p, int size);
void printArray(int *begin, int *end);
int main(void)
{
    int b[M];
    readArray(a, N);
    readArray(b, M);
    printArray(a, N + a);
    printArray(b, b + M);
}
void readArray(int *p, int size)
{
    // for (int i = 0; i < size; i++)
    // {
    //     scanf("%d", &p[i]);
    // }
    while (size--)
    {
        scanf("%d", p++);
    }
}
void printArray(int *begin, int *end)
{
    for (; begin != end; begin++)
    {
        printf("%d ", *begin);
    }
    printf("\n");
}