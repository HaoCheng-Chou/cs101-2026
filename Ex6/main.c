#include <stdio.h>
#include <stdlib.h>

typedef struct employee {
    int id;
    char name[100];
    int age;
    double salary;
} employee_t;

void emp_info(employee_t emp)
{
    printf("employee id = %d\n", emp.id);
    printf("employee name = %s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %f\n\n", emp.salary);
}

int emp_aveage_age(employee_t emp[], int n)
{
    int sum = 0;

    if (n <= 0) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        sum += emp[i].age;
    }

    return sum / n;
}

void emp_writefile(employee_t emp[], int n)
{
    FILE *file = fopen("employee.bin", "wb");

    if (file == NULL) {
        perror("Cannot open employee.bin for writing");
        exit(EXIT_FAILURE);
    }

    if (fwrite(emp, sizeof(employee_t), n, file) != (size_t)n) {
        perror("Cannot write employee.bin");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

void emp_readfile(employee_t emp[], int n)
{
    FILE *file = fopen("employee.bin", "rb");

    if (file == NULL) {
        perror("Cannot open employee.bin for reading");
        exit(EXIT_FAILURE);
    }

    if (fread(emp, sizeof(employee_t), n, file) != (size_t)n) {
        fprintf(stderr, "Cannot read all employee records\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

int main(void)
{
    employee_t emp[3] = {
        {1, "IU", 20, 30000.0},
        {2, "taylor", 26, 36000.0},
        {3, "swift", 31, 90000.0}
    };

    employee_t read_emp[3];

    emp_writefile(emp, 3);
    emp_readfile(read_emp, 3);

    for (int i = 0; i < 3; i++) {
        emp_info(read_emp[i]);
    }

    return 0;
}
