#include <stdio.h>
#include <stdlib.h>

/* prototype function */
void letter_freq(const char word[], int freq[]);

int main() {

    /* freq stores frequency of each occurring letter of the alphabet */
    int i, freq[26];
    for(i=0; i<26; i++)
        freq[i] = 0;

    //char word[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char word[] = "pomegranate";

    letter_freq(word, freq);    //calls function

    return 0;
}

/* letters a-z in ASCII is 97-122 */
/* letters A-Z in ASCII is 65-90 */
void letter_freq(const char word[], int freq[]) {

    int i = 0;      //index for loops

    /* iterates through character array until it reaches terminator */
    while(word[i] != '\0') {
        if(word[i] >= 97 && word[i] <= 122) {   //ensures char is within ascii range
            freq[(word[i]%97)]++;               //modulo operation gives index, and freq counter goes up
        }
        if(word[i] >= 65 && word[i] <= 90) {
            freq[(word[i]%65)]++;
        }
        i++;    //iterator for word index goes up by one
    }
    printf("\n");

    /* prints frequency of each letter in the word */
    for(i=0; i<26; i++) {
        if(freq[i] == 0)    //ignore letters that don't occur
            continue;
        printf("The count of '%c' and '%c' is: %d\n", 65+i, 97+i, freq[i]);
    }
}
