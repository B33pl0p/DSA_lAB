#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3
int queue[MAX_SIZE];
int front = 0;
int rear = -1;
void insert();
void delete();
void display();
int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Insert to queue\n");
        printf("2. Delete from queue\n");
        printf("3. Display queue items\n");
        printf("4. Exit\n");
        printf("Enter a choice : ");
        scanf("%d", &choice);
    prompt:
        switch (choice)
        {
        case 1:
            insert();
         

            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
          
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
}
void insert(){
    int item;
    printf("\nEnter the item to insert into queue : ");
    scanf("%d",&item);
    if(rear == MAX_SIZE-1){
        printf("queue is full\n");
    }
    else {
        queue[++rear] = item;
    }
    system("clear");
    printf("Item inserted\n");   
}
void delete(){
    if(front>rear){
        printf("Queue is empty\n");
    }
    else{
        printf("deleted element is %d\n",queue[front]);
        front++;
    }
     
}
void display(){
    int i;
    printf(" the elements in the queue are :");
    for(i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}