#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int exp;
    int coef;
    struct Node *next;
}node;

node*readData(node*,int);
node*addnode(node*,int,int);
void display(node*);
node*addpoly(node*,node*);
int main()
{
    node*p1=NULL;
    node*p2 = NULL;
    node*p3= NULL;
    int x, y;
    printf("Enter no of term  : ");
    scanf("%d",&x);
    p1 = readData(p1,x);
    display(p1);
    printf("Enter no of term  : ");
    scanf("%d",&y);
    p2 = readData(p2,y);
    display(p2);
    p3 = addpoly(p1,p2);
    display(p3);
    return 0;
}
node*readData(node*p,int n){
    {
        int i = 0;
        while (i<n)
        {
            int c,e;
            printf("Enter Coefficient : ");
            scanf("%d",&c);
            printf("Enter Exponential : ");
            scanf("%d",&e);
            p = addnode(p,c,e);
            i++;
        }
    }
    return p;
}
void display(node*ptr){
    if(ptr==NULL){
        printf("Linked List is Empty\n");
    }
    else{
        while(ptr->next!=NULL){
            if(ptr->exp==0){
                if(ptr->coef==0){
                }
                else if(ptr->coef==1){
                    printf("1+");
                }
                else{
                    printf("%d+",ptr->coef);
                }
            }
            else if(ptr->exp==1){
                if(ptr->coef==0){

                }
                else if(ptr->coef==1){
                    printf("X+");
                }
                else{
                    printf("%dX+",ptr->coef);
                }
            }
            else{
                if(ptr->coef==0){

                }
                else if(ptr->coef==1){
                    printf("X^%d+",ptr->exp);
                }
                else{
                    printf("%dX^%d+",ptr->coef,ptr->exp);
                }
            }
            ptr = ptr->next;
        }
        if(ptr->exp==0){
                if(ptr->coef==0){
                }
                else if(ptr->coef==1){
                    printf("1");
                }
                else{
                    printf("%d",ptr->coef);
                }
            }
            else if(ptr->exp==1){
                if(ptr->coef==0){

                }
                else if(ptr->coef==1){
                    printf("X");
                }
                else{
                    printf("%dX",ptr->coef);
                }
            }
            else{
                if(ptr->coef==0){

                }
                else if(ptr->coef==1){
                    printf("X^%d",ptr->exp);
                }
                else{
                    printf("%dX^%d",ptr->coef,ptr->exp);
                }
            }
            ptr = ptr->next;
            printf("\n");

    }
}

node*addnode(node*ptr,int c,int e){
    node*p = (node*)malloc(sizeof(node));
    p->coef = c;
    p->exp = e;
    if(ptr==NULL){
        p->next = NULL;
        ptr = p;
    }
    else{
        node*q = ptr;
        while (q->next!=NULL)
        {
            q = q->next;
        }
        q ->next = p;
        p->next = NULL; 
    }
    return ptr;
}

node*addpoly(node*ptr1,node*ptr2){
    node*ptr3 = NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        int c,e;
        if(ptr1->exp > ptr2->exp){
            c = ptr1->coef;
            e = ptr1->exp;
            ptr1= ptr1->next;
        }
        else if(ptr1->exp < ptr2->exp){
            c = ptr2->coef;
            e = ptr2->exp;
            ptr2= ptr2->next;
        }
        else{
            c = ptr1->coef + ptr2->coef;
            e = ptr2->exp;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if(c!=0){
            ptr3 = addnode(ptr3,c,e);
        }
    }
    if(ptr1==NULL){
        while(ptr2!=NULL){
            ptr3 = addnode(ptr3,ptr2->coef,ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    if(ptr2==NULL){
        while(ptr1!=NULL){
            ptr3 = addnode(ptr3,ptr1->coef,ptr1->exp);
            ptr1 = ptr1->next;
        }
    }
    return ptr3;
}