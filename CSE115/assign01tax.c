#include <stdio.h>

int main() {
    double income;
    double bracket1 = 0.0, bracket2 = 0.0, bracket3 = 0.0, bracket4 = 0.0;
    double totalTax, effectiveRate;

    printf("Enter your annual income: ");
    scanf("%lf", &income);

    if (income <= 0) {
        printf("Income must be greater than 0.\n");
        return 0;
    }

    bracket1 = 0.0;

    if (income > 10000) {
        if (income <= 30000)
            bracket2 = (income - 10000) * 0.10;
        else
            bracket2 = 20000 * 0.10;
    } else {
        bracket2 = 0.0;
    }

    if (income > 30000) {
        if (income <= 70000)
            bracket3 = (income - 30000) * 0.20;
        else
            bracket3 = 40000 * 0.20;
    } else {
        bracket3 = 0.0;
    }

    if (income > 70000) {
        bracket4 = (income - 70000) * 0.30;
    } else {
        bracket4 = 0.0;
    }

    totalTax = bracket1 + bracket2 + bracket3 + bracket4;
    effectiveRate = (totalTax / income) * 100;

    printf("Tax Breakdown:\n");
    printf("Bracket 1 (0%%): $%.2f\n", bracket1);
    printf("Bracket 2 (10%%): $%.2f\n", bracket2);
    printf("Bracket 3 (20%%): $%.2f\n", bracket3);
    printf("Bracket 4 (30%%): $%.2f\n\n", bracket4);
    printf("Total Tax Owed: $%.2f\n", totalTax);
    printf("Effective Tax Rate: %.2f%%\n", effectiveRate);

    return 0;
}