#include <stdio.h>

int main() {
    
	int n = -1;         //n is initialized to negative value (user is expected to enter positive)
    int num, min;       //variables to store number and mininum respectively
	
	do {
        
		printf("How many numbers? ");   //user is prompted for n each iteration
        scanf("%d", &n);        //scans for user input
        
		if(n < 0) {             //prompt if user enters negative n value
            printf("\nENTER A POSITIVE VALUE!\n\n");
        }

    } while(n < 0);             //iterates again if n is negative
    printf("\n");
	
    int i;
    for(i=0; i<n; i++) {            //iterates n times
        
		printf("Enter integer: ");
        scanf("%d", &num);          //user enters new integer for each iteration
        
		if(i == 0) {                //in the first entry...
            min = num;              //...min value is initialized
        }
		if(num < min) {      		//if input is less than set minimum...
            min = num;              //...set new min value
        }
    }

    printf("\nSmallest integer: %d", min);      //prints min value
    return 0;
}
