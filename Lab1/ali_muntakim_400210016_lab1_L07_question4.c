#include <stdio.h>
#include <stdlib.h>

int main() {

    float avg;      //variable to store user input (student average)
    int mark;       //variable to store student mark

    printf("Enter student average: ");                  //prompt user to enter student average
    if(scanf("%f", &avg) != 1) {                        //to ensure no char input
        printf("\ninvalid input: NOT A NUMBER\n");
        return EXIT_FAILURE;                            //stop program with exit code 1
    } else if(avg >= 90 && avg <= 100) {        //checks interval of avg...
        mark = 4;                               //...and assigns respective mark
    } else if(avg >= 80 && avg < 90) {
        mark = 3;
    } else if(avg >= 70 && avg < 80) {
        mark = 2;
    } else if(avg >= 60 && avg < 70) {
        mark = 1;
    } else if(avg >= 0 && avg < 60) {
        mark = 0;
    } else {
        printf("\ninvalid input: OUT OF RANGE\n");      //if avg is out of range
        return EXIT_FAILURE;
    }

    printf("\nStudent mark: %d\n", mark);   //prints out student mark
	
    return EXIT_SUCCESS;                    //stops program with exit code 0
}