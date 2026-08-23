
#include<stdio.h>
int main(){

    int row,col, i, j;
    
    printf("enter row number \n");
    scanf("%d",&row);
    
    printf("enter colum number: \n");
    scanf("%d", &col);
    printf("\n");

    int arr[row][col];
    for( i=0; i<row; i++ ){
        for( j=1; j<=col; j++){
            scanf("%d", &arr[i][j]);
        }
    }for( i=0; i<row; i++ ){
        for( j=1; j<=col; j++){
        printf("%d", arr[i][j]);
        }printf("\n");
    }
    
    

    return 0;
}
