#include<stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int enqueue(int a){
    if (front == (rear+1)%MAX_SIZE){
        printf("queue full");
    }
    else { 
        if(front == -1){
        front = rear = 0;   
        queue[rear] = a;  
        }
        else {
            rear = (rear+1)%MAX_SIZE;
            queue[rear] = a;
        }
    }
    printf("\n %d enqueued\n",a);

}
void dequeue(){
   
    int temp;
    if (front == -1){
       printf("queue empty");
        //queue empty
    }
    else {
        temp = queue[front];
        if (front == rear){
            front = rear = -1;
        }
        else {
            front = (front+1)%MAX_SIZE;
        }

        
    }
    printf("\nelement dequeued is %d\n",temp);
}
void display(){
    int i;
    printf("\nthe elements in queue are :");
    for(i = front;i<=rear;i++){
        printf(" %d" ,queue[i]);
    }
}
int main(){
enqueue(1);
enqueue(2);
enqueue(3);

enqueue(5);
display();
dequeue();
display();
enqueue(6);
display();

}