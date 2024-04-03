#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define count 4

int i, j, temp = 0, choice, sum = 0;

struct student
{
    int rollno;
    char name[100];
    int marks;
    float percent;
    char grade;
};
struct student fe[100];

void askdata(void)
{
    for (i = 0; i < count; i++)
    {
        fe[i].rollno = i + 1;
        printf("Roll No %d\n", fe[i].rollno);
        printf("Name: ");
        scanf("%s", &fe[i].name);
        printf("Marks: ");
        scanf("%d", &fe[i].marks);
        printf("\n");
    }
}

void calculategrade(void)
{
    for (i = 0; i < count; i++)
    {
        fe[i].percent = fe[i].marks / 7.00;
        if (fe[i].percent < 40)
        {
            fe[i].grade = 'D';
        }
        else if (fe[i].percent < 60)
        {
            fe[i].grade = 'C';
        }
        else if (fe[i].percent < 75)
        {
            fe[i].grade = 'B';
        }
        else
        {
            fe[i].grade = 'A';
        }
        sum = sum + fe[i].marks;
    }
}

void showresult(void)
{
    system("cls");
    printf("R.No    Name            Marks       Percentage  Grade\n");
    for (i = 0; i < count; i++)
    {
        printf("%4d  ", fe[i].rollno);
        printf("%-16s  ", fe[i].name);
        printf("%3d  ", fe[i].marks);
        printf("%13.2f  ", fe[i].percent);
        printf("%5c\n", fe[i].grade);
    }
    printf("                       Tottal: %d\n", sum);
}

void showmenu(void)
{
    printf("\nSort by..");
    printf("\n1: Roll No");
    printf("\n2: Name");
    printf("\n3: Marks");
    printf("\n4: Exit           Enter your choice: ");
    scanf("%d", &choice);
}

void sortdata(void)
{
    struct student stemp;
    switch (choice)
    {
    case 1:
        for (i = 0; i < count - 1; i++)
        {
            for (j = 0; j < count - 1; j++)
            {
                if (fe[j].rollno > fe[j + 1].rollno)
                {
                    stemp = fe[j];
                    fe[j] = fe[j + 1];
                    fe[j + 1] = stemp;
                }
            }
        }

        break;

    case 2:
        for (i = 0; i < count - 1; i++)
        {
            for (j = 0; j < count - 1; j++)
            {
                if (fe[j].name[0] > fe[j + 1].name[0])
                {
                    stemp = fe[j];
                    fe[j] = fe[j + 1];
                    fe[j + 1] = stemp;
                }
            }
        }

        break;
    case 3:
        for (i = 0; i < count - 1; i++)
        {
            for (j = 0; j < count - 1; j++)
            {
                if (fe[j].marks < fe[j + 1].marks)
                {
                    stemp = fe[j];
                    fe[j] = fe[j + 1];
                    fe[j + 1] = stemp;
                }
            }
        }
        break;
    case 4:
        exit(0);
    default:
        break;
    }
}

int main()
{
    system("clear");
    printf("\n\n");
    askdata();
    calculategrade();
    int i = 0;
    while (i < count)
    {
        sortdata();
        showresult();
        showmenu();
        i++;
    }

    printf("\n\n");

    return 0;
}