#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
char pass_id[50];
typedef struct
{
    char student_id[50];
    char name[50];
    char password[50];
    char department[50];
} Student;

typedef struct
{
    char course_id[50];
    char name_of_course[50];
    int credit_hour_of_subject;
} Course;

typedef struct
{
    char assignment_id[50];
    char assignment_name[50];
    char course_id[50];
    char deadline[20];
} Assignments;

typedef struct
{
    char student_id[50];
    char course_id[50];
} Enrollment;

typedef struct
{
    char student_id[50];
    char assignment_id[50];
    char last_submission[50];
} Submission;

typedef struct student
{
    char student_id[50];
    float grade_point;
    char grade[5];
} Grade;

void registerstudent()
{
    FILE *fp;
    Student s;
    fp = fopen("students.txt", "a");
    if (fp == NULL)
    {
        printf("File could not be created!\n");
        return;
    }
    printf("Student ID:");
    scanf(" %s", s.student_id);
    printf("Name:");
    scanf(" %s", s.name);
    printf("Password:");
    scanf(" %s", s.password);
    printf("Department:");
    scanf(" %s", s.department);
    fprintf(fp, "%s %s %s %s\n", s.student_id, s.name, s.password, s.department);
    fclose(fp);
    printf("Student Added.\n");
}

int loginasastudent()
{
    printf("Login To Proceed\n");

    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL)
    {
        printf("File could not be opened!\n");
        return 0;
    }

    Student s;
    char enter_id[50];
    char enter_password[20];

    printf("Enter your Id: ");
    scanf("%s", enter_id);

    printf("Enter your password: ");
    scanf("%s", enter_password);

    int found = 0;

    while (fscanf(fp, "%s %s %s %s", s.student_id, s.name, s.password, s.department) == 4)
    {
        if (strcmp(enter_id, s.student_id) == 0 && strcmp(enter_password, s.password) == 0)
        {
            found = 1;
            strcpy(pass_id, enter_id);
            break;
        }
    }

    fclose(fp);

    if (found)
    {
        printf("Login successful\n");
        return 1;
    }
    else
    {
        printf("Invalid id or password\n");
        return 0;
    }
}

void viewprofile_student()
{
    FILE *fp;
    fp = fopen("students.txt", "r");
    if (fp == NULL)
    {
        printf("File could not be opened!\n");
        return;
    }
    Student s;
    
    int found = 0;
    while (fscanf(fp, "%s %s %s %s", s.student_id, s.name, s.password, s.department) == 4)
    {
        if (strcmp(pass_id, s.student_id) == 0)
        {
            printf("Student Profile:\n");
            printf("Student ID: %s\n", s.student_id);
            printf("Name: %s\n", s.name);
            printf("Department: %s\n", s.department);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Invalid Given Data No Profile Found!");
    }
    fclose(fp);
}

void view_assignment_student()
{

    FILE *fp;
    fp = fopen("submissions.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening files!\n");
        return;
    }

    char enter_studenttid[10];
    Submission s;
    printf("Enter your assignment ID: ");
    scanf("%s", enter_studenttid);
    int access=0;

    while (fscanf(fp, "%s %s %s", s.student_id, s.assignment_id, s.last_submission) == 3)
    {
        if (strcmp(enter_studenttid, s.student_id) == 0)
        {
            printf("Student ID: %s\n", s.student_id);
            printf("Assignment ID: %s\n", s.assignment_id);
            printf("Date of Submission: %s\n", s.last_submission);
            access=1;
        }
    }
    fclose(fp);
    if (access)
    {
        printf("You have submitted assignment\n");
    }
    else
    {
        printf("You have not submitted assignment");
    }
}

void viewcourse_student()
{
    FILE *fpe;
    FILE *fpc;
    Enrollment en;
    Course c;
    int found = 0;
    fpe = fopen("enrollments.txt", "r");
    if (!fpe)
    {
        printf("Enrollments file could not be opened!\n");
        return;
    }

    printf("Enrolled Courses\n");
    while (fscanf(fpe, "%s %s", en.student_id, en.course_id) == 2)
    {
        if (strcmp(pass_id, en.student_id) == 0)
        {
            fpc = fopen("courses.txt", "r");
            if (!fpc)
            {
                printf("Courses file could not be opened!\n");
                fclose(fpe);
                return;
            }
            int course_found = 0;
            while (fscanf(fpc, "%s %s %d", c.course_id, c.name_of_course, &c.credit_hour_of_subject) == 3)
            {
                if (strcmp(en.course_id, c.course_id) == 0)
                {
                    printf("Course ID: %s | Name: %s | Credit Hours: %d\n", c.course_id, c.name_of_course, c.credit_hour_of_subject);
                    course_found = 1;
                    break;
                }
            }

            if (!course_found)
            {
                printf("Course ID: %s | Details not found\n", en.course_id);
            }

            fclose(fpc);
            found++;
        }
    }
    if (!found)
        printf("No courses found for this student.\n");
    else
        printf("Total courses enrolled: %d\n", found);
    fclose(fpe);
    printf("Operation Accomplished.\n");
}
void submitassignment()
{
    FILE *fp;
    Submission s;
    fp = fopen("submissions.txt", "a");
    if (fp == NULL)
    {
        printf("File could not be created!\n");
        return;
    }
    printf("Student ID: ");
    scanf(" %s", s.student_id);
    printf("Assigment ID: ");
    scanf(" %s", s.assignment_id);
    printf("Assigment submission Date: ");
    scanf(" %s", s.last_submission);
    fprintf(fp, "%s %s %s\n", s.student_id, s.assignment_id, s.last_submission);
    fclose(fp);
    printf("Assignment Submitted Successful.\n");
}

void enrollstudent()
{
    FILE *fp;
    Enrollment e;
    fp = fopen("enrollments.txt", "a");
    if (fp == NULL)
    {
        printf("File could not be created!\n");
        return;
    }
    printf("Student ID:");
    scanf(" %s", e.student_id);
    printf("Course ID:");
    scanf(" %s", e.course_id);
    fprintf(fp, "%s %s\n", e.student_id, e.course_id);
    fclose(fp);
    printf("Student Enrollment is successful.\n");
}

void grade_student()
{
    FILE *fp;
    Grade g;
    char student_id[50];
    fp = fopen("grades.txt", "r");
    if (fp == NULL)
    {
        printf("File could not be created!\n");
        return;
    }
    printf("Enter your student ID: ");
    scanf("%s", student_id);

    printf("\nYour Grades Are:\n");
    while (fscanf(fp, "%s %f %s", g.student_id, &g.grade_point, g.grade) == 3)
    {
        if (strcmp(student_id, g.student_id))
        {
            printf("Student ID: %s | Grade: %.2f | Grade: %s\n", g.student_id, g.grade_point, g.grade);
        }
        
    }
    fclose(fp);
}

void menu_student()
{
    int choice;
    do
    {
        printf("\nStudent Management System -- Student\n");
        printf("-----------------------\n");
        printf("Logged in as: %s\n", pass_id);
        printf("1. View Your Profile\n");
        printf("2. View Courses / Enroll in a Course\n");
        printf("3. View Assignments\n");
        printf("4. Submit Assignment\n");
        printf("5. View Grades\n");
        printf("6. Logout\n");
        printf("Enter Your Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            viewprofile_student();
            printf("\nEnter any key to continue..........");
            getch();
            break;
        case 2:
        {
            system("cls");
            int put;
            printf("Enrolled Courses\n");
            printf("1. View Courses\n");
            printf("2. Enroll in new Course\n");
            printf("3. Back\n");
            printf("Enter your choice: ");
            scanf("%d", &put);
            switch (put)
            {
            case 01:
                viewcourse_student();
                printf("\nEnter any key to continue..........");
                getch();
                break;
            case 02:
                printf("New Enrollment");
                enrollstudent();
                printf("\nEnter any key to continue..........");
                getch();
                break;
            case 3:
                break;
            default:
                break;
            }
            break;
        }
        case 3:
            system("cls");
            view_assignment_student();
            printf("\nEnter any key to continue..........");
            getch();
            break;
        case 4:
            system("cls");
            submitassignment();
            printf("\nEnter any key to continue..........");
            getch();
            break;
        case 5:
            system("cls");
            grade_student();
            printf("\nEnter any key to continue..........");
            getch();
            break;
        case 6:
            printf("Logged out successfully.\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);
}
