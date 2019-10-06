#include <stdio.h>

/*
    Each number in the input file represents the quantity of repeating digits.
    Therefore, each number represents a different digit.
    So, the program "takes turns" writing zeroes or ones into output after each read of input.
*/

int main() {

    int num;        //stores each number from input file
    int zero = 1;   //pseudo-boolean variable to check if zeroes are to be printed
    int i;          //index for loop

    FILE *input_file = fopen("input_file2.txt", "r");         //opens file for reading
    FILE *output_file = fopen("output_file2.txt", "w");       //opens file for writing

    if (input_file) {   //checks if file is not empty

        /*while condition reads the next number and
        yields TRUE as long as it isn't the end of the file*/
        while(fscanf(input_file, "%d", &num) != EOF) {
            if(zero) {                              //if zero is to be printed...
                for(i = 0; i < num; i++) {
                    fprintf(output_file, "%d ", 0);  //...print zero 'num' times
                }
                zero = 0;                           //...next time print ones
            } else {
                for(i = 0; i < num; i++) {			//if zero is NOT to be printed...
                    fprintf(output_file, "%d ", 1);	//...print one 'num' times
                }
                zero = 1;							//...next time print zeroes
            }
        }

    } else {
        printf("error: EMPTY INPUT FILE");    //prints if input_file2 is empty
    }

    fclose(input_file);     //closes files
    fclose(output_file);

    return 0;
}
