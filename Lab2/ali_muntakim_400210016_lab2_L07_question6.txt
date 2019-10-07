#include <stdio.h>
#include <stdlib.h>

/* prototype functions */
void efficient(const int source[], int val[], int pos[], int size);
void reconstruct(int source[], int m, const int val[], const int pos[], int n);
int non_zero_count(int vector[], int size);
void print_vector(int vector[], int size);

int main() {

    int vector1[] = {0, 0, 23, 0, -7, 0, 0, 48, 0, 0};  //initializes vector
    int size1 = sizeof(vector1) / sizeof(vector1[0]);   //gets size of vector
    int k1 = non_zero_count(vector1, size1);    //stores # of non-zero elements in vector
    int val1[k1], pos1[k1];     //arrays to store non-zero elements and positions

    /* puts non-zero values into val_1 and pos_1 */
    efficient(vector1, val1, pos1, size1);

    /* prints values of non-zero elements and respective positions */
    printf("val: ");
    print_vector(val1, k1);
    printf("pos: ");
    print_vector(pos1, k1);

    int val2[] = {23, -7, 48}, pos2[] = {2, 4, 7}; //initializes 'efficient' vectors
    int k2 = sizeof(val2) / sizeof(val2[0]); //gets size or # of non-zero elements
    int size2 = 10;        //the size of the to-be reconstructed vector
    int vector2[size2];    //initialization of to-be reconstructed vector

    /* reconsctructs the sparse vector */
    reconstruct(vector2, size2, val2, pos2, k2);

    /* prints the reconstructed vector */
    printf("reconstructed vector: ");
    print_vector(vector2, size2);

    return 0;
}

/* takes a sparse vector and stores it in an 'efficient' representation */
void efficient(const int source[], int val[], int pos[], int size) {
    int i;      //index for source[] vector
    int j = 0;  //index for val[] and pos[] vectors
    for(i=0; i<size; i++) {     //iterates through source vector
        if(source[i] != 0) {    //if element in source is not zero...
            val[j] = source[i]; //...store value of element
            pos[j] = i;         //...store position of element
            j++;                //...index for val/pos goes up by one
        }
    }
}

/* reconstructs a sparse vector from its 'efficient' representation */
void reconstruct(int source[], int m, const int val[], const int pos[], int n) {
    int i;      //index for source[] vector
    int j=0;    //index for val[] and pos[] vectors
    for(i=0; i<m; i++) {        //iterates through source vector
        if(i == pos[j]) {       //if index matches position of non-zero element...
            source[i] = val[j]; //...set value to source
            j++;                //...count up by one
        } else {
            source[i] = 0;      //else set vector element to zero
        }
    }
}

/* returns the count of all non=zero elements in the vector */
int non_zero_count(int vector[], int size) {
    int i, count = 0;
    for(i=0; i<size; i++) {
        if(vector[i] != 0)  //if element is not zero...
            count++;        //...counter goes up
    }
    return count;
}

/* iterates through array and prints each element on line */
void print_vector(int vector[], int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}
