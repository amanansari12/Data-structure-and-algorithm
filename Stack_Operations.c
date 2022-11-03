#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push()
{
    int x;

    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        printf("Enter the Element to Push: \n");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        int val = stack[top];
        top--;
        printf("Element Popped: %d\n", val);
        return val;
    }
}

void show()
{
    printf("The Element in stack are:\n\n");
    if (top== -1)
    {
        printf("Stack Underflow!\n");
    }
    
    for (int i = top; i >= 0; i--)
    {
        printf("Element: %d\n", stack[i]);
    }
}

int main()
{

    int choice;
    while(1){

    printf("\nOperations performed by Stack");
    printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
    printf("\n\nEnter the choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1: push();
        break;

    case 2: pop();
        break;

    case 3: show();
        break;
    
    case 4: exit(0);
        break;

    default:
    printf("Invalid choice!\n");

    }
    }
    return 0;
}