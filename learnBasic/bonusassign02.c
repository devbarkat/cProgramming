#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Structure definitions
struct Employee {
    char name[50];
    char code[20];
    char position[50];
};

struct Company {
    char name[100];
    char code[20];
    struct Employee employees[3];
};

int main() {
    // String concatenation
    printf("String Concatenation\n");
    char str1[] = "Hello";
    char str2[] = "Mr. Bob";
    char str3[] = "Mr. Rock";
    char result[200];
    
    sprintf(result, "%s, %s. %s, %s.", str1, str2, str1, str3);
    printf("%s\n\n", result);
    
    // Convert to lowercase
    printf("Convert to Lowercase\n");
    char lowercase[200];
    strcpy(lowercase, result);
    
    for(int i = 0; lowercase[i]; i++) {
        lowercase[i] = tolower(lowercase[i]);
    }
    printf("%s\n\n", lowercase);
    
    // Company and Employee structure
    printf("Company and Employee Structure\n");
    struct Company company;
    
    // Initialize company details
    strcpy(company.name, "NSU Tech Solutions");
    strcpy(company.code, "NSUTSI001");
    
    // Employee 1
    strcpy(company.employees[0].name, "Kowshik Kundu");
    strcpy(company.employees[0].code, "EMP201");
    strcpy(company.employees[0].position, "Software Engineer");
    
    // Employee 2
    strcpy(company.employees[1].name, "Abrar Tahsin");
    strcpy(company.employees[1].code, "EMP402");
    strcpy(company.employees[1].position, "Project Manager");
    
    // Employee 3
    strcpy(company.employees[2].name, "Abir Hossain");
    strcpy(company.employees[2].code, "EMP273");
    strcpy(company.employees[2].position, "Senior Developer");
    
    // Display company and employee information
    printf("Company Name: %s\n", company.name);
    printf("Company Code: %s\n\n", company.code);
    
    for(int i = 0; i < 3; i++) {
        printf("Employee %d:\n", i + 1);
        printf("  Name: %s\n", company.employees[i].name);
        printf("  Code: %s\n", company.employees[i].code);
        printf("  Position: %s\n\n", company.employees[i].position);
    }
    
    return 0;
}