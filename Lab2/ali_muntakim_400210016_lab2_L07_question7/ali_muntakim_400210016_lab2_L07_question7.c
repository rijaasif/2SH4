#include <stdio.h>
#include <stdlib.h>

/* prototype functions */
void print_vector(int vector[], int size);
void addEff(int val1[], int val2[], int val3[],
            int pos1[], int pos2[], int pos3[],
            int k1, k2);

int main() {

    int val1[] = {1, 3, 5, 7}, pos1[] = {1, 2, 4, 7};
    int k1 = sizeof(val1) / sizeof(val2[0]);
    int val2[] = {2, 4, 6}, pos2[] = {2, 4, 6};
    int k2 = sizeof(val2) / sizeof(val2[0]);



    return 0;
}

/* iterates through array and prints each element on line */
void print_vector(int vector[], int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void addEff(int val1[], int val2[], int val3[],
            int pos1[], int pos2[], int pos3[],
            int k1, k2) {

    int i, max = 0;
    for(i=0; i<k1; i++) if(max < pos1[i]) max = pos1[i];
    for(i=0; i<k2; i++) if(max < pos2[i]) max = pos2[i];


}
