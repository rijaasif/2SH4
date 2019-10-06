#include <stdio.h>

int main() {

    int count = 0;      	//variable to store number of found triples
    int side1, side2, hyp;  //sides of triangle

    /* side1 starts at 1 (since sides cannot be 0),
     * and counts up until it reaches 400 */
    for(side1 = 1; side1 <= 400; side1++) {

        /* side2 >= side1, so side2 will start to count up at value of side1 */
        for(side2 = side1; side2 <= 400; side2++) {

            /* by law of right triangles, hypotenuse > side2 (assuming side2 >= side1),
             * so hyp starts at side2, and counts up
			 * also by law of right triangles: hyp < side1 + side2,
			 * so there is another condition in for() statement to reduce runtime*/
            for(hyp = side2; (hyp < side1 + side2) && (hyp <= 400); hyp++) {

                //condition to check if Pythagorean Theorem is true for given sides and then...
                if(side1*side1 + side2*side2 == hyp*hyp) {
                    printf("side1 = %d\t"
                           "side2 = %d\t"
                           "hyp = %d\n",
                           side1, side2, hyp);      //...print side lengths if true
                    count++;                        //...update counter of found triples by 1
                }
            }
        }
    }

    printf("\n# of Pythagorean Triples = %d\n", count);     //print # of found Pythagorean triples

    return 0;
}