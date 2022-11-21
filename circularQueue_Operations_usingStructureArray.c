#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct circularQueue *p){
    if ((p->rear+1)%p->size == p->front)  // Circular Increment of Rear
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

int isEmpty(struct circularQueue *p){
    if (p->rear==p->front)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

void enqueue(struct circularQueue *ptr, int val){
    if (isFull(ptr))
    {
        printf("circularQueue is Full!\n");
    }
    else{
        ptr->rear= (ptr->rear+1)%ptr->size;  // Circular Increment of Rear
        ptr->arr[ptr->rear]= val;
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct circularQueue *ptr){
    int  a=-1;
    if (isEmpty(ptr))
    {
        printf("circularQueue is Empty!\n");
    }
    else{
        ptr->front= (ptr->front+1)%ptr->size; // Circular Increment of  Front
        a= ptr->arr[ptr->front];
    }
    return a;
}


void show(struct circularQueue *q){
    printf("\nElement in the Queue\n");
    for (int i = q->front+1; i <= q->rear; i++)
    {
        printf("Element: %d\n", q->arr[i]);
    }
    
}

int main (){
    struct circularQueue *q = (struct circularQueue*)malloc (sizeof(struct circularQueue));
    q->size =100;
    q->front=q->rear= 0;
    q->arr= (int *)malloc (q->size*sizeof(int));

    // Adding Element in circularQueue.
    enqueue(q,25);
    enqueue(q,89);
    enqueue(q,12);
    enqueue(q,8);
    show(q);

    // Deleting Element in circularQueue.
    dequeue(q);
    show(q);
    return 0;
}