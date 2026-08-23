#include <stdio.h>

int main(void) {
    int n;

    printf("Enter N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: N must be a positive integer.\n");
        return 0;
    }

    int totalSum = 0;

    for (int i = 1; i <= n; i++) {
        int termSum = 0;

        for (int j = 1; j <= i; j++) {
            termSum += j;
        }

        printf("Term %d sum: %d\n", i, termSum);
        totalSum += termSum;
    }

    printf("Total Series Sum: %d\n", totalSum);

    return 0;
}