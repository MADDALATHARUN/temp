// read and print names and marks.



#include <stdio.h >
#include <stdlib.h >
#include <string.h>
void replace_newline_with_null( char*any_string )
{
    if ( any_string[strlen(any_string) - 1] == '\n' )
    {
        any_string[strlen(any_string) - 1] = NULL;
    }
}
void main()
{
    int subject_count, student_count, counter, marks_counter, size = 5;

    int** marks;
    char** subjects;
    char** names;
    printf("How many subjects are there ? ");
    scanf("%d", &subject_count);
    subjects = ( char** ) malloc( subject_count * sizeof(char*));

    for (counter = 0 ; counter < subject_count ; counter++)
    {
        subjects[counter] = ( char* ) malloc(size);
        fflush(stdin);
        printf("Enter the subject_%d name: ", counter + 1);
        fgets(subjects[counter], size, stdin );

    }

    fflush(stdin);
    printf("How many students are there ? ");
    scanf("%d", &student_count);
    names = ( char** ) malloc( student_count* sizeof(char*));
    marks = ( int** ) malloc( student_count* sizeof(int*));

    for (counter = 0; counter < student_count; counter++)
    {
        names[counter] = ( char* ) malloc(size);
        marks[counter] = ( int* ) malloc(subject_count * sizeof(int));
        fflush(stdin);
        printf("Enter the student name_%d: ", counter + 1);
        fgets(names[counter], size, stdin );

        for (marks_counter = 0; marks_counter < subject_count; marks_counter++)
        {
            fflush(stdin);
            replace_newline_with_null(subjects[marks_counter]);
            printf("Enter the %s marks: ", subjects[marks_counter]);
            scanf("%d", marks[counter] + marks_counter);
        }
    }

    /*for(counter = 0 ; counter < student_count ; counter++)
    {
        replace_newline_with_null(names[counter]);
        printf("%d. Name: %s ", counter + 1, names[counter]);
        for (marks_counter =  0 ; marks_counter < subject_count ; marks_counter++)
        {
            printf(" %s marks: %d",  subjects[marks_counter], *(marks[counter] + marks_counter));
        }
        printf("\n");

    }
*/
    for(counter = 0; counter < student_count; counter++)
    {
        free(subjects[counter]);
        free(names[counter]);
        free(marks[counter]);
    }

    printf("%s %s marks: %d",  names[1], subjects[1], *(marks[1] + 1));
    free(marks);
    free(subjects);
    free(names);

   // printf("%s marks: %d",  subjects[1], *(marks[1]+1));
}
