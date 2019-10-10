#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* prototype functions*/
void print_vector(double vector[], int n);
void add_vectors(double vector1[], double vector2[], double vector3[], int n);
double scalar_prod(double vector1[], double vector2[], int n);
double norm2(double vector[], int n);

int main() {
    //declaring size and vectors
    int n = 5;
    double vector1[] = {3, 0, 4, 5, -1};
    double vector2[] = {6, 1, -1, 8, 2};
    double vector3[] = {0, 0, 0, 0, 0};

    //printing each vector
    printf("printing all vectors:\n");
    printf("v1: ");
    print_vector(vector1, n);
    printf("v2: ");
    print_vector(vector2, n);
    printf("v3: ");
    print_vector(vector3, n);
    printf("\n");

    //adding vector1 and vector2 to vector3, then printing all
    add_vectors(vector1, vector2, vector3, n);

    printf("after adding, vector3 = vector1 + vector2\n");
    printf("v1: ");
    print_vector(vector1, n);
    printf("v2: ");
    print_vector(vector2, n);
    printf("v3: ");
    print_vector(vector3, n);
    printf("\n");

    //prints scalar product of vector1 and vector2
    printf("scalar product of vector1 and vector2\n%0.5lf\n",
           scalar_prod(vector1, vector2, n));
    printf("\n");

    //prints L2 norm of vector3
    printf("L2 norm of vector3\n%0.5lf\n",
           norm2(vector3, n));

    return 0;
}

void print_vector(double vector[], int n) {
    int i;
    for(i = 0; i < n; i++) {            //iterates through entire vector
        printf("%0.2lf ", vector[i]);   //prints each component
    }
    printf("\n");
}

void add_vectors(double vector1[], double vector2[], double vector3[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        //stores sum of i'th components from vector1 and vector2 to vector3
        vector3[i] = vector1[i] + vector2[i];
    }
}

double scalar_prod(double vector1[], double vector2[], int n) {
    int i;
    double prod = 0; //variable to store scalar product
    for(i = 0; i < n; i++) {
        prod += vector1[i] * vector2[i]; //adds product of i'th components to 'prod' variable
    }
    return prod;
}

double norm2(double vector[], int n) {
    double norm;
    norm = scalar_prod(vector, vector, n);  //essentially gets sum of squares of each component
    norm = sqrt(norm);                      //square roots the sum of squares
    return norm;
}










