#include <stdio.h>;
int front=-1,rear=-1;
#define MAX 10
int queue[MAX];

int isEmpty(){
    return(front==-1 && rear==-1);
}

int isFull(){
    return(rear == MAX-1);
}
void enqueue(int value){
    if(isFull()){
        printf("Queue is full");
        return;
    }

    if(isEmpty()){
        front=0;
        rear=0;
    }
    else{
        rear+=1;
       
    }

     queue[rear] = value;

     printf("%d enqueued",value);
}

void dequeue(int value){
    if(isEmpty()){
        printf("queue is empty");
        return;
    }

    printf("%d dequeued",queue[front]);
    front+=1;
    
}

void display(){
    if(isEmpty()){
        printf("queue is empty");
        return;    
    }

    printf("queue elements:");

    for(int i=front;i<MAX;i++){
        printf("%d\t",queue[i]);
    }
}