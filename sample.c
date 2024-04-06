#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

    int n;

    printf("enter the size ");
    scanf("%d", &n);
    printf("\n");
    char c[n]; 

    printf("enter array elements\n");

    for(int i = 0; i < n ; i++)
    {
        scanf(" %c", &c[i]);
    }

    int l = 0;
    int r = n - 1;

    while(l <= r)
    {
        if(!(c[l] >= 'a' && c[l] <= 'z') && !(c[l] >= 'A' && c[l] <= 'Z'))
        {

            l++;
        }
        else if(!(c[r] >= 'a' && c[r] <= 'z') && !(c[r] >= 'A' && c[r] <= 'Z'))
        {
            r--;
        }
        else 
        {
            char temp = c[l];
            c[l] = c[r];
            c[r] = temp;
            l++;
            r--;
            
        }
    }

    printf("answer : \n");

    for(int i = 0; i < n; i++)
    {
        printf("%c ", c[i]); 
    }
    printf("\n");

    return 0;
}
