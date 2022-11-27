#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node * front = NULL;
struct node * rear = NULL;

void traversal(){
    struct node *ptr = front;
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

void enqueue(int val){
 struct node *ptr = (struct node *)malloc(sizeof(struct node));
 if (ptr==NULL)
 {
    printf("Queue is Full\n"); 
 }else{
    ptr->data=val;
    ptr->next=NULL;
    if (front==NULL)
    {
        front = rear =ptr;
    }else{
        rear->next=ptr;
        rear=ptr;
    }
    
 }
 
}


int dequeue(){
    int val = -1;
    if (front ==NULL)
    {
        printf("\n\nQueue is Empty! Element Cannot  be Dequeued\n");
    }
    else{
        struct node *ptr=front;
        front=front->next;
        int val=ptr->data;
        free(ptr);
        printf("\nDequeued Element: %d", val);
    }
    return val;
}
int main (){
    enqueue(25);
    enqueue(38);
    enqueue(56);
    enqueue(23);
    enqueue(89);
    printf("\n");
    traversal();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    printf("\n\n");
    traversal();
    return 0;
}