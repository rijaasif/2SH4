#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

char **read_words(const char *filename, int *nPtr);
void print_words(char **words, int size);
void swap_words(char *word1, char *word2);
void insertion_sort_list(char **words, int size);
void bubble_sort_list(char **words, int size);
void free_words(char **words, int *size);

void instructions() {
    printf("Enter 'prompt' command numbers:\n");
    printf("0. exit program\n");
    printf("1. create word list\n");
    printf("2. print words\n");
    printf("3. insertion sort\n");
    printf("4. bubble sort\n");
    printf("5. destroy list\n\n");
}

int main() {
    int n = 0;      //size of word list
    char **words;   //pointer to pointers/arrays

    instructions(); // print instructions for user

    /* infinite loop to keep asking user for prompts */
    int prompt;
    while(1) {
        printf("Enter prompt: ");
        scanf("%d", &prompt);
        switch(prompt) {
            case 0:     // allows user to exit the program
                printf("\nExiting program...\n");
                return 0;
                break;
            case 1:
                printf("Creating word list...");
                words = read_words("input_file.txt", &n);
                printf("done.\n");
                break;
            case 2:
                printf("\n");
                print_words(words, n);
                break;
            case 3:
                printf("Sorting list using INSERTION...");
                insertion_sort_list(words, n);
                printf("done.\n");
                break;
            case 4:
                printf("Sorting list using BUBBLE...");
                bubble_sort_list(words, n);
                printf("done.\n");
                break;
            case 5:
                printf("Destroying list in memory...");
                free_words(words, &n);
                printf("done.\n");
                break;
            default:
                printf("\n");
                instructions(); // print instructions if user enters wrong prompt
                break;
        }
        printf("\n");
    }
    return 0;
}

char **read_words(const char *filename, int *nPtr) {
    FILE *filePtr = fopen(filename, "r");   // open file to read
    char **words;           // point to pointers, essentially array of string
    char word[MAX_LEN];     // temporary variable to store each word

    /* exit program if file is not found */
    if(filePtr == NULL) {
        printf("\nERROR: The file '%s' does not exist.\n", filename);
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
        words[i] = malloc((strlen(word)+1) * sizeof(char));     // add +1 for '\n' terminator
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
}

/* uses insertion sort method to sort the list */
void insertion_sort_list(char **words, int size) {
    char *temp;
    int letter = 0;
    int i, j;
    for(i = 0; i < size-1; i++) {
        /* ascending order */
        for(j = i+1; j > 0 && words[j-1][letter] > words[j][letter]; j--) {
            // swap words
            temp = words[j-1];
            words[j-1] = words[j];
            words[j] = temp;

        }
    }
}

/* useres bubble sort method to sort the list */
void bubble_sort_list(char **words, int size) {
    char *temp;
    int letter = 0;
    int i, j;
    for(i = 0; i < size-1; i++) {
        /* elements at the end of list are already sorted */
        for(j = 0; j < size-i-1; j++) {
            /* ascending order */
            if(words[j][letter] > words[j+1][letter]) {
                // swap words
                temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }
}

/* frees each element in the pointer array and resets all variables */
void free_words(char **words, int *size) {
    int i;
    for(i = 0; i < *size; i++) {
        free(words[i]);
    }
    *words = NULL;
    *size = 0;
}
