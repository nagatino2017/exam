#include<stdio.h>
#define MIN(x, y)  ((x) < (y) ? (x) : (y))
long a[100];
FILE *g;

void Partition(long n, long high, long pos)
{
    long i;
    if (n > 0)
    {
        for (i = 1; i <= high; i++)
        {
            a[pos] = i;
            Partition(n - i, MIN(i, n - i), pos + 1);
        }
    }
    else
    {
        for (i = 0; i < pos; i++)
            fprintf(g, "%ld ", a[i]);
        fprintf(g, "\n");
    }
}

int main()
{
    long n;
    if ((g = fopen("output.txt","wt")) == NULL)
        return 1;
    scanf("%ld", &n);
    Partition(n, n, 0);
    return 0;
}