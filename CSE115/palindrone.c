#include<stdio.h>
#include<strings.h>

#define Max 100

int main(void){

char s[Max];
char rev[Max];

printf("Enter a String: ");
fgets(s, sizeof(s), stdin);
s[strcspn(s,"\n")] = '\0';

strcpy(rev,s);
int n = strlen(rev);
for(int i = 0; i< n/2; i++){
    char temp = rev[i];
    rev[i] = rev[n - 1 - i];
    rev[n - 1 - i] = temp;
} 
printf("Reversed : %s\n", rev);

if(strcmp(s, rev)== 0)printf("%s is Palindrome", rev);
else printf("\"%s\" is not Palindrome", rev);

return 0;
}