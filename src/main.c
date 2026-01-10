#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "student.h"
#include "admin.h"

int main()
{
    int j=1;
    do
    {
    int choice;
    printf("Student Management System\n");
    printf("-------------------------\n");
    printf("1. Login as Student\n");
    printf("2. Login as Admin\n");
    printf("3. Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        int choice3;
        printf("1. Login as Student\n");
        printf("2. Register as Student\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice3);
        switch (choice3)
        {
        case 1:
            system("cls");
            int authenticate= loginasastudent();
            if (authenticate)
            {
                menu_student();
            }
            break;
        case 2:
            system("cls");
            registerstudent();
            printf("You have been registered as Student\n");
            printf("Login to proceed\n");
            printf("\nEnter any key to continue..........");
            getch();
            break;
        case 3: 
            j=0;
            break;
        default:
            break;
        }
        
        break;
    }

    case 2:
    {
        int i = 1;
        int choice2;
        int verify = Login_admin();
        if (verify)
        {
            do
            {
                adminmainMenu();
                printf("Enter your choice: ");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                    ManageSudents();
                    break;
                case 2:
                    Courses_Menu();
                    break;
                case 3:
                    Assignment_Menu();
                    break;
                case 4:
                    Manage_Grades();
                    break;
                case 5:
                    Manage_Enrollments();
                    break;
                case 6:
                    i=0;
                    break;
                default:
                    break;
                }

            } while (i);
        }

        break;
    }
    case 3:
        j=0;
        break;
    default:
        break;
    }
    } while (j);
    return 0;
}
