#include<stdio.h>
#include<stdlib.h>
#define size 100
int queue[size],front=-1,rear=-1;
int isempty(){
    return (front == -1) ? 1 : 0;
}
int  isfull(){
    return (rear == size-1) ? 1 : 0;
}
void enqueue(int data){
    queue[++rear]=data;
    if(front==-1){
        front = rear;
    }
    printf("Element Inserted !!!!\n");
}
int dequeue(){
    int ret=queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
    return ret;
}
int peek(){
    return queue[front];
}
int display(){
    for(int i=0;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}
int main(){
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice,data;
        printf("Enter Choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
                if(isfull()){
                    printf("Queue Overflow !!!!\n");
                }
                else{
                    printf("Element Element : ");
                    scanf("%d",&data);
                    enqueue(data);
                }
                break;
            case 2 :
                if(isempty()){
                    printf("Queue Underflow !!!!\n");
                }
                else{
                    printf("%d is dequeue from the queue\n",dequeue());
                }
                break;
            case 3 :
                printf("Element available in front of queue is %d\n",peek());
                break;
            case 4 :
                if(isempty()){
                    printf("Queue is empty");
                }
                else{
                    display();
                }
                break;
            case 5 :
                exit(0);
            default : 
                printf("Invalid Choice !!!!\n");
        }
        printf("\n");
    }
    return 0;
}
