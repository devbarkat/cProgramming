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

    int insertPos = 0;  

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            int temp = arr[i];

            int j = i;
            while (j > insertPos) {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[insertPos] = temp;
            insertPos++;
        }
    }

    printf("Segregated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}