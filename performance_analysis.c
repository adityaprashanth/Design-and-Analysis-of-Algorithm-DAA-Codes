#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void getrand(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 10000;
    }
}

int search(int arr[], int n, int x, int *count)
{
    int i;
    for (i = 0; i < n; i++)
    {
        (*count)++;
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int a[10000], i, res, count;
    double elapse, start, end;
    struct timeval tv;
    FILE *fp1, *fp2;
    fp1 = fopen("seqtime.txt", "w");
    fp2 = fopen("seqcount.txt", "w");
    int key;
    for (i = 500; i <= 10000; i += 500) // size of the array to be created
    {
        getrand(a, i);
        key = a[i - 1];
        count = 0;
        gettimeofday(&tv, NULL);
        start = tv.tv_sec + (double)tv.tv_usec / 1000000; // start time
        res = search(a, i, key, &count);
        gettimeofday(&tv, NULL);
        end = tv.tv_sec + (double)tv.tv_usec / 1000000; // end time
        elapse = (end - start) * 1000;
        fprintf(fp1, "%d\t%lf\n", i, elapse);
        fprintf(fp2, "%d\t%d\n", i, count);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}