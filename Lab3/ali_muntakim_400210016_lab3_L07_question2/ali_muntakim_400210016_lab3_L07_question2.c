#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void compute_final_course_grades();
void output_final_course_grades();
void print_list(student **list, int size);
void withdraw(int idNo, student **list, int *sizePtr);
void destroy_list(student **list, int *sizePtr);

int main() {
    int size;           // class size or # of students
    student **list;     // pointer to the beginning of array of pointers of each student

    list = create_class_list("class_list.txt", &size);

    /* prints contents of list */
    printf("%d\n", size);
    int i;
    for(i = 0; i < size; i++) {
        printf("%d\t%s %s\t%d %d %.2f\n",
               list[i]->studentID,
               list[i]->firstName,
               list[i]->lastName,
               list[i]->proj1Grade,
               list[i]->proj2Grade,
               list[i]->finalGrade);
    }
    printf("\n");

    /* testing the find function */
    printf("index of %d is %d\n", 2512, find(2512, list, size));
    printf("index of %d is %d\n", 1200, find(1200, list, size));



    free(list);
    return 0;
}

/* function reads the input file and puts elements into an array of structures */
student **create_class_list(char *filename, int *sizePtr) {
    FILE *filePtr = fopen(filename, "r");   // file pointer to filename
    fscanf(filePtr, "%d", sizePtr);         // gets # of students from first line

    /* allocates memory for entire student list for the **list variable */
    student **list = malloc((*sizePtr)*(sizeof(student*)));

    /* iterates through each line and allocates memory for struct */
    int i;
    for(i = 0; i < *sizePtr; i++) {
        /* new allocation for each student struct, auto-sets values to 0*/
        list[i] = calloc(1, sizeof(student));
        fscanf(filePtr, "%d %s %s",     // reads each line of the file
               &list[i]->studentID,     // scans studentID
               &list[i]->firstName,     // scans firstName
               &list[i]->lastName);     // scans lastName
    }

    fclose(filePtr);    //always close file after reading
    return list;
}

/* function returns index of desired studentID */
int find(int idNo, student **list, int size) {
    int i;
    for(i = 0; i < size; i++) {
        if(list[i]->studentID == idNo) {
            return i;   //return index if idNo matches
        }
    }
    return -1;  //return -1 by default (if idNo is not in list)
}

void input_grades(char *filename, student **list, int size) {
    FILE *filePtr = fopen(filename, "r");
    int idNo, pos;
    int i;
    for(i = 0; i < size; i++) {
        fscanf(filePtr, "%d", idNo);
        pos = find(idNo, )
    }
}


void compute_final_course_grades() {

}

void output_final_course_grades() {

}

void print_list(student **list, int size) {

}

void withdraw(int idNo, student **list, int *sizePtr) {

}

void destroy_list(student **list, int *sizePtr) {

}
