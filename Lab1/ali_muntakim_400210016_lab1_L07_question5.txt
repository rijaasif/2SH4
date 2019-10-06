#include <stdio.h>

int main() {

    int n;      //quantity of terms

    do {
        printf("Enter n: ");    //prompts user for n
        scanf("%d", &n);        //accepts n from user

        if(n < 1) {         //condition to print prompt if n < 1
            printf("\ninvalid input: n>=1\n\n");
        }
    } while(n < 1);         //continues to iterate until n >= 1
    printf("\n");

    float approx = 0;           //variable to store the approximation of pi

    int i;
    for(i=0; i<n; i++) {                //adds up to n terms
        if(i%2 == 0) {                      //if it is an even index (odd term)...
            approx += 4/((float)i*2 + 1);   //...add the term to approx
        } else {                            //else (odd index, even term)...
            approx -= 4/((float)i*2 + 1);   //...subtract the term from approx
        }
//        printf("index=%d     term=%d     sum=%f\n", i, i+1, approx);        //print each iteration
    }

    printf("\nPi (n=%d): %f\n", n, approx);     //display the approximation

    return 0;
}
