/*
// random string pattern matching example program with time complexity of all cases
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
int main(){
    // check on massive random string and do patten matching on the string pattern should be like something fixed and not random but pattern should be small
    char str[1000000];
    char *pattern= "abc";
    // now make the string a random text
    // we now start a clock and calculate time taken
    clock_t start,end;
    start = clock();
    for(int i=0;i<1000000;i++){
        str[i] = rand()%26 + 'a';
    }
    int count=0;
    //print string and pattern
    printf("The string is %s\n",str);
    printf("The pattern is %s\n",pattern);
    for(int i=0;i<1000000;i++){
        if(str[i]==pattern[0]){
            if(str[i+1]==pattern[1]){
                if(str[i+2]==pattern[2]){
                    count++;
                }
            }
        }
    }
    printf("The number of times the pattern is found is %d\n",count);
    end = clock();
    double time_taken = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time taken is %f\n",time_taken);
    return 0;
    
}
*/

/*
    Take an input pattern from the user and search for it in a given text file. 
    Return success! if found, else return failure. 
    Also, print the best case, worst case and average case time complexity.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to search for a pattern in a text file
int search(char *pattern, char *text) {
    int patternLength = strlen(pattern);
    int textLength = strlen(text);

    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;

        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == patternLength) {
            return 1;
        }
    }

    return 0;
}

int main() {
    // Open the text file
    FILE *file = fopen("random_text_file.txt", "r");

    // Read the text file
    char text[1000];
    fgets(text, 1000, file);

    // Close the text file
    fclose(file);

    // Take an input pattern from the user
    char pattern[100];
    printf("Enter a pattern: ");
    scanf("%s", pattern);

    // Record the start time
    clock_t start_time = clock();

    // Search for the pattern in the text file
    int found = search(pattern, text);

    // Record the end time
    clock_t end_time = clock();

    // Print the result
    if (found) {
        printf("Success!\n");
    } else {
        printf("Failure!\n");
    }

    // Calculate and print the time complexity
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time Complexity: %f\n", time_taken);

    return 0;
}