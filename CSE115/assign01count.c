#include <stdio.h>

#define MAX_SIZE 100

int main(void) {
    int arr[MAX_SIZE];
    int n;

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

    printf("Compressed Output:\n");

    int i = 0;
    while (i < n) {
        int current = arr[i];
        int count = 1;

        while (i + count < n && arr[i + count] == current) {
            count++;
        }

        printf("%d of %d\n", count, current);
        i += count;
    }

    return 0;
}