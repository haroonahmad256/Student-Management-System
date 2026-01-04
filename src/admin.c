#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

struct students
{
    char student_id[20];
    char student_name[100];
    char password[50];
    char department[50];
};

struct admins
{
    char admin_id[20];
    char admin_password[50];
};

struct courses
{
    char course_id[20];
    char course_name[50];
    int creadit_hours;
};

struct enrollments
{
    char student_ID[20];
    char course_ID[20];
};

struct assignments
{
    char Course_id[20];
    char Assignment_id[20];
    char Assignment_name[50];
    char deadline[50];
};

struct submission
{
    char student_id[20];
    char assignment_id[20];
    char date_submission[50];
};

struct grades
{
    char student_id[20];
    float gradepoint;
    char grade[10];
};

int Login_admin()
{

    int choice;
    printf("1. Login as Admin\n");
    printf("2. Reset Password\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        FILE *fptr;
        fptr = fopen("admin_login.txt", "r");

        if (fptr == NULL)
        {
            printf("Error opening file\n");
        }

        char enter_adminid[50];
        char enter_password[20];
        printf("Enter your Admin Id: ");
        scanf("%s", enter_adminid);
        printf("Enter your password: ");
        scanf("%s", enter_password);

        int i = 1;
        do
        {
            int on = 0;
            struct admins admin;

            while (fscanf(fptr, "%s %s", admin.admin_id, admin.admin_password) == 2)
            {

                if (strcmp(enter_adminid, admin.admin_id) == 0 && strcmp(enter_password, admin.admin_password) == 0)
                {
                    on = 1;
                }
            }

            if (on)
            {
                printf("Login successful\n");
                return 1;
                i = 0;
            }

            else
            {
                printf("Invaid admin id or password\n");
                return 0;
                break;
            }

            fclose(fptr);

        } while (i);

        break;

    case 2:
    {
        FILE *fptr3;
        FILE *fptr2;
        fptr3 = fopen("admin_login.txt", "r");
        fptr2 = fopen("admin_login_temp.txt", "w");
        if (fptr == NULL || fptr2 == NULL)
        {
            printf("Error opening files!\n");
            if (fptr3)
                fclose(fptr3);
            if (fptr2)
                fclose(fptr2);
            return 0;
        }
        char forgotpassword[10];
        char admin_id[10], new_password[20];
        struct admins admin;

        printf("Forgot password as Admin(y/n): ");
        scanf("%s", forgotpassword);
        int inside = 0;

        if (forgotpassword[0] == 'y' || forgotpassword[0] == 'Y')
        {
            printf("Enter your Admin ID to verify: ");
            scanf("%s", admin_id);

            while (fscanf(fptr3, "%s %s", admin.admin_id, admin.admin_password) == 2)
            {

                if (strcmp(admin_id, admin.admin_id) == 0)
                {
                    printf("Enter new password: ");
                    scanf("%s", new_password);
                    fprintf(fptr2, "%s %s\n", admin.admin_id, new_password);
                    inside = 1;
                }

                else
                {

                    fprintf(fptr2, "%s %s\n", admin.admin_id, admin.admin_password);
                }
            }
            fclose(fptr3);
            fclose(fptr2);

            if (inside)
            {
                remove("admin_login.txt");
                rename("admin_login_temp.txt", "admin_login.txt");
                printf("Your password has been changed successfully\n");
                return 1;
            }

            else
            {
                remove("admin_login_temp.txt");
                printf("Pssword could not changed\n");
                return 0;
            }
        }
        break;
    }
    default:
        break;
    }
}

void add_student()
{

    FILE *fptr;
    fptr = fopen("students.txt", "a");
    if (fptr == NULL)
    {
        printf("Error opening files!\n");
        return;
    }
    struct students student;
    printf("Enter Student Student ID: ");
    scanf("%s", student.student_id);
    printf("Enter Student Name: ");
    scanf("%s", student.student_name);
    printf("Enter Student Password: ");
    scanf("%s", student.password);
    printf("Eter Student Department: ");
    scanf("%s", student.department);
    fprintf(fptr, "%s %s %s %s\n", student.student_id, student.student_name, student.password, student.department);
    printf("Student Data added successfully\n");
    fclose(fptr);
    printf("Enter any key to continue..........\n");
    getchar();
}

void delete_student()
{

    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("students.txt", "r");
    fptr2 = fopen("students_temp.txt", "w");

    if (fptr == NULL || fptr2 == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        if (fptr2) fclose(fptr2);
        return;
    }

    char del_account[10];
    char enter_studentid[10];
    struct students student;
    printf("Do you want to delete a student account(y/n): ");
    scanf("%s", del_account);
    int inside = 0;

    if (del_account[0] == 'y' || del_account[0] == 'Y')
    {
        printf("Enter Student ID: ");
        scanf("%s", enter_studentid);

        while (fscanf(fptr, "%s %s %s %s", student.student_id, student.student_name, student.password, student.department) == 4)
        {
            if (strcmp(enter_studentid, student.student_id) == 0)
            {
                inside = 1;
                continue;
            }

            else
            {

                fprintf(fptr2, "%s %s %s %s\n", student.student_id, student.student_name, student.password, student.department);
            }
        }

        fclose(fptr);
        fclose(fptr2);

        if (inside)
        {
            remove("students.txt");
            rename("students_temp.txt", "students.txt");
            printf("You account has been deleted successfully\n");
            printf("Enter any key to continue..........\n");
            getchar();
        }
        else
        {
            remove("students_temp.txt");
            printf("Account couldn't be deleted\n");
            printf("Enter any key to continue..........");
            getchar();
        }
    }
}

void show_student_data()
{
    FILE *fptr;
    fptr = fopen("students.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        return;
    }
    char enter_studentid[10];
    struct students student;
    int choice;
    printf("Perform any action\n");
    printf("1. Show data of a particular Student\n");
    printf("2. SHow all students data\n");
    printf("3. Exit\n");
    printf("What do you want: ");
    scanf("%d", &choice);

    int inside = 0;
    switch (choice)
    {
    case 1:

        printf("Enter Student ID of student: ");
        scanf("%s", enter_studentid);

        while (fscanf(fptr, "%s %s %s %s", student.student_id, student.student_name, student.password, student.department) == 4)
        {
            if (strcmp(enter_studentid, student.student_id) == 0)
            {
                printf("Student ID: %s\n", student.student_id);
                printf("Student Name: %s\n", student.student_name);
                printf("Department: %s\n", student.department);
                printf("Password: %s\n", student.password);
                inside = 1;
            }
        }

        if (inside)
        {
            printf("Rewiew data\n");
            printf("Enter any key to continue..........\n");
            getchar();
        }
        else
        {
            printf("Couldn't perform the operation!\n");
            printf("Enter any key to continue..........\n");
            getchar();
        }

        fclose(fptr);
        break;

    case 2:
        int i = 0;

        while (fscanf(fptr, "%s %s %s %s", student.student_id, student.student_name, student.password, student.department) == 4)
        {
            printf("Student%d data: \n", i + 1);
            printf("Student ID: %s\n", student.student_id);
            printf("Student Name: %s\n", student.student_name);
            printf("Department: %s\n", student.department);
            printf("Password: %s\n", student.password);
            printf("\n");
            inside = 1;
            i++;
        }

        if (inside)
        {
            printf("Rewiew data\n");
            printf("Enter any key to continue..........\n");
            getchar();
        }
        else
        {
            printf("Couldn't perform the operation!\n");
            printf("Enter any key to continue..........\n");
            getchar();
        }

        fclose(fptr);
        break;

    case 3:
        break;
    default:
        break;
    }
}

void change_name()
{
    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("students.txt", "r");
    fptr2 = fopen("students_temp.txt", "w");
    if (fptr == NULL || fptr2 == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        if (fptr2) fclose(fptr2);
        return;
    }
    char forgotpassword;
    char student_id[10], new_name[50];
    struct students student;

    printf("Enter Student ID to change name: ");
    scanf("%s", student_id);

    int inside = 0;
    while (fscanf(fptr, "%s %s %s %s", student.student_id, student.student_name, student.password, student.department) == 4)
    {
        if (strcmp(student_id, student.student_id) == 0)
        {
            printf("Enter new name: ");
            scanf("%s", new_name);
            fprintf(fptr2, "%s %s %s %s\n", student.student_id, new_name, student.password, student.department);
            inside = 1;
        }

        else
        {

            fprintf(fptr2, "%s %s %s %s\n", student.student_id, student.student_name, student.password, student.department);
        }
    }

    fclose(fptr2);
    fclose(fptr);

    if (inside)
    {
        remove("students.txt");
        rename("students_temp.txt", "students.txt");
        printf("Your Student Name has been changed successfully\n");
        printf("Enter any key to continue..........\n");
        getchar();
    }

    else
    {
        remove("students_temp.txt");
        printf("Student Name could not changed\n");
        printf("Enter any key to continue..........\n");
        getchar();
    }
}

void change_student_ID()
{

    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("students.txt", "r");
    fptr2 = fopen("students_temp.txt", "w");
    if (fptr == NULL || fptr2 == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        if (fptr2) fclose(fptr2);
        return;
    }
    char forgotpassword;
    char student_id[20], new_ID[20];
    struct students student;

    printf("Enter Student ID to change ID: ");
    scanf("%s", student_id);

    int inside = 0;
    while (fscanf(fptr, "%s %s %s %s", student.student_id, student.student_name, student.password, student.department) == 4)
    {
        if (strcmp(student_id, student.student_id) == 0)
        {
            printf("Enter new ID: ");
            scanf("%s", new_ID);
            fprintf(fptr2, "%s %s %s %s\n", new_ID, student.student_name, student.password, student.department);
            inside = 1;
        }

        else
        {

            fprintf(fptr2, "%s %s %s %s\n", student.student_id, student.student_name, student.password, student.department);
        }
    }

    fclose(fptr2);
    fclose(fptr);

    if (inside)
    {
        remove("students.txt");
        rename("students_temp.txt", "students.txt");
        printf("Your Student ID has been changed successfully\n");
        printf("Enter any key to continue..........\n");
        getchar();
    }

    else
    {
        remove("students_temp.txt");
        printf("Student ID could not changed\n");
        printf("Enter any key to continue..........\n");
        getchar();
    }
}

void change_student_password()
{

    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("students.txt", "r");
    fptr2 = fopen("students_temp.txt", "w");
    if (fptr == NULL || fptr2 == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        if (fptr2) fclose(fptr2);
        return;
    }
    char forgotpassword;
    char student_id[10], new_Password[20];
    struct students student;

    printf("Enter Student ID to change Password: ");
    scanf("%s", student_id);

    int inside = 0;
    while (fscanf(fptr, "%s %s %s %s", student.student_id, student.student_name, student.password, student.department) == 4)
    {
        if (strcmp(student_id, student.student_id) == 0)
        {
            printf("Enter new Password: ");
            scanf("%s", new_Password);
            fprintf(fptr2, "%s %s %s %s\n", student.student_id, student.student_name, new_Password, student.department);
            inside = 1;
        }

        else
        {

            fprintf(fptr2, "%s %s %s %s\n", student.student_id, student.student_name, student.password, student.department);
        }
    }

    fclose(fptr2);
    fclose(fptr);

    if (inside)
    {
        remove("students.txt");
        rename("students_temp.txt", "students.txt");
        printf("Your Student Account Password has been changed successfully\n");
        printf("Enter any key to continue..........\n");
        getchar();
    }

    else
    {
        remove("students_temp.txt");
        printf("Student Account Password could not changed\n");
        printf("Enter any key to continue..........\n");
        getchar();
    }
}

void change_student_Department()
{

    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("students.txt", "r");
    fptr2 = fopen("students_temp.txt", "w");
    if (fptr == NULL || fptr2 == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        if (fptr2) fclose(fptr2);
        return;
    }
    char forgotpassword;
    char student_id[10], new_Department[20];
    struct students student;

    printf("Enter Student ID to change Department: ");
    scanf("%s", student_id);

    int inside = 0;
    while (fscanf(fptr, "%s %s %s %s", student.student_id, student.student_name, student.password, student.department) == 4)
    {
        if (strcmp(student_id, student.student_id) == 0)
        {
            printf("Enter new Department: ");
            scanf("%s", new_Department);
            fprintf(fptr2, "%s %s %s %s\n", student.student_id, student.student_name, student.password, new_Department);
            inside = 1;
        }

        else
        {

            fprintf(fptr2, "%s %s %s %s\n", student.student_id, student.student_name, student.password, student.department);
        }
    }

    fclose(fptr2);
    fclose(fptr);

    if (inside)
    {
        remove("students.txt");
        rename("students_temp.txt", "students.txt");
        printf("Your Student Department has been changed successfully\n");
        printf("Enter any key to continue..........");
        getchar();
    }

    else
    {
        remove("students_temp.txt");
        printf("Student Department could not changed\n");
        printf("Enter any key to continue..........\n");
        getchar();
    }
}

void Update_student()
{
    int choice;
    printf("Edit Student Details\n");
    printf("1. Change ID\n");
    printf("2. Change Name\n");
    printf("3. Change Password\n");
    printf("4. Change Department\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        change_student_ID();
        break;

    case 2:
        change_name();
        break;

    case 3:
        change_student_password();
        break;

    case 4:
        change_student_Department();
        break;

    case 5:

        break;
    default:
        break;
    }
}

void add_course()
{
    FILE *fptr;
    fptr = fopen("courses.txt", "a");
    if (fptr == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        return;
    }
    struct courses course;
    printf("Enter New course ID: ");
    scanf("%s", course.course_id);
    printf("Enter Course Name: ");
    scanf("%s", course.course_name);
    printf("Enter Course Credit Hours: ");
    scanf("%d", &course.creadit_hours);
    fprintf(fptr, "%s %s %d\n", course.course_id, course.course_name, course.creadit_hours);
    fclose(fptr);
    printf("Course has been added Successsfully");
}

void delete_course()
{
    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("courses.txt", "r");
    fptr2 = fopen("courses_temp.txt", "w");
    if (fptr == NULL || fptr2 == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        if (fptr2) fclose(fptr2);
        return;
    }
    char del_course[10];
    char enter_course_ID[10];
    printf("Do you want to delete a Course(y/n): ");
    scanf("%s", del_course);
    int inside = 0;

    if (del_course[0] == 'y' || del_course[0] == 'Y')
    {
        printf("Enter Course ID: ");
        scanf("%s", enter_course_ID);

        struct courses course;
        while (fscanf(fptr, "%s %s %d", course.course_id, course.course_name, &course.creadit_hours) == 3)
        {
            if (strcmp(enter_course_ID, course.course_id) == 0)
            {
                inside = 1;
                continue;
            }
            else
            {

                fprintf(fptr2, "%s %s %d\n", course.course_id, course.course_name, course.creadit_hours);
            }
        }

        fclose(fptr2);
        fclose(fptr);

        if (inside)
        {
            remove("courses.txt");
            rename("courses_temp.txt", "courses.txt");
            printf("Course has been deleted successfully\n");
        }
        else
        {
            remove("courses_temp.txt");
            printf("Course couldn't be deleted\n");
        }
    }
}

void view_courses()
{
    FILE *fptr;
    fptr = fopen("courses.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        if (fptr) fclose(fptr);
        return;
    }
    char enter_courseid[10];
    struct courses course;
    int choice;
    printf("Perform any action\n");
    printf("1. Show data of a particular Course\n");
    printf("2. SHow all Course\n");
    printf("3. Exit\n");
    printf("What do you want: ");
    scanf("%d", &choice);

    int inside = 0;
    switch (choice)
    {
    case 1:

        printf("Enter Course ID: ");
        scanf("%s", enter_courseid);

        while (fscanf(fptr, "%s %s %d", course.course_id, course.course_name, &course.creadit_hours) == 3)
        {
            if (strcmp(enter_courseid, course.course_id) == 0)
            {
                printf("Course ID: %s\n", course.course_id);
                printf("Course Name: %s %s\n", course.course_name);
                printf("Credit Hourse: %d\n", course.creadit_hours);
                inside = 1;
            }
        }
        fclose(fptr);

        if (inside)
        {
            printf("Rewiew data\n");
        }
        else
        {
            printf("Couldn't perform the operation!\n");
        }

        break;

    case 2:
        int i = 0;

        while (fscanf(fptr, "%s %s %d", course.course_id, course.course_name, &course.creadit_hours) == 3)
        {
            printf("Course no: %d\n", i + 1);
            printf("Course ID: %s\n", course.course_id);
            printf("Course Name: %s\n", course.course_name);
            printf("Credit Hourse: %d\n", course.creadit_hours);
            printf("-----------------------\n");
            inside = 1;
            i++;
        }
        fclose(fptr);

        if (inside)
        {
            printf("Rewiew data\n");
        }
        else
        {
            printf("Couldn't perform the operation!\n");
        }


        break;

    case 3:
        break;
    default:
        break;
    }
}

void update_courses()
{
    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("courses.txt", "r");
    fptr2 = fopen("courses_temp.txt", "w");
    if (fptr == NULL || fptr2 == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        if (fptr2) fclose(fptr2);
        return;
    }
    char course_id[20], new_ID[20];
    struct courses course;

    printf("Enter Course ID: ");
    scanf("%s", course_id);

    int inside = 0;
    while (fscanf(fptr, "%s %s %d", course.course_id, course.course_name, &course.creadit_hours) == 3)
    {
        if (strcmp(course_id, course.course_id) == 0)
        {
            printf("Enter new ID: ");
            scanf("%s", new_ID);
            fprintf(fptr2, "%s %s %d\n", new_ID, course.course_name, course.creadit_hours);
            inside = 1;
        }

        else
        {

            fprintf(fptr2, "%s %s %d\n", course.course_id, course.course_name, course.creadit_hours);
        }
    }

    fclose(fptr2);
    fclose(fptr);

    if (inside)
    {
        remove("courses.txt");
        rename("courses_temp.txt", "courses.txt");
        printf("Your Course ID has been changed successfully\n");
    }

    else
    {
        remove("courses_temp.txt");
        printf("Course ID could not changed\n");
    }
}

void new_enrollments()
{

    FILE *fptr;
    fptr = fopen("enrollments.txt", "a");
    if (fptr == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        return;
    }
    struct enrollments enroll;
    printf("Enter Student ID: ");
    scanf("%s", enroll.student_ID);
    printf("Enter Course ID: ");
    scanf("%s", enroll.course_ID);
    fprintf(fptr, "%s %s\n", enroll.student_ID, enroll.course_ID);
    fclose(fptr);
    printf("New Enrollment Added Successfully\n");
}

void view_enrollments()
{

    FILE *fptr;
    fptr = fopen("enrollments.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        return;
    }
    char enter_courseid[10];
    struct enrollments enroll;
    int choice;
    printf("Perform any action\n");
    printf("1. View enrollments of a particular course\n");
    printf("2. View all enrollments\n");
    printf("3. Exit\n");
    printf("What do you want: ");
    scanf("%d", &choice);

    int inside = 0;
    switch (choice)
    {
    case 1:

        int j = 0;
        printf("Enter Course ID: ");
        scanf("%s", enter_courseid);

        while (fscanf(fptr, "%s %s", enroll.student_ID, enroll.course_ID) == 2)
        {
            if (strcmp(enter_courseid, enroll.course_ID) == 0)
            {
                printf("Course No: %d\n", j + 1);
                printf("Course ID: %s | Course Name: %s", enroll.course_ID, enroll.student_ID);
                printf("\n");
                inside = 1;
                j++;
            }
        }
        fclose(fptr);

        if (inside)
        {
            printf("Rewiew data\n");
        }
        else
        {
            printf("Couldn't perform the operation!\n");
        }

        break;

    case 2:
        int i = 0;

        while (fscanf(fptr, "%s %s", enroll.course_ID, enroll.student_ID) == 2)
        {
            printf("Course no: %d\n", i + 1);
            printf("Course ID: %s | Course Name: %s", enroll.course_ID, enroll.student_ID);
            printf("-----------------------\n");
            inside = 1;
            i++;
        }
        fclose(fptr);

        if (inside)
        {
            printf("Rewiew data\n");
        }
        else
        {
            printf("Couldn't perform the operation!\n");
        }


        break;

    case 3:
        break;
    default:
        break;
    }
}

void remove_enrollments()
{

    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("enrollments.txt", "r");
    fptr2 = fopen("enrollments_temp.txt", "w");
    if (fptr == NULL || fptr2 == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        if (fptr2) fclose(fptr2);
        return;
    }
    char del_enrollement[10];
    char enter_student_ID[10];
    printf("Do you want to delete an enrollment(y/n): ");
    scanf("%s", del_enrollement);
    int inside = 0;

    if (del_enrollement[0] == 'y' || del_enrollement[0] == 'Y')
    {
        printf("Enter Student ID: ");
        scanf("%s", enter_student_ID);

        struct enrollments enroll;
        while (fscanf(fptr, "%s %s", enroll.course_ID, enroll.student_ID) == 2)
        {
            if (strcmp(enter_student_ID, enroll.student_ID) == 0)
            {
                inside = 1;
                continue;
            }

            else
            {

                fprintf(fptr2, "%s %s", enroll.student_ID, enroll.student_ID);
            }
        }

        fclose(fptr2);
        fclose(fptr);

        if (inside)
        {
            remove("enrollments.txt");
            rename("enrollments_temp.txt", "enrollments.txt");
            printf("Course Enrollement has been deleted successfully\n");
        }
        else
        {
            remove("enrollments_temp.txt");
            printf("Course Enrollement couldn't be deleted\n");
        }
    }
}

void add_assignment()
{
    FILE *fptr = fopen("assignments.txt", "a");
    FILE *fptr2 = fopen("courses.txt", "r");

    if (fptr == NULL || fptr2 == NULL)
    {
        printf("Error opening files!\n");
        if (fptr)
            fclose(fptr);
        if (fptr2)
            fclose(fptr2);
        return;
    }

    struct assignments assignment;
    struct courses course;

    printf("Enter Course ID: ");
    scanf("%s", assignment.Course_id);

    int course_found = 0;
    while (fscanf(fptr2, "%s %s %d", course.course_id, course.course_name, &course.creadit_hours) == 3)
    {
        if (strcmp(assignment.Course_id, course.course_id) == 0)
        {
            course_found = 1;
            break;
        }
    }
    fclose(fptr2);

    if (course_found)
    {
        int id_is_unique = 1;
        struct assignments a;
        printf("Enter A Unique Assignment ID: ");
        scanf("%s", assignment.Assignment_id);

        FILE *fptr3 = fopen("assignments.txt", "r");
        if (fptr3 != NULL)
        {
            while (fscanf(fptr3, "%s %s %s %s", a.Assignment_id, a.Course_id, a.Assignment_name, a.deadline) == 4)
            {
                if (strcmp(assignment.Assignment_id, a.Assignment_id) == 0)
                {
                    id_is_unique = 0;
                    break;
                }
            }
            fclose(fptr3);
        }

        if (id_is_unique)
        {
            printf("Enter Assignment Name: ");
            scanf("%s", assignment.Assignment_name);
            printf("Enter Deadline: ");
            scanf("%s", assignment.deadline);

            fprintf(fptr, "%s %s %s %s\n", assignment.Assignment_id, assignment.Course_id, assignment.Assignment_name, assignment.deadline);
            printf("Assignment added successfully!\n");
        }
        else
        {
            printf("Assignment ID already exists.\n");
        }
    }
    else
    {
        printf("Course ID doesn't exist.\n");
    }

    fclose(fptr);
}

void remove_Assignment()
{
    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("assignments.txt", "r");
    fptr2 = fopen("assignments_temp.txt", "w");
    if (fptr == NULL || fptr2 == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        if (fptr2) fclose(fptr2);
        return;
    }
    char del_assignment[10];
    char Assignment_ID[10];
    printf("Do you want to remove an assignment(y/n): ");
    scanf("%s", del_assignment);
    int inside = 0;

    if (del_assignment[0] == 'y' || del_assignment[0] == 'Y')
    {
        printf("Enter Assignment ID: ");
        scanf("%s", Assignment_ID);

        struct assignments assignment;
        while (fscanf(fptr, "%s %s %s %s", assignment.Assignment_id, assignment.Course_id, assignment.Assignment_name, assignment.deadline) == 4)
        {
            if (strcmp(Assignment_ID, assignment.Assignment_id) == 0)
            {
                inside = 1;
                continue;
            }
            else
            {
                fprintf(fptr2, "%s %s %s %s\n", assignment.Assignment_id, assignment.Course_id, assignment.Assignment_name, assignment.deadline);
            }
        }

        fclose(fptr2);
        fclose(fptr);

        if (inside)
        {
            remove("assignments.txt");
            rename("assignments_temp.txt", "assignments.txt");
            printf("Assignment has been deleted successfully\n");
        }
        else
        {
            remove("assignments_temp.txt");
            printf("Assignment couldn't be deleted\n");
        }
    }
}

void view_assignment()
{
    FILE *fptr;
    fptr = fopen("assignments.txt", "r");
    if (fptr == NULL )
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        return;
    }

    char enter_assignmentid[10];
    struct assignments assignment;

    int i = 0;

    while (fscanf(fptr, "%s %s %s %s", assignment.Assignment_id, assignment.Course_id, assignment.Assignment_name, assignment.deadline) == 4)
    {
        printf("Assignment no: %d\n", i + 1);
        printf("Assignment ID: %s\n", assignment.Assignment_id);
        printf("Course ID: %s\n", assignment.Course_id);
        printf("Assignment Name: %s\n", assignment.Assignment_name);
        printf("Assignment Deadline %s\n", assignment.deadline);
        printf("-----------------------\n");
        i++;
    }

    fclose(fptr);
}

void view_submissions()
{

    FILE *fptr;
    fptr = fopen("submissions.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        return;
    }
    char enter_assignmentid[10];
    struct submission submit;

    int i = 0;
    int sum = 0;
    int should_g0 = 0;

    char sid[20];
    printf("Enter Assignment id to check submissions: ");
    scanf("%s", sid);

    while (fscanf(fptr, "%s %s %s", submit.assignment_id, submit.student_id, submit.date_submission) == 3)
    {
        if (strcmp(sid, submit.assignment_id) == 0)
        {
            printf("Student no: %d\n", i + 1);
            printf("Strudent ID: %s\n", submit.assignment_id);
            printf("Assignment ID: %s\n", submit.student_id);
            printf("Date of Submission: %s\n", submit.date_submission);
            printf("-----------------------\n");
            should_g0 = 1;
            i++;
            sum += 1;
        }
    }

    if (should_g0)
    {
        printf("%d Students have submitted the assignment\n", sum);
    }
    else
    {
        printf("Assignment Id doesn't exist\n");
    }

    fclose(fptr);
}

void Add_grades()
{
    FILE *fptr;
    fptr = fopen("grades.txt", "a");
    if (fptr == NULL )
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        return;
    }
    struct grades g;
    printf("Enter Student ID: ");
    scanf("%s", g.student_id);

    int n;
    float marks;
    int total = 0;
    printf("Enter number of Subjects of student: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter marks in subject %d: ", i + 1);
        scanf("%f", &marks);
        total += marks;
    }

    float percentage = (total / (n * 100.0)) * 100.0;
    float gradepoint;
    char grade[10];

    if (percentage >= 85.0)
    {
        g.gradepoint = 4.0;
        strcpy(g.grade, "A+");
    }
    else if (percentage >= 80.0)
    {
        g.gradepoint = 3.7;
        strcpy(g.grade, "A");
    }
    else if (percentage >= 75.0)
    {
        g.gradepoint = 3.4;
        strcpy(g.grade, "B+");
    }
    else if (percentage >= 70.0)
    {
        g.gradepoint = 3.0;
        strcpy(g.grade, "B");
    }
    else if (percentage >= 65.0)
    {
        g.gradepoint = 2.5;
        strcpy(g.grade, "C");
    }
    else if (percentage >= 60.0)
    {
        g.gradepoint = 2.0;
        strcpy(g.grade, "D");
    }
    else if (percentage >= 55.0)
    {
        g.gradepoint = 1.0;
        strcpy(g.grade, "E");
    }
    else
    {
        g.gradepoint = 0.0;
        strcpy(g.grade, "F");
    }

    fprintf(fptr, "%s %.2f %s\n", g.student_id, g.gradepoint, g.grade);
    fclose(fptr);
    printf("Grades have been Added\n");
    printf("Press any key to continue......\n");
    getchar();
}

void Delete_grade()
{
    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("grades.txt", "r");
    fptr2 = fopen("grades_temp.txt", "w");
    if (fptr == NULL || fptr2 == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        if (fptr2) fclose(fptr2);
        return;
    }
    char del_grades[10];
    char Student_ID[10];
    printf("Do you want to remove grades of a student(y/n): ");
    scanf("%s", del_grades);
    int inside = 0;

    if (del_grades[0] == 'y' || del_grades[0] == 'Y')
    {
        printf("Enter Student ID: ");
        scanf("%s", Student_ID);

        struct grades g;
        while (fscanf(fptr, "%s %f %s", g.student_id, &g.gradepoint, g.grade) == 3)
        {
            if (strcmp(Student_ID, g.student_id) == 0)
            {
                inside = 1;
                continue;
            }
            else
            {

                fprintf(fptr2, "%s %.2f %s\n", g.student_id, g.gradepoint, g.grade);
            }
        }

        fclose(fptr2);
        fclose(fptr);

        if (inside)
        {
            remove("grades.txt");
            rename("grades_temp.txt", "grades.txt");
            printf("Grades of student has been deleted successfully\n");
        }
        else
        {
            remove("grades_temp.txt");
            printf("Grades of student couldn't be deleted\n");
        }
    }
}

void view_grades()
{
    FILE *fptr;
    fptr = fopen("grades.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening files!\n");
        if (fptr) fclose(fptr);
        return;
    }
    char enter_studentid[10];
    struct grades g;
    int choice;
    printf("Perform any action\n");
    printf("1. Show Grades of a particular Student\n");
    printf("2. SHow all students Grades\n");
    printf("3. Exit\n");
    printf("What do you want: ");
    scanf("%d", &choice);
    int inside = 0;

    switch (choice)
    {
    case 1:

        printf("Enter Student ID: ");
        scanf("%s", enter_studentid);

        while (fscanf(fptr, "%s %f %s", g.student_id, &g.gradepoint, g.grade) == 3)
        {
            if (strcmp(enter_studentid, g.student_id) == 0)
            {
                printf("Student ID: %s\n", g.student_id);
                printf("Student GPA: %.2f\n", g.gradepoint);
                printf("Student Grade: %2s\n", g.grade);
                inside = 1;
            }
        }
        fclose(fptr);

        if (inside)
        {
            printf("Rewiew data\n");
        }
        else
        {
            printf("Couldn't perform the operation!\n");
        }

        break;

    case 2:
        int i = 0;

        while (fscanf(fptr, "%s %f %s", g.student_id, &g.gradepoint, g.grade) == 3)
        {
            printf("Student no: %d\n", i + 1);
            printf("Student ID: %s\n", g.student_id);
            printf("GPA: %.2f\n", g.gradepoint);
            printf("Grade: %2s\n", g.grade);
            printf("-----------------------\n");
            inside = 1;
            i++;
        }
        fclose(fptr);

        if (inside)
        {
            printf("Rewiew data\n");
        }
        else
        {
            printf("Couldn't perform the operation!\n");
        }

        break;

    case 3:
        break;
    default:
        break;
    }
}

void adminmainMenu()
{

    printf("\n******Welcome As Admin******\n");
    printf("Student Management System\n");
    printf("1. Manage Students\n");
    printf("2. Manage Courses\n");
    printf("3. Manage Assignment\n");
    printf("4. Manage Grades\n");
    printf("5. Manage Enrollments\n");
    printf("6 Logout\n");
}

void ManageSudents()
{
    // system("cls");
    int choice;
    printf("Student Managing Section\n");
    printf("1. Add Students\n");
    printf("2. Delete Students\n");
    printf("3. Edit Student Information\n");
    printf("4. Veiw Student Record\n");
    printf("5. Back\n");
    printf("Ente your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add_student();
        break;

    case 2:
        delete_student();
        break;

    case 3:
        // system("cls");
        Update_student();
        break;

    case 4:
        show_student_data();
        break;

    case 5:
        break;
    default:
        break;
    }
}

void Courses_Menu()
{
    // system("cls");
    int choice;
    printf("COuse Management Section\n");
    printf("1. Add Courses\n");
    printf("2. Delete Courses\n");
    printf("3. Edit COurse ID\n");
    printf("4. View Courses\n");
    printf("5. Back\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add_course();
        printf("\nEnter any key to continue..........");
        getchar();
        break;
    case 2:
        delete_course();
        printf("\nEnter any key to continue..........");
        getchar();
        break;

    case 3:
        update_courses();
        printf("\nEnter any key to continue..........");
        getchar();
        break;

    case 4:
        view_courses();
        printf("\nEnter any key to continue..........");
        getchar();
        break;

    case 5:
        break;
    default:
        break;
    }
}

void Assignment_Menu()
{
    // system("cls");
    int choice;
    printf("Assignment Management Section\n");
    printf("1. Add Assignment\n");
    printf("2. Delete Assignment\n");
    printf("3. View Assignment\n");
    printf("4. View Submissions\n");
    printf("5. Back\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add_assignment();
        printf("\nEnter any key to continue..........");
        getchar();
        break;
    case 2:
        remove_Assignment();
        printf("\nEnter any key to continue..........");
        getchar();
        break;

    case 3:
        view_assignment();
        printf("\nEnter any key to continue..........");
        getchar();
        break;

    case 4:
        view_submissions();
        printf("\nEnter any key to continue..........");
        getchar();
        break;

    case 5:
        break;
    default:
        break;
    }
}

void Manage_Grades()
{
    // system("cls");
    int choice;
    printf("Grades Management Section\n");
    printf("1. Add Student Grade\n");
    printf("2. Delete Student Grade\n");
    printf("3. View Grades\n");
    printf("4. Back\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        Add_grades();
        printf("\nEnter any key to continue..........");
        getchar();
        break;
    case 2:
        Delete_grade();
        printf("\nEnter any key to continue..........");
        getchar();
        break;

    case 3:
        view_grades();
        printf("\nEnter any key to continue..........");
        getchar();
        break;

    case 4:
        printf("\nEnter any key to continue..........");
        getchar();
        break;

    default:
        break;
    }
}

void Manage_Enrollments()
{
    // system("cls");
    int choice;
    printf("Student Enrollment Section\n");
    printf("1. Add Student Enrollement\n");
    printf("2. Remove Enrollement\n");
    printf("3. View Enrollement\n");
    printf("4. Back\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        new_enrollments();
        printf("\nEnter any key to continue..........");
        getchar();
        break;
    case 2:
        remove_enrollments();
        printf("\nEnter any key to continue..........");
        getchar();
        break;

    case 3:
        view_enrollments();
        printf("\nEnter any key to continue..........");
        getchar();
        break;

    case 4:
        break;

    default:
        break;
    }
}
