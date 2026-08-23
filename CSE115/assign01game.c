#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int target = 73;     
    int guess;
    int attempts = 5;
    int won = 0;
    int diff;

    printf("Guess the number (1-100). You have %d attempts.\n", attempts);

    for (int i = 1; i <= attempts; i++) {
        printf("Attempt %d: ", i);

        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');  
            i--;                        
            continue;
        }

        if (guess == target) {
            printf("Correct! You won in %d attempts.\n", i);
            won = 1;
            break;
        }

        if (guess > target) {
            printf("Too high.");
        } else {
            printf("Too low.");
        }

        diff = abs(guess - target);
        if (diff <= 10) {
            printf(" (Warmer)\n\n");
        } else {
            printf(" (Colder)\n\n");
        }
    }

    if (!won) {
        printf("Game Over! You've used all %d attempts. The number was %d.\n", attempts, target);
    }

    return 0;
}