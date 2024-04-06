#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

void merge(int* a, int* b, int* c, int m, int n)
{
    for(int i=0; i<m; i++)
    {
        c[i] = a[i];
    }
    for(int i=0; i<n; i++)
    {
        c[m+i] = b[i];
    }
}

void mergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, a, a, mid+1-low+1, high-mid);
    }
}

int main()
{
    int m = 5;
    int a[5] = {10, 20, 30, 40, 50};
    int n = 4;
    int b[4] = {15, 25, 35, 45};
    int c[8];
    merge(a, b, c, m, n);
    for(int i = 0; i < (m+n); i++)
    {
        printf("%d ",c[i]);
    }
}
*/