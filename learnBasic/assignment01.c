#include <stdio.h>
#include <string.h>
#include<ctype.h>

// Define the structure for an Employee
struct Employee {
    char Emp_name[50];
    int Emp_id;
    char Emp_Position[50];
};

// Define the structure for a Company
struct Company {
    char Comp_name[50];
    char Comp_code[20];
    struct Employee employees[3]; 
};

int main() {
    //1. str1 = "Hello", str2 = "Mr. Bob", str3 = "Mr. Rock". Now, concatenate the 3 strings into one string and print as "Hello, Mr. Bob. Hello, Mr. Rock."
    // String concatenation
    printf("String Concatenation\n");
    char str1[] = "Hello";
    char str2[] = "Mr.Bob";
    char str3[] = "Mr.Rock";
    char result[200];
    
    sprintf(result, "%s, %s. %s, %s.", str1, str2, str1, str3);
    printf("%s\n\n", result);
    //2. From the above string, convert all the upper case into lower case
    // Convert to lowercase
    printf("Convert to Lowercase\n");
    char lowercase[200];
    strcpy(lowercase, result);
    
    for(int i = 0; lowercase[i]; i++) {
        lowercase[i] = tolower(lowercase[i]);
    }
    printf("%s\n\n", lowercase);
    //3. Define a company and employee structure and accommodate at least 3 employees for each company.
    // Initialize data
    struct Company companyData[2] = {
        {
            "CyberWorld", "CyW0010",
            {
                {"Khalid Arafat",1013, "Software Engineer"},
                {"Abir Hossain",2703, "Project Manager"},
                {"Touhid Islam",2208, "UX Designer"}
            }
        },
        {
            "North South solutions ltd", "NSSl1106",
            {
                {"Kowshik Kundu",1001, "Data Scientist"},
                {"Tahsin Abrar",2032, "Marketing Analyst"},
                {"Saad Rokon",3033, "Sales Representator"}
            }
        }
    };

    // Print  structured information
    printf("Company and Employee Structure Details\n\n");
    for (int i = 0; i < 2; i++) {
        printf("Company Name: %s, Company Code: %s", companyData[i].Comp_name, companyData[i].Comp_code);
        printf("\n\n");
        printf(" Employee Details:\n");
        for (int j = 0; j < 3; j++) {
            // Accessing nested structure members using the dot operator
            printf(" Name: %s, ID: %d, Position: %s\n",
                   companyData[i].employees[j].Emp_name,
                   companyData[i].employees[j].Emp_id,
                   companyData[i].employees[j].Emp_Position);
        }
        printf("\n");
    }

    return 0;
}