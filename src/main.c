#include <stdio.h>
#include "student.h"
#include "admin.h"

int main() {
    int choice;

    printf("1. Login as Student\n");
    printf("2. Login as Admin\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        studentMenu();
    } else if (choice == 2) {
        adminMenu();
    }

    return 0;
}
