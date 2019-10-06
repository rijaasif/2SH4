#include <stdio.h>

int main() {

    int m;		//highest number to generate to

    do {
        printf("Enter m: ");    //prompts user to enter m
        scanf("%d", &m);        //accepts m from user
        if(!(m > 1)) {          //prompt user if m is not greater than 1
            printf("invalid input: m>1\n");
        }
    } while(!(m > 1));          //iterates again if m is not greater than 1
    printf("\n");

    int num, fac;		//allocate memory for counters for num and factor
	int sum = 0;		//initialize variable to store sum
	
	/* num starts at 1, and counts up until it reaches m */
    for(num = 1; num <= m; num++) {
        /* fac counts up to find all factors within num but does not include num*/
        for(fac = 1; fac < num; fac++) {
            if(num % fac == 0) {	//if factor divides num...
                sum += fac;			//...add factor to sum
            }
        }

        /* if statement checks if num equals sum
         * by definition of a "perfect number" */
        if(num == sum) {
            printf("%d is a perfect number.\n", num);
        }

        sum = 0;    //resets sum to 0 for next iteration of num
    }

    return 0;
}
