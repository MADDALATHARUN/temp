//Read percentage and print the grade.

#include <stdio.h>

char main()
{
    int percentage, marks_difference;
    char grades[] = {'O', 'A', 'B', 'C', 'D', 'E'}; // 'o' grade is only for 100 marks.
    char obtained_grade = 'F';
    printf("Enter marks difference between two grades: ");
    scanf("%d", &marks_difference);
    printf("Enter percentage to know grade: ");
    scanf("%d", &percentage);
    if(percentage > (100 - ((sizeof(grades) - 1) * marks_difference))) //sizeof(grades) - 1 is used to remove exeptional case 100 marks.
    {
        obtained_grade = grades[((100 / marks_difference) + 1) - (percentage + (marks_difference - (100 % marks_difference))) / marks_difference];
    }
    printf("Obtained grade to the given percentage %d: %c", percentage, obtained_grade);
    return obtained_grade;
}
