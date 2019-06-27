#include <stdio.h>
#include <stdlib.h>

/* In this task you will continue working on the linked 
list of students in which you would like to store, for each student,
their name and age. As before you are provided with some code
that you should not modify:
A structure definition for the storage of each student's information.
A main() function to test your code. 
Prototypes for the functions createStudent() (from the previous task)
and append() (from the current task).
You will need the function definition (from the previous task) for 
createStudent(), as well as any other functions you added, such as 
copyStr() for example. 

Your new task is to write a function append() which 
takes as input two pointers: the first pointer holds the address
of the current end of the linked list of students, the second pointer 
points to a newly created student. Your function should append this
new student to the linked list and return the address (a struct student *)
of the new end of the list. */

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr); 
void copyStr (char inputName [], char newStudentName[]); 

int main(void) {
    struct student *start, *newStudptr, *end, *tmp;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);
    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printf("%s is %d years old.\n", start->name, start->age);
    printf("%s is %d years old.\n", start->next->name, start->next->age);
    printf("%s is %d years old.\n", start->next->next->name, start->next->next->age);

    tmp = start->next;
    free(start);
    start = tmp;
    tmp = start->next;
    free(start);
    free(tmp);

    return 0;
}

/* Place your function definitions here. Be sure to include the definition for 
   createStudent() and any other functions you created for the previous task. */

struct student *createStudent(char studentName[], int studentAge){
    struct student * newStudent;
    //the size of the STRUCT STUDENT not the size of the STRUCT STUDENT * !!!
    newStudent = (struct student *) malloc(sizeof(struct student));
    copyStr (studentName, newStudent->name);
    newStudent->age = studentAge;
    newStudent->next = NULL;
    return newStudent;
}

void copyStr (char inputName [], char newStudentName[]){
    int i = 0;
    while (inputName[i]!='\0'){
        newStudentName[i] = inputName[i];
        i++;
    }
    newStudentName[i] = '\0';
} 

struct student * append (struct student * end, struct student * newStudptr){
    end->next = newStudptr;
    end = newStudptr;
    return (end);
    
}
