#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(){

    int n;
    scanf("%d", &n);

    int num;
    int pos_sum=0;
    int neg_sum=0;
    for(int i=0; i<n; i++){
        scanf("%d", &num);

        if(num>0){
            pos_sum = pos_sum + num;
        }if(num<0){
            neg_sum= neg_sum + num; 
        }
    }    
    printf("%d %d", pos_sum,neg_sum);


    return 0;
}