
#include<stdio.h>
int main(){

    int days , months, weeks, years;
    printf("Enter Days :");
    

scanf("%d", &days);

    years = days/365;
    months = (days%365)/30;
    weeks = (days%365)/7;
    days = days - ((years*365)+(months*30)+(weeks*7));

    printf("%d/n", years);
    printf("%d/n", months);
    printf("%d/n", weeks);
    printf("%d", days);

    return 0;
}

    