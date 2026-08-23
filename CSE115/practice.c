#include<stdio.h>
#include<string.h>

#define N 3

struct Student {
int id;
char name[30];
float cgpa;
};

int main(void){

struct Student student[N];

for(int i = 0; i < N; i++){
    printf("Student %d\n", i + 1);

    printf(" ID : ");
    scanf("%d", &student[i].id);
    getchar();                                  /* eat the newline */

    printf(" Name : ");
    fgets(student[i].name, sizeof(student[i].name), stdin);
    student[i].name[strcspn(student[i].name, "\n")] = '\0';

    printf(" CGPA : ");
    scanf("%f", &student[i].cgpa);
    }

    printf("\n%-6s %-12s %s\n", "ID", "Name", "CGPA");

    for (int i = 0; i < N; i++) {
        printf("%-6d %-12s %.2f\n",student[i].id, student[i].name, student[i].cgpa);
    }


    int best = 0;
    for (int i = 1; i < N; i++) {
    if (student[i].cgpa > student[best].cgpa) best = i;
    }

    printf("\nTop student: %s (%.2f)\n", student[best].name, student[best].cgpa);
    
    
    return 0;
}