//  sparse matrix 
#include<stdio.h>
#define SIZE 40
void readData(int arr[SIZE][SIZE],int);
void display(int arr[SIZE][SIZE],int);
void transpose(int arr1[SIZE][SIZE],int arr2[SIZE][SIZE]);
int main()
{ 
    int A[SIZE][SIZE]={(0,0)};
    int B[SIZE][SIZE]={(0,0)};
    int C[SIZE][SIZE]={(0,0)};

    int row,col,non_zero;
    printf("Enter No of Row : ");
    scanf("%d",&row);
    printf("Enter No of Column : ");
    scanf("%d",&col);
    printf("Enter non Zero element : ");
    scanf("%d",&non_zero);
    readData(A,non_zero);
    
    int k =1;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(A[i][j]!=0){
                B[k][1] = i;
                B[k][2] = j;
                B[k][3] = A[i][j];
                k++;
            }
        }
    }
    B[0][1] = row;
    B[0][2] = col;
    B[0][3] = non_zero;
    display(B,non_zero);
    printf("\nTranspose of sparse matrix is : \n");
    transpose(B,C);
    display(C,non_zero);
    return 0;
}

void readData(int arr[SIZE][SIZE],int n){
    for (int i=1; i<=n; i++)
    {
       int r,c,val;
       printf("Enter row : ");
       scanf("%d",&r);
       printf("Enter column : ");
       scanf("%d",&c);
       printf("Enter value : ");
       scanf("%d",&val);
       arr[r][c] = val;
    }  
}
void display(int arr[SIZE][SIZE],int n){
    printf("\nRow\tColumn\tValue\n");
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1;j<=3;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    } 
}

void transpose(int arr1[SIZE][SIZE],int arr2[SIZE][SIZE]){
    int m,n,t;
    m = arr1[0][1];
    n = arr1[0][2];
    t = arr1[0][3];

    arr2[0][1] = n;
    arr2[0][2] = m;
    arr2[0][3] = t;

    if(t<=0){
        return ;
    }
    int q = 1;
    for(int i=1;i<=n;i++){
        for(int p=1;p<=t;p++){
            if(arr1[p][2]==i){
                arr2[q][1] = arr1[p][2];
                arr2[q][2] = arr1[p][1];
                arr2[q][3] = arr1[p][3];
                q++;
            }
        }
    }
}