#include <stdio.h>

// Function to find the survivor
int josephus(int n, int k) {
    if (n == 1)
        return 0;
    else
        return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the killing interval: ");
    scanf("%d", &k); //  killing interval must always be 2 
    int survivor = josephus(n, k) + 1; // Adding 1 to convert from 0-based indexing to 1-based indexing
    printf("The survivor is person %d\n", survivor);
    return 0;
}
