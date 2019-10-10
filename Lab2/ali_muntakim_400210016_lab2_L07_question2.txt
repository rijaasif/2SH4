#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* defines the size of the square matrix*/
#define N 3

/* prototypes for fucntions */
void print_matrix(int matrix[N][N]);
int is_diag_dom(int matrix[N][N]);

int main() {

    int matrix[N][N];   //initializises matrix

    /* sets values of elementa of matrix */
    int i, j;
    for(i=0; i<N; i++) {        //iterates through rows
        for(j=0; j<N; j++) {    //iterates through columns
            if(i==j)
                matrix[i][j] = 2;       //sets diagonal elements
            else
                matrix[i][j] = 1;       //sets non-diagonal elements
        }
    }

    /* prints matrix */
    print_matrix(matrix);

    /* calls is_diag_dom() to check if matrix is diagonally dominant */
    if(is_diag_dom(matrix)) {
        printf("IS diagonally dominant.\n");
    } else {
        printf("NOT diagonally dominant.\n");
    }

    return 0;
}

void print_matrix(int matrix[N][N]){
    int i, j;
    for(i=0; i<N; i++) {        //iterates through rows
        for(j=0; j<N; j++) {    //iterates through columns
            printf("%d\t", matrix[i][j]);   //prints each element
        }
        printf("\n");   //new line if new row
    }
    printf("\n");
}

int is_diag_dom(int matrix[N][N]) {

    int row_sum = 0;    //stores row_sum

    int i, j;
    for(i=0; i<N; i++) {        //iterates through rows
        for(j=0; j<N; j++) {    //iterates through columns
            if(j==i)            //ignores if diagonal element
                continue;
            row_sum += fabs(matrix[i][j]);  //adds absolute value of element to row_sum
        }

        /* if absolute value of diagonal element is less than row_sum, return false */
        if(fabs(matrix[i][i]) <= row_sum)
            return 0;

        row_sum = 0;    //reset row_sum value for next row
    }

    /* if all diagonal elements are greater than respective sum of row, return true */
    return 1;
}
