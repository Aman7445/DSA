#include<stdio.h>

#define size 5
int queue[size];
int front=-1;
int rear=-1;

void enque(int queue[],int val){
    if(rear==size-1){
        printf("the queue is full\n");
    }
    else {
        if(front==-1){
            front =0;
        }
        rear++;
        queue[rear]=val;
        printf("%d is inserted in queue\n",val);
    }
}
void deque(int queue[]){
    if(front==-1){
        printf("the queue is empty\n");
    }
    else{
        int del=queue[front];
        front++;
        printf("the del element is : %d\n",del);
    }
}
void display(){
    if(rear == -1)
        printf("\nQueue is empty");
   else{
        int i;
        printf("\nNow, we are printing the Queue :");
        
        for(i=front; i<=rear; i++)
	        printf("%d ",queue[i]);
   }
}
int main()
{
   Enqueue(10);
   Enqueue(20);
   Enqueue(30);
   Enqueue(40);
   
   
   Dequeue();
   Dequeue();
   
   display();
   return 0;
}

