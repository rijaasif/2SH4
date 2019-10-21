#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

char **read_words(const char *filename, int *nPtr);
void print_words(char **words, int size);
void sort_list(char **words, int size);
void free_words(char **words, int *size);

int main() {
    int n = 0;

    char **words = read_words("input_file.txt", &n);

//    printf("BEFORE SORTING:\n");
//    print_words(words, n);

    sort_list(words, n);
//    printf("AFTER SORTING:\n");
//    print_words(words, n);

    free_words(words, &n);

    return 0;
}

char **read_words(const char *filename, int *nPtr) {
    FILE *filePtr = fopen(filename, "r");
    char **words;
    char word[MAX_LEN];
    int total_char = 0;

    if(filePtr == NULL) {
        printf("ERROR: the file '%s' does not exist", filename);
        exit(1);
    }

    while(fscanf(filePtr, "%s", word) != EOF) {
        total_char += strlen(word);
        (*nPtr)++;
    }
    rewind(filePtr);

    words = malloc(*nPtr * sizeof(char*));

    int i;
    for(i = 0; i < *nPtr; i++) {
        fscanf(filePtr, "%s", word);
        words[i] = malloc(strlen(word) * sizeof(char));
        strcpy(words[i], word);
    }

    fclose(filePtr);

    return words;
}

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
    int i, j, k;
    for(i = 1; i < size-1; i++) {
        for(j = i+1; j > 0 && words[j-1][letter] > words[j][letter]; j--) {
            /* swap words[j] and words[j-1] */
            temp = malloc((strlen(words[j-1])) * sizeof(char));
            strcpy(temp, words[j-1]);

            words[j-1] = realloc(words[j-1], sizeof(words[j]));
            strcpy(words[j-1], words[j]);

            words[j] = realloc(words[j], sizeof(temp));
            strcpy(words[j], temp);

            free(temp);

            printf("i=%d j=%d\n", i, j);
            print_words(words, size);
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
