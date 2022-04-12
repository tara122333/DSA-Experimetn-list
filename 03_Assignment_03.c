#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size,top;
    int *arr;
};
int isEmpty(struct stack *);
int isFull(struct stack *);
void display(struct stack*ptr);
void Push(struct stack*,int);
int Pop(struct stack*);
int main()
{   
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 16;
    s->top = -1;
    s -> arr = (int*)malloc((s->size)*sizeof(int));
    int choise,input;
    do
    {
        printf("\n1. PUSH ELEMENT ");
        printf("\n2. POP ELEMENT ");
        printf("\n3. EXIT\n");
        scanf("%d",&choise);
        switch (choise)
        {
        case 1:
            printf("Enter a value : ");
            scanf("%d",&input);
            Push(s,input);
            display(s);
            break;
        
        case 2:
            printf("Popped element is => %d \n",Pop(s));
            display(s);
            break;
        
        case 3:
            printf("\nThank you !!\n");
            break;
        
        default:
            printf("\nPlease enter a valid number !!\n");
            break;
        }
    } while (choise != 3); 
    return 0;
}


int isEmpty(struct stack * s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}
int isFull(struct stack *s){
    if(s->top == (s-> size) - 1){
        return 1;
    } 
    return 0;
}
void display(struct stack*ptr){
    printf("\n ==>  Stack <== \n\n");
    if (ptr->top == -1){
        printf("\nStack is Empty\n");
    }
    else{
        for (int i = 0; i <= ptr -> top; i++)
        {
            printf(" ==>> %d ",ptr->arr[i]);
        }   
    }
}
void Push(struct stack*s,int data){
    if(isFull(s)){
        printf("\nStack is overflow | You can not push element in stack!! \n");
    }
    else{
        s -> top ++;
        s -> arr[s->top] = data;
    }
}
int Pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is underflow || You can not popped the element in tha stack !!\n");
        return -1;
    }
    else{
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}