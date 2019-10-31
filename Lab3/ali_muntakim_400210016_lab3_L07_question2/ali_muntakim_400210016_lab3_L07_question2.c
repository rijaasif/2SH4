#include <stdio.h>
#include <stdlib.h>

/* defining typedef "student" structure */
typedef struct{
    int studentID;
    char firstName[15];
    char lastName[15];
    int proj1Grade;
    int proj2Grade;
    float finalGrade;
} student;

/* prototype functions */
student **create_class_list(char *filename, int *sizePtr);
int find(int idNo, student **list, int size);
void input_grades(char *filename, student **list, int size);
void compute_final_course_grades(student **list, int size);
void output_final_course_grades(char *filename, student **list, int size);
void print_list(student **list, int size);
void withdraw(int idNo, student **list, int *sizePtr);
void destroy_list(student **list, int *sizePtr);

/* instruction set for the program */
void instructions() {
    printf("Enter 'prompt' command numbers:\n");
    printf("0. exit program\n");
    printf("1. create_class_list\n");
    printf("2. find\n");
    printf("3. input_grades\n");
    printf("4. compute_final_course_grades\n");
    printf("5. output_final_course_grades\n");
    printf("6. print_list\n");
    printf("7. withdraw\n");
    printf("8. destroy_list\n\n");
}

int main() {
    int size;           // class size or # of students
    student **list;     // pointer to the beginning of array of pointers of each student

    instructions();

    /* infinite loop that asks for user prompt*/
    int prompt;
    while(1) {
        printf("Enter prompt: ");
        scanf("%d", &prompt);
        switch(prompt) {
            case 0: // prompt to exit the program
                printf("\nExiting program...\n");
                return 0;
            case 1:
                printf("Creating class list...");
                list = create_class_list("class_list.txt", &size);
                printf("done.\n");
                break;
            case 2:
                printf("Enter index for find function: ");
                scanf("%d", &prompt);
                printf("Index of %d is %d\n", prompt, find(prompt, list, size));
                break;
            case 3:
                printf("Inputting grades...");
                input_grades("project_grades.txt", list, size);
                printf("done.\n");
                break;
            case 4:
                printf("Computing final grades...");
                compute_final_course_grades(list, size);
                printf("done.\n");
                break;
            case 5:
                printf("Outputting final course grades...");
                output_final_course_grades("final_grades.txt", list, size);
                printf("done.\n");
                break;
            case 6:
                print_list(list, size);
                break;
            case 7:
                printf("Enter index to withdraw: ");
                scanf("%d", &prompt);
                withdraw(prompt, list, &size);
                printf("Done.\n");
                break;
            case 8:
                printf("Destroying list...");
                destroy_list(list, &size);
                printf("done.\n");
                break;
            default:
                printf("\n");
                instructions(); //print instructions if user enters wrong prompt
                break;
        }
        printf("\n");
    }
}

/* function reads the input file and puts elements into an array of structures */
student **create_class_list(char *filename, int *sizePtr) {
    FILE *filePtr = fopen(filename, "r");   // file pointer to filename

    /* exit code for if file does not exist */
    if(filePtr == NULL) {
        printf("ERROR: the file '%s' does not exist\n", filename);
        exit(1);
    }

    fscanf(filePtr, "%d", sizePtr);         // gets # of students from first line

    /* allocates memory for entire student list for the **list variable */
    student **list = malloc((*sizePtr)*(sizeof(student*)));

    /* iterates through each line and allocates memory for struct */
    int i;
    for(i = 0; i < *sizePtr; i++) {
        /* new allocation for each student struct, auto-sets values to 0*/
        list[i] = calloc(1, sizeof(student));
        fscanf(filePtr, "%d %s %s",     // scans each line of the file
            &list[i]->studentID,        // puts 1st num into studentID
            &list[i]->firstName,        // puts 2nd str into firstName
            &list[i]->lastName);        // puts 3rd str into lastName
    }

    fclose(filePtr);    // always close file after opening
    return list;
}

/* function returns index of desired studentID */
int find(int idNo, student **list, int size) {
    int i;
    for(i = 0; i < size; i++) {
        if(list[i]->studentID == idNo) {
            return i;   // return index if idNo matches
        }
    }
    return -1;  // return -1 by default (if idNo is not in list)
}

/* reads from input file of grades and puts elements into each student in list */
void input_grades(char *filename, student **list, int size) {
    FILE *filePtr = fopen(filename, "r");   // file pointer to file name
    int idNo, pos;  // student id number and index position respectively

    /* exit code for if file does not exist */
    if(filePtr == NULL) {
        printf("ERROR: The file '%s' does not exist.\n", filename);
        exit(1);
    }

    /* iterates through 'project_grades.txt' and adds grades to student list */
    int i;
    for(i = 0; i < size; i++) {
        fscanf(filePtr, "%d", &idNo);   // scans the student id number
        pos = find(idNo, list, size);   // finds the index of student id
        if(pos == -1) {
            /* print error and exit if id number is not in file */
            printf("ERROR: Student ID in '%s' is not in student list.\n", filename);
            exit(1);
        } else {
            fscanf(filePtr, "%d %d",
                &list[pos]->proj1Grade,     // assign project 1 grade into list
                &list[pos]->proj2Grade);    // assign project 2 grade into list
        }
    }
}

/* computes final course grades by taking average of project grades and assigns to student list */
void compute_final_course_grades(student **list, int size) {
    int i;
    for(i = 0; i < size; i++) {     // iterates through entire list
        list[i]->finalGrade = ((float) list[i]->proj1Grade + (float) list[i]->proj2Grade) / 2;
    }
}

/* writes the final course grades to an output file */
void output_final_course_grades(char *filename, student **list, int size) {
    FILE *filePtr = fopen(filename, "w");   // opens file to write

    fprintf(filePtr, "%d\n", size);         // writes the number of students on first line

    int i;
    for(i = 0; i < size; i++) {         // iterates through student list
        fprintf(filePtr, "%d %.1f\n",
            list[i]->studentID,         // prints the student ID
            list[i]->finalGrade);       // prints the final grade
    }

    fclose(filePtr);    // always close file after opening
}

/* prints the student list to console */
void print_list(student **list, int size) {
    int i;
    for(i = 0; i < size; i++) {     // iterates through entire student list array
        /* prints each element of student structure */
        printf("%d\t%s %s\t%3d %3d %6.1f\n",
            list[i]->studentID,
            list[i]->firstName,
            list[i]->lastName,
            list[i]->proj1Grade,
            list[i]->proj2Grade,
            list[i]->finalGrade);
    }
}

/* withdraws a student from the student list, and reduces class size by one*/
void withdraw(int idNo, student **list, int *sizePtr) {
    int i, pos = find(idNo, list, *sizePtr);    //finds the position of student ID
    if(pos == -1) {                         //prints error if the ID is not in list
        printf("ERROR: Student ID '%d' is not in student list.\n", idNo);
    } else {
        (*sizePtr)--;                       //reduce list size by one
        for(i = pos; i < *sizePtr; i++) {   //iterate through rest of list starting at ID position
            list[i] = list[i+1];            //collapse list by one, removing i'th position
        }
        free(list[i+1]);                    //free the extra element of the list
    }
}

/* destroys entire list by emptying it completely */
void destroy_list(student **list, int *sizePtr) {
    int i;
    for(i = 0; i < *sizePtr; i++) {
        free(list[i]);      //frees each student structure
    }
    free(*list);            //frees the pointer to list
    *list = NULL;           //list pointer points to NULL
    *sizePtr = 0;           //the size of student list is now 0
}
