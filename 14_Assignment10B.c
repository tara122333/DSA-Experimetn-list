//  sparse matrix 
#include<stdio.h>
#define SIZE 40
void readData(int arr[SIZE][SIZE],int);
void display(int arr[SIZE][SIZE],int);
void add_sparse(int arr1[SIZE][SIZE],int arr2[SIZE][SIZE],int arr3[SIZE][SIZE],int);
int main()
{ 
    int A[SIZE][SIZE]={(0,0)};
    int B[SIZE][SIZE]={(0,0)};
    int C[SIZE][SIZE]={(0,0)};
    int D[SIZE][SIZE]={(0,0)};

    int row1,col2,row2,col1,non_zero1,non_zero2;
    printf("\nSparse matrix 1 \n");
    printf("Enter No of Row : ");
    scanf("%d",&row1);
    printf("Enter No of Column : ");
    scanf("%d",&col1);
    printf("Enter non Zero element : ");
    scanf("%d",&non_zero1);
    readData(A,non_zero1);
    printf("\nSparse matrix 2 \n");
    printf("Enter No of Row : ");
    scanf("%d",&row2);
    printf("Enter No of Column : ");
    scanf("%d",&col2);
    printf("Enter non Zero element : ");
    scanf("%d",&non_zero2);
    readData(B,non_zero2);
    int tara;
    if(col1==row2){
        
        if(row1>=col2){
            tara = row1;
        }
        else if(row1<col2){
            tara = col2;
        }
        add_sparse(A,B,C,tara);
    }
        int k =1;
        for(int i=1;i<=tara;i++){
            for(int j=1;j<=tara;j++){
                if(C[i][j]!=0){
                    D[k][1] = i;
                    D[k][2] = j;
                    D[k][3] = C[i][j];
                    k++;
                }
            }
        }
        printf("before display addition\n");
        display(D,k-1);
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


void add_sparse(int arr1[SIZE][SIZE],int arr2[SIZE][SIZE],int arr3[SIZE][SIZE],int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                arr3[i][j] = arr1[i][j]+arr2[i][j];
        }
    }
}