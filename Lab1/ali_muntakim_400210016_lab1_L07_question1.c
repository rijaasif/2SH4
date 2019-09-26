#include <stdio.h>

/* prototypes declared before main() */
void forLoop();
void whileLoop();
void doWhileLoop();

int main() {
    
	forLoop();          //calls for loop
    whileLoop();        //calls while loop
    doWhileLoop();      //calls do-while loop
    
	return 0;
}

void forLoop() {
    
	int sum = 0;	//variable to store sum
    
	int i;
    for(i=30; i<=1000; i++) {       //iterates from range 30 to 1000
        if(i%4 == 0) {                  //if i is divisible by 4...
            sum += i;                   //...add i to sum
        }
    }
    
	printf("for loop: %d\n", sum);      //prints the sum
}

void whileLoop() {
    
	int sum = 0, i = 30;                //index (i) starts at 30
    
	while(i <= 1000) {                  //iterates until i is equal or less than 1000
        if(i%4 == 0) {
            sum += i;
        }
        i++;                            //i counts up by 1
    }
    
	printf("while loop: %d\n", sum);
}

void doWhileLoop() {
    
	int sum = 0, i = 30;                //i starts at 30
    
	do {
        if(i%4 == 0) {
            sum += i;
        }
        i++;
    } while(i <= 1000);                 //loop terminates once i exceeds 1000
    
	printf("do while loop: %d\n", sum);
}