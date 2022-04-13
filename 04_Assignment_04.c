#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack*next;
};

int isEmpty(struct stack *);
int isFull(struct stack *);
void display(struct stack*ptr);
struct stack *Push(struct stack*,int);
int Pop(struct stack**);

int main()
{ 
    struct stack*top = NULL;
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
            top = Push(top,input);
            display(top);
            break;
        
        case 2:
            printf("Popped element is => %d \n",Pop(&top));
            display(top);
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

int isEmpty(struct stack *top){
    if(top == NULL){
        return 1;
    }
    return 0;
}
int isFull(struct stack *top){
    struct stack *ptr = (struct stack*)malloc(sizeof(struct stack));
    if(ptr == NULL){
        return 1;
    }
    return 0;
}
void display(struct stack*ptr){
    while (ptr!=NULL)
    {
        printf(" ==> %d ",ptr->data);
        ptr = ptr -> next;
    }
    
}
struct stack *Push(struct stack *top,int data){
    if (isFull(top))
    {
        printf("\nStack is overfull\n");
    }
    else{
        struct stack* ptr = (struct stack*)malloc(sizeof(struct stack));
        ptr -> data = data;
        ptr->next = top;
        top = ptr;
        return top; 
    }
    
}
int Pop(struct stack**top){
    if (isEmpty(*top))
    {
        printf("Stack is underflow\n");
        return -1;
    }
    else{
        struct stack* ptr = *top;
        *top = (*top)->next;
        int val = ptr->data;
        free(ptr);
        return val; 
    }
    
}