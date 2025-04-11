#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void addEmployee(Employee employees[], int *count) {
    if (*count < MAX_EMPLOYEES) {
        printf("Enter Employee ID: ");
        scanf("%d", &employees[*count].id);

        // Clear newline left by scanf
        getchar();

        printf("Enter Employee Name: ");
        fgets(employees[*count].name, sizeof(employees[*count].name), stdin);

        // Remove trailing newline from fgets
        employees[*count].name[strcspn(employees[*count].name, "\n")] = '\0';

        printf("Enter Employee Salary: ");
        scanf("%f", &employees[*count].salary);

        (*count)++;
        printf("Employee added successfully!\n");
    } else {
        printf("Database is full!\n");
    }
}

void displayEmployees(Employee employees[], int count) {
    if (count == 0) {
        printf("No employees in the database.\n");
        return;
    }

    printf("\nEmployee Database:\n");
    printf("----------------------------------------\n");
    printf("%-5s %-20s %-10s\n", "ID", "Name", "Salary");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-10.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].salary);
    }

    printf("----------------------------------------\n");
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    do {
        printf("\nEmployee Database Menu:\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &employeeCount);
                break;
            case 2:
                displayEmployees(employees, employeeCount);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}
