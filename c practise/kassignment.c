#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
} Job;

typedef struct {
    char name[50];
    char capital[50];
    int numberOfJobs;
    Job jobIDs[10];
} Country;

int main() {
    
    Country countries[2]; 

    strcpy(countries[0].name, "Bangladesh");
    strcpy(countries[0].capital, "Dhaka");
    countries[0].numberOfJobs = 2;
    countries[0].jobIDs[0].id = 101;
    countries[0].jobIDs[1].id = 102;

    strcpy(countries[1].name, "Thailand");
    strcpy(countries[1].capital, "Bankok");
    countries[1].numberOfJobs = 1;
    countries[1].jobIDs[0].id = 201;


    for (int i = 0; i < 2; i++) {
        printf("Country: %s\n", countries[i].name);
        printf("Capital: %s\n", countries[i].capital);
        printf("Number of Jobs: %d\n", countries[i].numberOfJobs);
        printf("Job IDs: ");
        for (int j = 0; j < countries[i].numberOfJobs; j++) {
            printf("%d ", countries[i].jobIDs[j].id);
        }
        printf("\n\n");
    }

    return 0;
}