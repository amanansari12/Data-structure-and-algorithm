// Implemeting Queue Using Array

// We have Implemented Circular Queue so that we can use the memory that we have previously used
// to make an Circular Queue we are doing Circular incrementing in Rear and Front
// Intializing front and rear with zero. If we do not do this then,
// the (rear+1)%MAX will not be equal to front then our Queue will not become full

// When Index reaches MAX-1 then due to do Circular Increment of rear the Index will become 0(Zero).
// Queue Full Condition --> If the Modulas of rear+1 and size of Queue become eual to Front then the Queue is Full.
// Queue Empty Condition --> If the rear become equals to Front then the Queue is Empty

#include<stdio.h>
#define MAX 10
int queue[MAX];
int front, rear;

int isFull(){
    // if (rear == MAX-1)
    if ((rear+1)%MAX == front) // Circular Increment of Rear
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if (rear == front)
    {
        return 1;
    }
    else{
        return 0;
    }
}


void enqueue(int data){
    if (isFull())
    {
       printf("Queue is Full\n");
    }
    else{
        // rear++;
        rear = (rear+1)%MAX; // Circular Increment of Rear
        queue[rear]=data;
        printf("Enqueued Element: %d\n", data);
    }
    
}

int dequeue(){
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }else{
        // front++;
        front = (front+1)%MAX;  // Circular Increment of Front
        int val=queue[front];
        return val;
    }
    
}

void show(){
    for (int i = front+1; i <= rear; i++)
    {
        printf("Element: %d\n", queue[i]);
    }
    
}

int main (){
    front = rear = 0;
    enqueue(22);
    enqueue(45);
    enqueue(89);
    enqueue(56);
    show();
    printf("\nElement after Dequeue\n");
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    show();
printf("\n\n");
    return 0;
}