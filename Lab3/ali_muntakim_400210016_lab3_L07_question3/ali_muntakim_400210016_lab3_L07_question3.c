#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 256

/* allowed to use strlen() and strcpy() */

char **read_words(const char *filename, int *nPtr);
void print_words(char **words, int size);
void sort_list(char **words, int size);

int main() {
    int n = 0;

    char **words = read_words("input_file.txt", &n);

    printf("BEFORE SORTING:\n");
    print_words(words, n);

//    sort_list(words, n);
//    printf("AFTER SORTING:\n");
//    print_words(words, n);

    return 0;
}

char **read_words(const char *filename, int *nPtr) {
    FILE *filePtr = fopen(filename, "r");   //opens file to read
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

    words = malloc(total_char * sizeof(char));

    int i;
    for(i = 0; i < *nPtr; i++) {
        fscanf(filePtr, "%s", word);
        words[i] = malloc(strlen(word) * sizeof(char));
    }
    rewind(filePtr);

    for(i = 0; i < *nPtr; i++) {
        fscanf(filePtr, "%s", words[i]);
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

//void sort_list(char **words, int size) {
//    char *temp;
//    int i, j;
//    for(i = 0; i < size-1; i++) {
//        j = i;
//        for(j = i; j > 0 && words[j-1][0] > words[j][0]; j--) {
//            /* swap words[j] and words[j-1] */
//            temp = (char*) malloc((strlen(words[j-1]))*sizeof(char));
//            strcpy(temp, words[j-1]);
//            strcpy(words[j-1], words[j]);
//            strcpy(words[j], temp);
//        }
//    }
//}
