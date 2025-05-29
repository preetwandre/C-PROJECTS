#include <stdio.h>

struct student
{
    int roll_no;
    char name[50];
    float per;
};

int main()
{
    int n;
    printf("Enter the no. of entries\n");
    scanf("%d", &n);

    struct student S[n];

    int count = 0;
    int choice = 0;
    do
    {
        printf("1.Add student\n2.Display students\n3.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter roll no.\n");
            scanf("%d", &S[count].roll_no);
            printf("Enter Name of Student\n");
            scanf("%s", &S[count].name);
            printf("Enter Percentage of student\n");
            scanf("%f", &S[count].per);
            count++;

            break;
        case 2:
            printf("Displaying all students details\n");
            printf("----------------------------------------\n");
            printf("Roll_no\t\tName\t\tPercentage\n");
            for (int i = 0; i < count; i++)
            {
                printf("%d\t\t%s\t\t%f\n", S[i].roll_no, S[i].name, S[i].per);
                printf("----------------------------------------\n");
            }
            break;
        case 3:
            printf("Exiting the program\n");

        default:
            printf("Invalid Chocie \n");
            break;
        }
    } while (choice != 3);

    return 0;
}