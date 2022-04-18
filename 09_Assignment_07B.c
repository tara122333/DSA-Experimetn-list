#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node*next;
}node;
typedef struct{
    node*front;
    node*rear;
}queue;

int isEmpty(queue *);
void display(queue*);
queue* enqueue(queue *,int);
int dequeue(queue*);
int front(queue *);
queue* creatqueue(queue *);

int main()
{
    queue *q;
    int ch,i;
    do{
	printf("\n1.Creat Queue\n");
	printf("2.Enqueue\n");
	printf("3.Dequeue\n");
	printf("4.Front\n");
	printf("5.Traverse\n");
	printf("6.Exit\n");
	printf("Enter Your choise : ");
	scanf("%d",&ch);
	switch(ch){
	    case 1:
		q=creatqueue(q);
		printf("\nqueue created");
		break;
	    case 2:
		printf("Enter an element : ");
		scanf("%d",&i);
		    q=enqueue(q,i);
		    printf("Element enqueue\n");
		break;
	    case 3:
		if(isEmpty(q)){
		    printf("Queue Underflow\n");
		}
		else{
		    int d = dequeue(q);
		    printf("dequeue element is : %d\n",d);
		}
		break;
	    case 4:
		if(!isEmpty(q))
			printf("Front element is : %d\n",front(q));
		else
			printf("\nQueue underflow");
		break;
	    case 5:
		if(!isEmpty(q))
			display(q);
		else
			printf("\n Queue is empty");
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

int isEmpty(queue *q){
    if(q->front == NULL){
	return 1;
    }
    return 0;
}

void display(queue *q){
    node *i=q->front;
    while(i!=NULL)
    {
	printf(" ==> %d ",i->data);
	i=i->next;
    }
}
queue* enqueue(queue *q,int val){
    node *p = (node*)malloc(sizeof(node));
    p->data = val;
    p->next = NULL;
    //printf("\n%d",p->data);
    if(q->rear == NULL){
       // printf("\nHELLO");
        q->front = q->rear = p;
    }
    else{
        (q->rear)->next = p;
        q->rear = p;
    }
    return q;
}

int dequeue(queue*q){
    int t = (q->front)->data;
    node*p = q->front;
    if(q->front == q->rear){
        q->front = q->rear = NULL;
    }
    else{
        q->front = (q->front)->next;
    }
    free(p);
    return t;
}
int front(queue *q){
    int t = (q->front)->data;
    return t;
}
queue* creatqueue(queue *q){
    q->front = q->rear = NULL;
    return q;
}