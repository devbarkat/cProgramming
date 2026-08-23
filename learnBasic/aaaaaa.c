#include<stdio.h>

struct date{
    int day, mon, year;
};

int date_cmp(struct date d1, struct date d2)
 {
    if (d1.year < d2.year) return -1;
    if (d1.year > d2.year) return 1;
    if (d1.mon < d2.mon) return -1;
    if (d1.mon > d2.mon) return 1;
    if (d1.day < d2.day) return -1;
    if (d1.day > d2.day) return 1;
    return 0;
}


void date_print(struct date d)
{
    printf("%02d/%02d/%04d", d.day, d.mon, d.year);
}

int main(){

    struct date d1 = { 07, 02, 2022};
    struct date d2 = { 12, 05, 2022};

    int cmp = date_cmp(d1,d2);
    date_print(d1);
    if(cmp==0)
        printf(" equal to");
    else if(cmp>0)
        printf("Grater than");
     else printf("smaller than");

    date_print(d2);

    return 0;

}
