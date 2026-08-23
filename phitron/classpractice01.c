#include<stdio.h>
int main() {

    /*char name[10];
    char department[10];
    int number;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your department: ");
    scanf("%s", department);

    printf("Enter your favourite number: ");
    scanf("%d", &number);


    printf("Hello %s from %s !\n", name, department);
    printf("Your favourite number is %d, which is awesome", number);*/

    int len;
    int wid;
    int area=0;
    
    scanf("%d", &len);
    scanf("%d", &wid);

    area = len*wid;

    printf("Area = %d", area);



return 0;
}
