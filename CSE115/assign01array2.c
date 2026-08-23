#include <stdio.h>

#define MAX_SIZE 100

int main(void) {
    int A[MAX_SIZE], B[MAX_SIZE];
    int n, m;

    printf("Enter size of Array A: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
    printf("Error: Size of A must be between 1 and %d.\n", MAX_SIZE);
        return 0;
    }

    printf("Enter elements of A: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter size of Array B: ");
    scanf("%d", &m);

    if (m <= 0 || m > MAX_SIZE) {
    printf("Error: Size of B must be between 1 and %d.\n", MAX_SIZE);
        return 0;
    }

    printf("Enter elements of B: ");
    for (int j = 0; j < m; j++) {
        scanf("%d", &B[j]);
    }

    printf("Intersection: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                printf("%d ", A[i]);
                break;  
            }
        }
    }
    printf("\n");

    return 0;
}