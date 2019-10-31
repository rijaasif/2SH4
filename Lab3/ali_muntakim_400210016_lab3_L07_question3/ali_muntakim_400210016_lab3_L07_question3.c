#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

char **read_words(const char *filename, int *nPtr);
void print_words(char **words, int size);
void swap_words(char *word1, char *word2);
void sort_list(char **words, int size);
void free_words(char **words, int *size);

int main() {
    int n = 0;

    char **words = read_words("input_file.txt", &n);

    printf("BEFORE SORTING:\n");
    print_words(words, n);

    sort_list(words, n);

    printf("AFTER SORTING:\n");
    print_words(words, n);

    free_words(words, &n);

    return 0;
}

char **read_words(const char *filename, int *nPtr) {
    FILE *filePtr = fopen(filename, "r");   // open file to read
    char **words;           // point to pointers, essentially array of string
    char word[MAX_LEN];     // temporary variable to store each word

    /* exit program if file is not found */
    if(filePtr == NULL) {
        printf("ERROR: the file '%s' does not exist", filename);
        exit(1);
    }

    /* gets # of words from first line */
    fscanf(filePtr, "%d", nPtr);

    /* allocates space for pointer to pointers */
    words = malloc(*nPtr * sizeof(char*));

    /* iterates through entire word list and allocates word length to char array */
    int i;
    for(i = 0; i < *nPtr; i++) {
        fscanf(filePtr, "%s", word);
        words[i] = malloc((strlen(word)+1) * sizeof(char));
        strcpy(words[i], word);
    }

    fclose(filePtr);    // close file

    return words;
}

/* function to iterate through entire word list and print */
void print_words(char **words, int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("%s\n", words[i]);
    }
    printf("\n");
}

void sort_list(char **words, int size) {
    char *temp;
    int letter = 0;
    int i, j;
    for(i = 0; i < size-1; i++) {
        for(j = i+1; j > 0 && words[j-1][letter] > words[j][letter]; j--) {
            //swap words
            temp = words[j-1];
            words[j-1] = words[j];
            words[j] = temp;
        }
    }
}

void free_words(char **words, int *size) {
    int i;
    for(i = 0; i < *size; i++) {
        free(words[i]);
    }
    *words = NULL;
    *size = 0;
}
