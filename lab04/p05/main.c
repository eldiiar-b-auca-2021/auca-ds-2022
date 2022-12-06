#include <stdio.h>
#include <stdlib.h>
void printArray(int *beg, int *end);
void reverseArray(int *beg, int *end);

int main(void)
{
    // vector<int>
    int *data = NULL;
    size_t sz = 0;
    size_t cp = 0;
    int t;
    while (scanf("%d", &t) == 1)
    {
        if (sz == cp)
        {
            cp = cp == 0 ? 1 : cp * 2;
            int *newData = (int *)malloc(cp * sizeof(int));
            for (int i = 0; i < sz; i++)
            {
                newData[i] = data[i];
            }
            free(data);
            data = newData;
        }
        data[sz++] = t;
    }
    printArray(data, data + sz);
    reverseArray(data, data + sz);
    printArray(data, data + sz);
    free(data);
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
void reverseArray(int *beg, int *end)
{
    for (;;)
    {
        if (beg == end)
        {
            break;
        }
        end--;
        if (beg == end)
        {
            break;
        }
        int temp = *end;
        *end = *beg;
        *beg = temp;
        beg++;
    }
}
