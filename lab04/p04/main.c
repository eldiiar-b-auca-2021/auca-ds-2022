#include <stdio.h>
#include <stdlib.h>
void reverse(int *beg, int *end);
void printArray(int *beg, int *end);
int main(void)
{
    int n;
    scanf("%d", &n);

    int *dynamicArray = (int *)malloc(n * sizeof(int));
    printf("%p", dynamicArray);
    printf("\n");
    if (dynamicArray == NULL)
    {
        printf("Not enough memory");
        exit(1);
    }
    for (int *b = dynamicArray; b != dynamicArray + n; b++)
    {
        printf("%p ", b);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", dynamicArray + i);
    }
    reverse(dynamicArray, dynamicArray + n);
    printArray(dynamicArray, dynamicArray + n);
    free(dynamicArray);
}
void reverse(int *beg, int *end)
{
    while (true)
    {
        if (beg == end)
            break;

        end--;
        if (beg == end)
            break;

        int t = *beg;
        *beg = *end;
        *end = t;
        beg++;
    }
}
void printArray(int *beg, int *end)
{
    while (beg != end)
    {
        printf("%d ", *beg);
        beg++;
    }
    printf("\n");
}