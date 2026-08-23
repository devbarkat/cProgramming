#include <stdio.h>

int main() {
    int n, i, target, count = 0;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target value
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Search for the target and count occurrences
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++;
        }
    }

    // Display the result
    if (count > 0) {
        printf("%d was found %d time(s).\n", target, count);
    } else {
        printf("%d is not in the array.\n", target);
    }

    return 0;
}