#include <stdio.h>
#include <stdlib.h>

/* prototype functions */
void string_copy(const char source[], char destination[], int n);
void print_string(const char string[]);

int main() {

    char string1[128];  //source string
    int n = 4;          //size of destination

    printf("enter word: ");     //receive string from user
    gets(string1);
    printf("enter size of destination: ");  //receive size of dest from user
    scanf("%d", &n);
    printf("\n");

    char string2[n+1];      //destination has extra spot for null terminato r

    string_copy(string1, string2, n);   //calls copy_string()
    printf("srce string: ");
    print_string(string1);  //prints string1
    printf("dest string: ");
    print_string(string2);  //prints string2

    return 0;
}

void string_copy(const char source[], char destination[], int n) {
    int i;  //index for loop
    for(i=0; i<n; i++) {    //iterates until end of destination size
        destination[i] = source[i];     //sets source char to destination char
    }
    destination[n] = '\0';  //adds null terminator to final char element
}

void print_string(const char string[]) {
    int i = 0;
    while(string[i] != '\0') {      //loop iterates while the char is not the terminator
        printf("%c", string[i]);    //print each character
        i++;
    }
    printf("\n");
}
