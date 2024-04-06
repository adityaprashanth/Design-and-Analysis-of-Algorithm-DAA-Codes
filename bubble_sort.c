/*
#include <stdio.h>

void main(){
    int n = 0;
    int temp = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter the element: ");
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(long int[], long int);

int main() 
{
    long int *array, n, c;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of elements: ");
    scanf("%ld", &n);

    // Dynamically allocate memory for the array
    array = (long int *)malloc(n * sizeof(long int));
z
    // Check if memory allocation is successful
    if (array == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %ld integers:\n", n);
    for (c = 0; c < n; c++) 
    {
        array[c] = rand() % 1000; // random value generation
        printf("%ld\n", array[c]);
    }

    start = clock();
    bubble_sort(array, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime complexity is O(n^2)\n");
    printf("Sorted list in ascending order:\n");
    for (c = 0; c < n; c++) 
    {
        printf("%ld\n", array[c]);
    }
    //print elapsed time
    printf("Elapsed time: %f\n", cpu_time_used);
    // Free the allocated memory
    free(array);

    return 0;
}

void bubble_sort(long int list[], long int n) 
{
    long int c, d, t;
    for (c = 0; c < (n - 1); c++) 
    {
        for (d = 0; d < n - c - 1; d++) 
        {
            if (list[d] > list[d + 1]) 
            {
                t = list[d];
                list[d] = list[d + 1];
                list[d + 1] = t;
            }
        }
    }
}
