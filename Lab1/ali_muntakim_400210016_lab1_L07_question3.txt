#include <stdio.h>

int main() {
    int num;                //variable to store user input

    while(num != 0) {       //continues to iterate until user enters 0
        
		printf("Enter integer (0 to end): ");   //prompts user to enter integer
        scanf("%d", &num);                      //receives user input

        /* if statement checks if number falls within range of all 5 digit numbers */
        if((num >= 10000 && num <= 99999) || (num >= -99999 && num <= -10000)) {
            printf("Integer is five-digits.\n");
        }
        printf("\n");
    }

    printf("Goodbye.\n");   //notify end of program to user

    return 0;
}