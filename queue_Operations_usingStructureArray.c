#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *p){
    if (p->rear==p->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

int isEmpty(struct queue *p){
    if (p->rear==p->front)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

void enqueue(struct queue *ptr, int val){
    if (isFull(ptr))
    {
        printf("Queue is Full!\n");
    }
    else{
        ptr->rear++;
        ptr->arr[ptr->rear]= val;
    }
}

int dequeue(struct queue *ptr){
    int  a=-1;
    if (isEmpty(ptr))
    {
        printf("Queue is Empty!\n");
    }
    else{
        ptr->front++;
        a= ptr->arr[ptr->front];
    }
    return a;
}


void show(struct queue *q){
    for (int i = q->front+1; i <= q->rear; i++)
    {
        printf("Element: %d\n", q->arr[i]);
    }
    
}

int main (){
    struct queue *q = (struct queue*)malloc (sizeof(struct queue));
    q->size =100;
    q->front=q->rear= -1;
    q->arr= (int *)malloc (q->size*sizeof(int));

    // Adding Element in Queue.
    enqueue(q,25);
    enqueue(q,89);
    enqueue(q,12);
    enqueue(q,8);
    show(q);

    // Deleting Element in Queue.
    printf("\nElement after Dequeue\n");
    dequeue(q);
    show(q);
    return 0;
}