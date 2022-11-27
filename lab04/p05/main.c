#include <stdio.h>
#include <stdlib.h>

void printArray(int *beg, int *end);
void reverseArray(int *beg, int *end);

int main(void)
{
    int *data = NULL;
    size_t sz = 0;
    size_t cp = 0;
    puts("enter arbitrary number of integer values: ");
    int x;
    while ((scanf("%d", &x) == 1))
    {
        if (sz == cp)
        {
            cp = (cp == 0) ? 1 : cp * 2;
            int *newData = (int *)malloc(cp * sizeof(int));
            for (size_t i = 0; i < sz; i++)
            {
                *(newData + i) = *(data + i);
            }
            free(data);
            data = newData;
        }
        data[sz++] = x;
    }
    printArray(data, data + sz);
    reverseArray(data, data + sz);
    printArray(data, data + sz);
}
void reverseArray(int *beg, int *end)
{
    while (true)
    {
        if (beg == end)
            break;
        end--;
        if (beg == end)
            break;
        int temp = *beg;
        *beg = *end;
        *end = temp;
        beg++;
    }
}
void printArray(int *beg, int *end)
{
    for (int *b = beg; b != end; b++)
    {
        printf("%d ", *b);
    }
    printf("\n");
}