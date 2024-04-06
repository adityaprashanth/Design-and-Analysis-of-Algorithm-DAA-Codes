/*
// Program to demonstrate quick sort algorithm with an array 10 numbers and also print
the worst case, average case and best case time complexity seperately
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;time.h&gt;
void swap(int *a, int *b) {
int t = *a;
*a = *b;
*b = t;
}
int partition(int arr[], int low, int high) {
int pivot = arr[high];
int i = (low - 1);
for (int j = low; j &lt;= high - 1; j++) {
if (arr[j] &lt; pivot) {
i++;
swap(&amp;arr[i], &amp;arr[j]);
}
}
swap(&amp;arr[i + 1], &amp;arr[high]);
return (i + 1);
}
void quickSort(int arr[], int low, int high) {
if (low &lt; high) {
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
int main() {
int arr[10] = {30, 60, 20, 40, 10, 80, 90, 70};
int n = sizeof(arr) / sizeof(arr[0]);
clock_t start, end;
start = clock();
quickSort(arr, 0, n - 1);
end = clock();

printf(&quot;Sorted array: \n&quot;);
for (int i = 0; i &lt; n; i++) {
printf(&quot;%d &quot;, arr[i]);
}
printf(&quot;\n&quot;);
// Calculate worst case time complexity
printf(&quot;Worst case time complexity: %f\n&quot;, (double)(end - start) / CLOCKS_PER_SEC);
// Calculate average case time complexity
start = clock();
quickSort(arr, 0, n - 1);
end = clock();
printf(&quot;Average case time complexity: %f\n&quot;, (double)(end - start) / CLOCKS_PER_SEC);
// Calculate best case time complexity
start = clock();
quickSort(arr, 0, n - 1);
end = clock();
printf(&quot;Best case time complexity: %f\n&quot;, (double)(end - start) / CLOCKS_PER_SEC);
return 0;
}
*/

/*
// Program to demonstrate quick sort algorithm with an array 10 numbers and also print the worst case, average case and best case time complexity seperately

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[10] = {30, 60, 20, 40, 10, 80, 90, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t start, end;

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calculate worst case time complexity
    printf("Worst case time complexity: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Calculate average case time complexity
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    printf("Average case time complexity: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Calculate best case time complexity
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    printf("Best case time complexity: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[10] = {30, 60, 20, 40, 10, 80, 90, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t start, end;
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Calculate worst case time complexity
    printf("Worst case time complexity: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    // Calculate average case time complexity
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    printf("Average case time complexity: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    // Calculate best case time complexity
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    printf("Best case time complexity: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}