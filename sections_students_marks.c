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
    int subject_count, sections, sections_counter, student_count, student_counter, marks_student_counter, size = 5;

    int*** marks;
    char*** subjects;
    char** names;
    /*printf("How many subjects are there ? ");
    scanf("%d", &subject_count);
    subjects = ( char** ) malloc( subject_count * sizeof(char*));

    for (student_counter = 0 ; student_counter < subject_count ; student_counter++)
    {
        subjects[student_counter] = ( char* ) malloc(size);
        fflush(stdin);
        printf("Enter the subject_%d name: ", student_counter + 1);
        fgets(subjects[student_counter], size, stdin );

    }*/
    printf("How many sections are there ? ");
    scanf("%d", &sections);
    names = ( char*** ) malloc( sections* sizeof(char**));
    marks = ( int*** ) malloc( sections* sizeof(int**));
    for (sections_counter = 0; sections_counter < sections; sections_counter++)
    {
    fflush(stdin);
    printf("How many students are there ? ");
    scanf("%d", &student_count);
    names[sections_counter] = ( char** ) malloc( student_count* sizeof(char));
    marks[sections_counter] = ( int** ) malloc( student_count* sizeof(int));

    for (student_counter = 0; student_counter < student_count; student_counter++)
    {
        names[sections_counter][student_counter] = ( char* ) malloc(size* sizeof(char));
        marks[sections_counter][student_counter] = ( int* ) malloc(subject_count * sizeof(int));
        fflush(stdin);
        printf("Enter the student name_%d: ", student_counter + 1);
        fgets(names[sections_counter][student_counter], size, stdin );
        replace_newline_with_null(names[sections_counter][student_counter]);
        fflush(stdin);
        for (marks_student_counter = 0; marks_student_counter < subject_count; marks_student_counter++)
        {
            fflush(stdin);
            replace_newline_with_null(subjects[marks_student_counter]);
            printf("Enter the %s marks: ", subjects[marks_student_counter]);
            scanf("%d", marks[sections_counter][student_counter] + marks_student_counter);
        }
    }
    }
    for (sections_counter = 0; sections_counter < sections; sections_counter++)
    {
    for(student_counter = 0 ; student_counter < student_count ; student_counter++)
    {
        //replace_newline_with_null(names[student_counter]);
        printf("%d. Name: %s ", student_counter + 1, names[sections_counter][student_counter]);
        for (marks_student_counter =  0 ; marks_student_counter < subject_count ; marks_student_counter++)
        {
            printf(" %s marks: %d",  subjects[marks_student_counter], *(marks[sections_counter][student_counter] + marks_student_counter));
        }
        printf("\n");

    }
    }
    

   // printf("%s marks: %d",  subjects[1], *(marks[1]+1));
}
