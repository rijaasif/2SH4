#include <stdio.h>

int main() {

    int num;                    //variable to store integer
	int rev = 0;         		//variable to store reversed integer
    
	printf("Enter integer: ");  //prompt user to enter num
    scanf("%d", &num);          //accepts num from user
    printf("\n");

    while(num != 0) {               //iterates until num = 0
//        printf("%d\t%d\n", num, rev);    //visualization purposes
        rev *= 10;           		//shift up by one digit, leaving a placeholder 0 in last digit
        rev += num % 10;     		//adds right-most digit of num to last digit in rev
        num /= 10;                  //removes right-most digit in num
    }

    printf("Reversed number: %d\n", rev);		//prints reversed integer

    return 0;
}
