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

