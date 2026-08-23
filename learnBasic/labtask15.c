#include <stdio.h>

void areaPeri(int *r) {
    if (r == NULL) return;
    int radius = *r;
    if (radius < 0) {
        printf("Radius must be non-negative.\n");
        return;
    }
    const double pi = 3.141592653589793;
    double area = pi * radius * radius;
    double perimeter = 2.0 * pi * radius;
    printf("Radius: %d\n", radius);
    printf("Area: %.6f\n", area);
    printf("Perimeter (Circumference): %.6f\n", perimeter);
}

int main(void) {
    int r;
    printf("Enter radius (integer): ");
    if (scanf("%d", &r) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    areaPeri(&r);
    return 0;
}