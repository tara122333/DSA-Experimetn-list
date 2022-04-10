#include<stdio.h>
#include<stdlib.h>

typedef struct node{
        int data;
        struct node *next;
}tara;

// All Functions
void display(tara*ptr);
tara* linkedListInsertFirst(tara*head,int data);
tara* linkedListInsertEnd(tara*head,int data);
tara* linkedlistInsertIndex(tara*head ,int data,int index);
tara* linkedlistDeletionFirst(tara*head);
tara* linkedlistDeletionEnd(tara*head);
tara* linkedlistDeletionIndex(tara*head,int index);

int main()
{ 
    tara *head = NULL;
    int choise,input,position;
    system("cls");
    do
    {
        printf("\n\n\n\t\t1 -->> Insert At The Beginnig.\n");
        printf("\t\t2 -->> Insert At The Position.\n");
        printf("\t\t3 -->> Insert At The End.\n");
        printf("\t\t4 -->> Deletion At The Beginnig.\n");
        printf("\t\t5 -->> Deletion At The Position.\n");
        printf("\t\t6 -->> Deletion At The End.\n");
        printf("\t\t7 -->> Exit.\n\n\n");
        printf("\t\tPlease Choose Any One : ");
        scanf("%d",&choise);
        switch (choise)
        {
        case 1:
            printf("\nEnter A Value In Insert LinkedList :");
            scanf("%d",&input);
            head = linkedListInsertFirst(head,input);
            display(head);
            break;

        case 2:
            printf("\nEnter A Value In Insert LinkedList :");
            scanf("%d",&input);
            printf("\nEnter A Position :");
            scanf("%d",&position);
            head = linkedlistInsertIndex(head,input,position);
            display(head);
            break;

        case 3:
            printf("\nEnter A Value In Insert LinkedList :");
            scanf("%d",&input);
            head = linkedListInsertEnd(head,input);
            display(head);
            break;

        case 4:
            head = linkedlistDeletionFirst(head);
            display(head);
            break;

        case 5:
            printf("\nEnter A Delet Element Position :");
            scanf("%d",&position);
            head = linkedlistDeletionIndex(head,position);
            display(head);
            break;

        case 6:
            head = linkedlistDeletionEnd(head);
            display(head);
            break;
            
        case 7:
            system("cls");
            printf("\n\t\t________________________________________________");
            printf("\n\t\t|   *                                      *   |");
            printf("\n\t\t|  * * Thank You For Visiting My Program  * *  |");
            printf("\n\t\t|______________________________________________|\n\n\n");
            printf("\n\t\t\t_____________________________________________________");
            printf("\n\t\t\t|                                                    |");
            printf("\n\t\t\t|    ******************************************      |");
            printf("\n\t\t\t|    ***         TARA CHAND KUMAWAT         ***      |");
            printf("\n\t\t\t|    ******************************************      |");
            printf("\n\t\t\t|____________________________________________________|\n\n\n\n\n");

            break;
            
        default:
            printf("\n\n\tPlease Enter A Valid Number !! Thank You");
            break;
        }
    } while (choise >=1 && choise <= 6);
    
    return 0;
}

void display(tara*ptr){
    system("cls");
    while (ptr != NULL)
    {
        printf("  ==>> %d",ptr -> data);
        ptr = ptr -> next;
    }    
}

tara* linkedListInsertFirst(tara*head,int data){
    tara*ptr = (tara*)malloc(sizeof(tara));
    ptr -> data = data;
    ptr -> next = head;
    return ptr;
}

tara* linkedListInsertEnd(tara*head,int data){
    tara*ptr = (tara*)malloc(sizeof(tara));
    tara *p = head;
    while (p -> next != NULL)
    {
        p = p -> next;
    }
    ptr -> data = data;
    p -> next = ptr;
    ptr -> next = NULL;
    return head;
}

tara *linkedlistInsertIndex(tara*head ,int data,int index){
    tara *ptr = (tara*)malloc(sizeof(tara));
    tara *p = head;
    ptr -> data = data;
    int i = 0;
    while (i != index - 2) 
    {   
       p = p -> next ;
       i++;
    }
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}


tara* linkedlistDeletionFirst(tara*head)
{
    if (head == NULL)
    {
        printf("\nLinked list is empty you can not delet element \n");
    }
    else{
        tara*p = head;
        head = head -> next;
        free(p);
    }
    
    return head;
}
tara* linkedlistDeletionEnd(tara*head){
    if (head == NULL){
        printf("\nLinked list is empty you can not delet element \n");
    }
    else{
        tara*ptr = head -> next;
        tara*p = head;
        while (ptr->next != NULL){
            ptr = ptr -> next;
            p = p -> next;
        }
        p -> next = ptr -> next;
        free(ptr);
        }
    return head;
}


tara* linkedlistDeletionIndex(tara*head,int index){
    if (head == NULL){
        printf("\nLinked list is empty you can not delet element \n");
    }
    else{
        tara*ptr = head -> next;
        tara*p = head;
        int i = 0;
        for (; i < index -2; i++){   p = p -> next;
                ptr = ptr -> next;
            }
        p -> next = ptr -> next;
        free(ptr);
    }
    return head;
}

