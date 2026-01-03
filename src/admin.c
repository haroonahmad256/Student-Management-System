// Ayesha's Section
// Here you will write functions like example given
// and don't create a main function in it
// Aur function prototype .h file me likein uper ki do lines aur end wali line k middle me
#include <stdio.h>
#include <string.h>

struct students {
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
    char student_ID[10];
    char course_ID[10];
};

struct assignments
{
    char Course_id[10];
    char Assignment_id[10];
    char Assignment_name[50];
    char deadline[20];
};



void adminMenu()
{
    printf("1. Manage Students");
    printf("2. Manage Courses");
    printf("3. Manage Assignment");
    printf("4. Manage Grades");
    printf("5. Logout");
}

void Login_admin()
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
            printf("Error opening file");
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

                if (strcmp(enter_adminid, admin.admin_id) == 0 && strcmp(enter_password, enter_adminid) == 0)
                {
                    on = 1;
                }
            }

            if (on)
            {
                printf("Login successful\n");
                i = 0;
            }

            else
            {
                printf("Invaid admin id or password\n");
                break;
            }

            fclose(fptr);

        } while (i);

        break;

    case 2:

        rewind(fptr);
        FILE *fptr2;
        fptr = fopen("admin_login.txt", "r");
        fptr2 = fopen("admin_login_temp.txt", "a");
        char forgotpassword;
        char admin_id[4], new_password[10];
        struct admins admin;

        printf("Forgot password as Admin(y/n): ");
        scanf("%s", forgotpassword);
        int inside = 0;

        if (forgotpassword == 'y' || forgotpassword == 'Y')
        {
            printf("Enter your Admin ID to verify: ");
            scanf("%s", admin_id);

            while (fscanf(fptr, "%s %s", admin.admin_id, admin.admin_password) == 2)
            {

                if (strcmp(admin_id, admin.admin_id) == 0)
                {
                    printf("Enter new password: ");
                    scanf("%s", new_password);
                    fprintf(fptr2, "%s %s", admin.admin_id, new_password);
                    inside = 1;
                }

                else
                {

                    fprintf(fptr2, "%s %s", admin.admin_id, admin.admin_password);
                }
            }

            fclose(fptr2);
            fclose(fptr);

            if (inside)
            {
                remove("admin_login.txt");
                rename("admin_login_temp.txt", "admin_login.txt");
                printf("Your password has been changed successfully");
            }

            else
            {
                remove("admin_login_temp.txt");
                printf("Pssword could not changed");
            }
        }
        break;
    default:
        break;
    }
}

void Logout_admin()
{
}

void add_student()
{

    FILE *fptr;
    fptr = fopen("students.txt", "a");
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
}

void delete_student()
{

    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("students.txt", "r");
    fptr2 = fopen("students_temp.txt", "a");

    if (fptr2== NULL)
    {
        printf("Error opening file");
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

        fclose(fptr2);
        fclose(fptr);

        if (inside)
        {
            remove("students.txt");
            rename("students_temp.txt", "students.txt");
            printf("You account has been deleted successfully\n");
        }
        else
        {
            remove("students_temp.txt");
            printf("Account couldn't be deleted\n");
        }
    }
}

void show_student_data()
{
    FILE *fptr;
    fptr = fopen("students.txt", "r");
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
                printf("Student Name: %s %s\n", student.student_name);
                printf("Department: %s\n", student.department);
                printf("Password: %s\n", student.password);
                inside = 1;
            }
        }

        if (inside)
        {
            printf("Rewiew data\n");
        }
        else
        {
            printf("Couldn't perform the operation!\n");
        }

        fclose(fptr);
        break;

    case 2:
        int i = 0;

        while (fscanf(fptr, "%s %s %s %s", student.student_id, student.student_name, student.password, student.department) == 4)
        {
            printf("Student%d data: \n", i+1);
            printf("Student ID: %s\n", student.student_id);
            printf("Student Name: %s %s\n", student.student_name);
            printf("Department: %s\n", student.department);
            printf("Password: %s\n", student.password);
            printf("\n");
            inside = 1;
            i++;
        }

        if (inside)
        {
            printf("Rewiew data\n");
        }
        else
        {
            printf("Couldn't perform the operation!\n");
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
    fptr2 = fopen("students_temp.txt", "a");
    char forgotpassword;
    char student_id[10], new_name[50];
    struct students student;

    printf("Enter Student ID to change name: ");
    scanf("%s", student_id);

    int inside= 0;
    while (fscanf(fptr, "%s %s %s %s", student.student_id, student.student_name, student.password, student.department) == 4)
    {
        if (strcmp(student_id, student.student_id) == 0)
        {
            printf("Enter new name: ");
            scanf("%s", new_name);
            fprintf(fptr2,  "%s %s %s %s\n", student.student_id, new_name, student.password, student.department);
            inside = 1;
        }

        else
        {

            fprintf(fptr2,  "%s %s %s %s\n", student.student_id, student.student_name, student.password, student.department);
        }
    }

    fclose(fptr2);
    fclose(fptr);

    if (inside)
    {
        remove("students.txt");
        rename("students_temp.txt", "students.txt");
        printf("Your Student Name has been changed successfully");
    }

    else
    {
        remove("students_temp.txt");
        printf("Student Name could not changed");
    }
}

void change_student_ID(){

    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("students.txt", "r");
    fptr2 = fopen("students_temp.txt", "a");
    char forgotpassword;
    char student_id[10], new_ID[20];
    struct students student;

    printf("Enter Student ID to change ID: ");
    scanf("%s", student_id);

    int inside= 0;
    while (fscanf(fptr, "%s %s %s %s", student.student_id, student.student_name, student.password, student.department) == 4)
    {
        if (strcmp(student_id, student.student_id) == 0)
        {
            printf("Enter new ID: ");
            scanf("%s", new_ID);
            fprintf(fptr2,  "%s %s %s %s\n", new_ID, student.student_name, student.password, student.department);
            inside = 1;
        }

        else
        {

            fprintf(fptr2,  "%s %s %s %s\n", student.student_id, student.student_name, student.password, student.department);
        }
    }

    fclose(fptr2);
    fclose(fptr);

    if (inside)
    {
        remove("students.txt");
        rename("students_temp.txt", "students.txt");
        printf("Your Student ID has been changed successfully");
    }

    else
    {
        remove("students_temp.txt");
        printf("Student ID could not changed");
    }

}

void change_student_password(){

    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("students.txt", "r");
    fptr2 = fopen("students_temp.txt", "a");
    char forgotpassword;
    char student_id[10], new_Password[20];
    struct students student;

    printf("Enter Student ID to change Password: ");
    scanf("%s", student_id);

    int inside= 0;
    while (fscanf(fptr, "%s %s %s %s", student.student_id, student.student_name, student.password, student.department) == 4)
    {
        if (strcmp(student_id, student.student_id) == 0)
        {
            printf("Enter new ID: ");
            scanf("%s", new_Password);
            fprintf(fptr2,  "%s %s %s %s\n", student.student_id, student.student_name, new_Password, student.department);
            inside = 1;
        }

        else
        {

            fprintf(fptr2,  "%s %s %s %s\n", student.student_id, student.student_name, student.password, student.department);
        }
    }

    fclose(fptr2);
    fclose(fptr);

    if (inside)
    {
        remove("students.txt");
        rename("students_temp.txt", "students.txt");
        printf("Your Student Account Password has been changed successfully");
    }

    else
    {
        remove("students_temp.txt");
        printf("Student Account Password could not changed");
    }

}

void change_student_Department(){

    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("students.txt", "r");
    fptr2 = fopen("students_temp.txt", "a");
    char forgotpassword;
    char student_id[10], new_Department[20];
    struct students student;

    printf("Enter Student ID to change Department: ");
    scanf("%s", student_id);

    int inside= 0;
    while (fscanf(fptr, "%s %s %s %s", student.student_id, student.student_name, student.password, student.department) == 4)
    {
        if (strcmp(student_id, student.student_id) == 0)
        {
            printf("Enter new ID: ");
            scanf("%s", new_Department);
            fprintf(fptr2,  "%s %s %s %s\n", student.student_id, student.student_name, student.password, new_Department);
            inside = 1;
        }

        else
        {

            fprintf(fptr2,  "%s %s %s %s\n", student.student_id, student.student_name, student.password, student.department);
        }
    }

    fclose(fptr2);
    fclose(fptr);

    if (inside)
    {
        remove("students.txt");
        rename("students_temp.txt", "students.txt");
        printf("Your Student Department has been changed successfully");
    }

    else
    {
        remove("students_temp.txt");
        printf("Student Department could not changed");
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
    struct courses course;
    printf("Enter New course ID: ");
    scanf("%s", course.course_id);
    printf("Enter Course Name: ");
    scanf("%s", course.course_name);
    printf("Enter Course Credit Hours: ");
    scanf("%d", &course.creadit_hours);

    fprintf(fptr, "%s %s %d\n", course.course_id, course.course_name, course.creadit_hours);

}

void delete_course()
{
    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("courses.txt", "r");
    fptr2 = fopen("courses_temp.txt", "a");
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

                fprintf(fptr2, "%s %s %d", course.course_id, course.course_name, course.creadit_hours);
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

        if (inside)
        {
            printf("Rewiew data\n");
        }
        else
        {
            printf("Couldn't perform the operation!\n");
        }

        fclose(fptr);
        break;

    case 2:
        int i = 0;

        while (fscanf(fptr, "%s %s %d", course.course_id, course.course_name, &course.creadit_hours) == 3)
        {
            printf("Course no: %d\n", i+1);
            printf("Course ID: %s\n", course.course_id);
            printf("Course Name: %s\n", course.course_name);
            printf("Credit Hourse: %d\n", course.creadit_hours);
            printf("-----------------------\n");
            inside = 1;
            i++;
        }

        if (inside)
        {
            printf("Rewiew data\n");
        }
        else
        {
            printf("Couldn't perform the operation!\n");
        }

        fclose(fptr);

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
    fptr2 = fopen("courses_temp.txt", "a");

    char course_id[10], new_ID[20];
    struct courses course;

    printf("Enter Student ID to change ID: ");
    scanf("%s", course_id);

    int inside= 0;
    while (fscanf(fptr, "%s %s %d", course.course_id, course.course_name, &course.creadit_hours) == 3)
    {
        if (strcmp(course_id, course.course_id) == 0)
        {
            printf("Enter new ID: ");
            scanf("%s", new_ID);
            fprintf(fptr2,  "%s %s %s %s\n", new_ID, course.course_name, course.creadit_hours);
            inside = 1;
        }

        else
        {

            fprintf(fptr2,  "%s %s %s %s\n", course.course_id, course.course_name, course.creadit_hours);
        }
    }

    fclose(fptr2);
    fclose(fptr);

    if (inside)
    {
        remove("courses.txt");
        rename("courses_temp.txt", "courses.txt");
        printf("Your Student ID has been changed successfully");
    }

    else
    {
        remove("courses_temp.txt");
        printf("Student ID could not changed");
    }

}

void new_enrollments(){

    FILE *fptr;
    fptr = fopen("enrollments.txt", "a");
    struct enrollments enroll;
    printf("Enter Student ID: ");
    scanf("%s", enroll.student_ID);
    printf("Enter Course ID: ");
    scanf("%s", enroll.course_ID);
    fprintf(fptr, "%s %s\n", enroll.student_ID, enroll.student_ID);

}

void view_enrollments(){
    
    FILE *fptr;
    fptr = fopen("enrollments.txt", "r");
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

        int j=0;
        printf("Enter Course ID: ");
        scanf("%s", enter_courseid);

        while (fscanf(fptr, "%s %s", enroll.student_ID, enroll.student_ID) == 2)
        {
            if (strcmp(enter_courseid, enroll.course_ID) == 0)
            {
                printf("Course No: %d\n", j+1);
                printf("Course ID: %s | Course Name: %s", enroll.course_ID, enroll.student_ID);
                printf("\n");
                inside = 1;
                j++;
            }
        }

        if (inside)
        {
            printf("Rewiew data\n");
        }
        else
        {
            printf("Couldn't perform the operation!\n");
        }

        fclose(fptr);
        break;

    case 2:
        int i = 0;

        while (fscanf(fptr, "%s %s", enroll.student_ID, enroll.student_ID) == 2)
        {
            printf("Course no: %d\n", i+1);
            printf("Course ID: %s | Course Name: %s", enroll.course_ID, enroll.student_ID);
            printf("-----------------------\n");
            inside = 1;
            i++;
        }

        if (inside)
        {
            printf("Rewiew data\n");
        }
        else
        {
            printf("Couldn't perform the operation!\n");
        }

        fclose(fptr);

        break;

    case 3:
        break;
    default:
        break;
    }


}

void remove_enrollments(){

    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("enrollments.txt", "r");
    fptr2 = fopen("enrollments_temp.txt", "a");
    
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
        while (fscanf(fptr, "%s %s", enroll.student_ID, enroll.student_ID) == 3)
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
            remove("courses.txt");
            rename("enrollments_temp.txt", "enrollments.txt");
            printf("Course has been deleted successfully\n");
        }
        else
        {
            remove("enrollments_temp.txt");
            printf("Course couldn't be deleted\n");
        }
    }


}

void add_assignment(){

    FILE *fptr;
    fptr = fopen("assignments.txt", "a");
    struct assignments assignment;
    printf("Enter Course ID: ");
    scanf("%s", assignment.Course_id);
    printf("Enter Assignment ID: ");
    scanf("%s", assignment.Assignment_id);
    printf("Enter Assignment Name: ");
    scanf("%s", assignment.Assignment_name);
    printf("Enter Deadline of assignment: ");
    scanf("%s", assignment.deadline);
    fprintf(fptr, "%s %s %s %s\n", assignment.Course_id, assignment.Assignment_id, assignment.Assignment_name, assignment.deadline);
    
}

void Manage_Assignment()
{


}

void Manage_Grades()
{

}

