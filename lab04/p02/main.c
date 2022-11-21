#include <stdio.h>

#define N 10

int main(void)
{
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("the values of array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += a[i];
    }
    printf("Sum of elements: %d\n", sum);
    int sum2 = 0;
    for (int *p = a; p != a + N; p++)
    {
        printf("%p\n", (void *)p);
        sum2 += *p;
    }
    printf("\n");
    printf("%p\n", (void *)a);
    printf("%p\n", (void *)(a + N - 1));
    printf("Sum of elements: %d\n", sum2);
}