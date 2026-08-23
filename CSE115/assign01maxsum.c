#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, k;

    printf("Enter N: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Error: N must be between 1 and %d.\n", MAX_SIZE);
        return 0;
    }

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter K: ");
    scanf("%d", &k);

    if (k <= 0 || k >= n) {
        printf("Error: K must be less than N and greater than 0.\n");
        return 0;
    }

    int maxSum = 0;
    int maxStart = 0;

    for (int i = 0; i < k; i++) {
        maxSum += arr[i];
    }

    for (int i = 1; i <= n - k; i++) {
        int currentSum = 0;

        for (int j = i; j < i + k; j++) {
            currentSum += arr[j];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxStart = i;
        }
    }

    printf("Max sum of %d contiguous elements is: %d (Elements: ", k, maxSum);
    for (int i = maxStart; i < maxStart + k; i++) {
        printf("%d", arr[i]);
        if (i < maxStart + k - 1) {
            printf(", ");
        }
    }
    printf(")\n");

    return 0;
}