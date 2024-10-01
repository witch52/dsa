#include<stdio.h>
void rev(char st[],int a){
    printf("After reversing \n");
    int len=0;
    while(st[len]!='\0'){
        len++;
    }
    for(int i=len-1;i>=0;i--){
        
        printf("%c",st[i]);}
    
}
void main(){
    int a;
    printf("Enter the number of characters in string array \n");
    scanf("%d",&a);
    char st[a+1];
    printf("Enter the string ");
    scanf("%s",st);
    printf("before reversing %s \n",st);
    rev(st,a);
}