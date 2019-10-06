#include <stdio.h>
#include <stdlib.h>

/* defines the size of square matrix */
#define N 10

/* prototype declaration */
void print_diag_order(int matrix[N][N]);

int main() {

    int matrix[N][N];   //decleration of N by N square matrix

    /* sets values for the matrix elements */
    int i, j, k = 1;    //k is a counter for elements
    for(i=0; i<N; i++) {        //iterates through rows
        for(j=0; j<N; j++) {    //iterates through columns
            matrix[i][j] = k++;     //sets matrix value, counter goes up
            printf("%d\t", matrix[i][j]);   //prints element
        }
        printf("\n");   //new line when new row
    }
    printf("\n");

    /* prints elements in a diagonal fasshion */
    print_diag_order(matrix);

    return 0;
}

void print_diag_order(int matrix[N][N]) {

    /* i and j are indices for matrix row and column respectively
    k is an 'index' for diagonal */
    int i, j, k;

    /* first part to iterate through top diagonal half */
    for(k = 0; k < N; k++) {
        i = k;  //row starts at k
        j = 0;  //column starts at left-most

        /* iterate through the diagonal until top row is reached */
        while(i >= 0) {
            printf("%d ", matrix[i][j]);
            i--;    //i goes down by one, moving up one row
            j++;    //j goes up by one, moving right one col
        }
    }

    /* this is the same as the above block,
    but k starts at bottom row elements*/
    for(k = 1; k < N; k++) {
        i = N-1;    //row starts at last row
        j = k;      //column starts at k

        /* iterate through diagonal until last column is reached */
        while(j < N) {
            printf("%d ", matrix[i][j]);
            i--;
            j++;
        }
    }

    printf("\n");
}
