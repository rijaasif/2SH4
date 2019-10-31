#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototype function
char *my_strcat(const char *const str1, const char *const str2);

int main() {
    char str1[128], str2[128];    // char arrays (or 'strings') to concatenate

    // get user input for string variables
    printf("Enter String 1: ");
    gets(str1);
    printf("Enter String 2: ");
    gets(str2);
    printf("\n");

    char *str = my_strcat(str1, str2);  // pointer to hold returned concat
    printf("Concatenation: %s\n", str);    // print the concatenation
    free(str);  // free the allocated memory

    return 0;
}

char *my_strcat(const char *const str1, const char *const str2) {

    // points to allocated memory for concatenated string
    // is the size of str1 and str2 and plus one for null terminator
    char *str3 = malloc(strlen(str1) + strlen(str2) + 1);

    int i = 0, j = 0;           // indices for str1 and str2 respectively
    while(str1[i] != '\0') {    // iterates until end of str1
        str3[i] = str1[i];      // sets str3 equal to str1
        i++;                    // index counts up
    }
    while(str2[j] != '\0') {    // iterates until end of str2
        str3[i] = str2[j];      // str2 is set to str3 after str1's prior index
        i++;                    // indices count up
        j++;
    }

    str3[i] = '\0';     // add null terminator to final concatenation

    return str3;
}
