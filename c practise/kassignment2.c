#include <stdio.h>
#include <string.h>

struct Country {
    char name[50];          
    char capital[50];       
    int num_jobs;           
    int job_ids[10];  
};

int main() {
    struct Country countries[2] = {
        {"Bangladesh", "Dhaka", 5, {1001, 1002, 1003,1004, 1005}},
        {"Thailamd", "Bangkok", 5, {2001, 2002, 2003,2004,2005}},
    };

    int i, j;

    for (i = 0; i <2; i++) {
        printf("\nCountry: %s\n", countries[i].name);
        printf("Capital: %s\n", countries[i].capital);
        printf("Number of jobs: %d\n", countries[i].num_jobs);
        printf("Job IDs: ");

        for (j = 0; j < countries[i].num_jobs; j++) {
            printf("%d", countries[i].job_ids[j]);
            if (j < countries[i].num_jobs ) {
                printf(", ");
            }
        }
        printf("\n");
    }

    return 0;
}