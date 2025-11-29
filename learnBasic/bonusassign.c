
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Structure definitions for task 3
struct Employee {
    int id;
    char name[50];
    float salary;
};

struct Company {
    char companyName[100];
    struct Employee employees[3];
    int empCount;
};

int main() {
    // String concatenation
    char str1[] = "Hello";
    char str2[] = "Mr. Bob";
    char str3[] = "Mr. Rock";
    char result[200];
    
    sprintf(result, "%s, %s. %s, %s.", str1, str2, str1, str3);
    printf("Concatenated String:\n%s\n\n", result);
    
    // Convert to lowercase
    char lowercase[200];
    strcpy(lowercase, result);
    
    for(int i = 0; lowercase[i]; i++) {
        lowercase[i] = tolower(lowercase[i]);
    }
    printf("Lowercase String:\n%s\n\n", lowercase);
    
    // Company and Employee structures
    struct Company company1;
    strcpy(company1.companyName, "NSU Tech Solutions.");
    company1.empCount = 3;
    
    // Employee 1
    company1.employees[0].id = 1001;
    strcpy(company1.employees[0].name, "Kowshik Kundu");
    company1.employees[0].salary = 50000.0;
    
    // Employee 2
    company1.employees[1].id = 1002;
    strcpy(company1.employees[1].name, "Abrar Tahsin");
    company1.employees[1].salary = 65000.0;
    
    // Employee 3
    company1.employees[2].id = 1003;
    strcpy(company1.employees[2].name, "Shahriar Ahmmed");
    company1.employees[2].salary = 72000.0;
    
    printf("Task 3 - Company and Employee Details:\n");
    printf("Company: %s\n", company1.companyName);
    printf("Employees:\n");
    for(int i = 0; i < company1.empCount; i++) {
        printf("  ID: %d, Name: %s, Salary: %.2f\n", 
               company1.employees[i].id,
               company1.employees[i].name,
               company1.employees[i].salary);
    }
    
    return 0;
}