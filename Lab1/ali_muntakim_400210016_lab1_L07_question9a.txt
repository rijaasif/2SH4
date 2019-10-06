#include <stdio.h>

/*
    This program works by counting how many
    consecutive repeating integers there are,
    and if there is break in repetition,
    it prints the number of repeating integers
    and restarts the counter.
*/

int main() {

    int num;            //stores each number read by fscanf()
    int prior = 0;      //variable to store previous number, to ensure repetition
    int consec = 0;     //counter to store # of conesecutive repeating integers

    FILE *input_file = fopen("input_file1.txt", "r");        //opens file for reading
    FILE *output_file = fopen("output_file1.txt", "w");      //opens file for writing

    if (input_file) {   //if file is not empty

        /*while condition reads the next number and
        iterates as long as it isn't the end of the file*/
        while(fscanf(input_file, "%d", &num) != EOF) {
            if(num != prior) {              //if there is a break in repetition...
                fprintf(output_file, "%d ", consec);    //...print the # of consecutive repetitions
                consec = 0;                 //...reset the counter
                prior = num;                //set the new number to track repetition
            }
            consec++;       //counter goes up
        }

        /*prints the # of consecutive reptitions of the last repetition
        because there isn't a break in repetition (as it is the end of the file)*/
        fprintf(output_file, "%d ", consec);

    } else {
        printf("error: EMPTY INPUT FILE");    //prints if input_file1 is empty
    }

    fclose(input_file);     //closes files
    fclose(output_file);

    return 0;
}
