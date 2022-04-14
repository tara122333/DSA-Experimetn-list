#include<stdio.h>
void tower(int,char,char,char);
int main()
{ 
    int n;
    printf("Enter no of term : ");
    scanf("%d",&n);
    tower(n,'A','C','B');
    return 0;
}
void tower(int n,char from ,char to ,char temp){
    if(n>0){
        tower(n-1,from,temp,to);
        printf(" Move Disk %d from %c to %c \n",n,from,to);
        tower(n-1,temp,to,from);
    }
}