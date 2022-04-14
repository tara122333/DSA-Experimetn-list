#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct{
    int front,rear;
    int element[MAX];
}queue;

int isFull(queue*);
int isEmpty(queue *);
void display(queue);
void enqueue(queue *,int);
// int dequeue(queue*);
// int front(queue *);
void creatqueue(queue *);

int main()
{   
    queue q;
    int ch,i;
    do{
        printf("\n1.Creat Queue\n");
        printf("2.Enqueue\n");
        printf("3.Dequeue\n");
        printf("4.Front\n");
        printf("5.Traversel\n");
        printf("6.Exit\n");
        printf("Enter Your choise : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                creatqueue(&q);
                break;
            case 2:
                printf("Enter an element : ");
                scanf("%d",&i);
                if(isFull(&q)){
                    printf("Stack Overflow\n");
                }
                else{
                    enqueue(&q,i);
                    printf("Element enqueue\n");
                }

                break;
            /*case 3:
                if(isEmpty(&q)){
                    printf("Stack Underflow\n");
                }
                else{
                    printf("dequeue element is : %d\n",dequeue(q));
                    printf("element enqueue\n");
                }
                break;
            case 4:
                printf("Front element is : %d\n",front(q));
                break;*/
            case 5:
                display(q);
                break;
            case 6:
                break;
            default:
                printf("\nPlease Enter a Valid number !! \n");
                break;


        }
    }while(ch!=6);
    return 0;
}

void creatqueue(queue *q){
    q->front = q->rear = -1;
}

int isFull(queue*q){
    if(q->rear == MAX-1){
        return 1;
    }
    return 0;
}

int isEmpty(queue *q){
    if(q->front ==0){
        return 1;
    }
    return 0;
}

void display(queue q){
    for (int i = q.front; i <=q.rear ; i++)
    {
       printf(" ==>> %d ",q.element[i]); 

    }
    
    
}
void enqueue(queue *q,int val){
    if(q->front == -1){
        q->rear = q->front = 0;
    }
    else if(q->rear == MAX -1){
        int i = q->front;
        while(i<=q->rear){
            q->element[i-q->front] = q->element[i];
            i++;
        }
    }
    else{
        q->rear = q->rear - q->front +1;
        q->front = 0;
    }
    q->element[q->rear] = val;
}

// int dequeue(queue*q){
//     int t = q->element[q->front];
//     if(q->front == q->rear){
//         q->front = q->rear = -1;
//     }
//     else{
//         q->front++;
//     }
//     return t;
// }
// int front(queue *q){
//     int t = q->element[q->front];
//     return t;
// }

