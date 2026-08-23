#include <stdio.h>

#define MAX_SIZE 20

int main(void) {
    float arr[MAX_SIZE];
    float normalized[MAX_SIZE];
    int n;
    float min, max;

    printf("Enter N: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Error: N must be between 1 and %d.\n", MAX_SIZE);
        return 0;
    }

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);

        if (arr[i] < 0) {
        printf("Error: Only positive numbers are allowed.\n");
            return 0;
        }
    }

    min = arr[0];
    max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Min: %.2f, Max: %.2f\n", min, max);

    for (int i = 0; i < n; i++) {
        if (max - min == 0) {
            normalized[i] = 0.0f;  
        } else {
            normalized[i] = (arr[i] - min) / (max - min);
        }
    }

    printf("Original: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    
    printf("Normalized: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", normalized[i]);
    }
    printf("\n");

    return 0;
}