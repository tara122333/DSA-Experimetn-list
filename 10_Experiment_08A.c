#include <stdio.h>

void readData(int arr[]);
void display(int arr[]);
int *addArray(int A[],int B[],int C[]);

int main()
{
    int a[500], b[500], c[1003];
    int x, y;
    printf("Enter no of term  : ");
    scanf("%d", &x);
    a[0] = x;
    readData(a);
    display(a);
    printf("Enter no of term : ");
    scanf("%d",&y);
    b[0]=y;
    readData(b);
    display(b);
    addArray(a,b,c);
    display(c);
    return 0;
}

void readData(int arr[])
{
    int t = (2*arr[0]);
    for (int i = 1; i <=t; i++)
    {
        if(i%2==1){
            printf("Enter coefficient : ");
            scanf("%d",&arr[i]);
        }
        else{
            printf("Enter exponential : ");
            scanf("%d",&arr[i]);
        }

    }
    printf("\n");
}

void display(int arr[])
{
    int t = 2*arr[0];
    int i;
    for (i=1;i<=t-2;i++)
    {
        if((arr[i]== 0) && i%2 == 1)
        {
            // printf("X^%d+", arr[i++]);
            continue;
        }
        else if((arr[i]== 0) && i%2 == 0)
        {
            printf("%d+",arr[i-1]);
        }

        else if (arr[i] == 1 && i%2==1)
        {
            printf("X^%d+", arr[i+1]);
            i++;
        }
        else if (arr[i] == 1 && i%2==0)
        {
            printf("%dX+", arr[i-1]);
        }

        else
        {
            printf("%dX^%d+", arr[i], arr[i+1]);
            i++;
        }
        if(i%2==1){
            if(arr[i]==0){
                i++;
            }
            else if(arr[i]==1){
               printf(""); 
            }
            else{
                printf("%d",arr[i]);
            }
        }
        else{
            if(arr[i]==0){
                printf("+");
            }
            else if(arr[i]==1){
                printf("X+");
            }
            else{
                printf("X^%d+",arr[i]);
            }
        }
    }
    if (arr[i] == 0)
    {
        i--;
    }
    else if (arr[i] == 1)
    {
        printf("X+");
        i--;
    }

    else
    {
        printf("%dX+", arr[i]);
    }
    printf("%d\n\n", arr[i]);
    if(i%2==1){
            if(arr[i]==0){
                i++;
            }
            else if(arr[i]==1){
               printf(""); 
            }
            else{
                printf("%d",arr[i]);
            }
        }
        else{
            if(arr[i]==0){
                printf("");
            }
            else if(arr[i]==1){
                printf("X");
            }
            else{
                printf("X^%d",arr[i]);
            }
        }
        i++;
    if(i%2==1){
            if(arr[i]==0){
                i++;
            }
            else if(arr[i]==1){
               printf(""); 
            }
            else{
                printf("%d",arr[i]);
            }
        }
        else{
            if(arr[i]==0){
                printf("");
            }
            else if(arr[i]==1){
                printf("X");
            }
            else{
                printf("X^%d",arr[i]);
            }
        }
        printf("\n");
}

int *addArray(int A[],int B[],int C[]){
    int m,n;
    int p,q,r;
    m = A[0];
    n = B[0];
    p = 2;
    q = 2;
    r = 2;
    while(p<=2*m && q<=2*n)
    {
        if(A[p]==B[q]){
            C[r-1] = A[p-1] + B[q-1];
            if(C[r-1]!=0){
                C[r]=A[p];
                r = r+2;
            }
            p = p+2;
            q = q+2;
        }
        else if(A[p]<B[q]){
            C[r-1] = B[q-1];
            C[r] = B[q];
            q = q+2;
            r = r+2;
        }
        else{
            C[r-1] = A[p-1];
            C[r] = A[p];
            p = p+2;
            r = r+2;
        }
    }
    while (p<=2*m)
    {
        C[r] = A[p];
        C[r-1] = A[p-1];
        p = p+2;
        r = r+2;
    }
    while (q<=2*n)
    {
        C[r] = B[q];
        C[r-1] = B[q-1];
        q = q+2;
        r = r+2;

    }
    C[0] = (r/2)-1;
    return C;
}