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
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        for (int i = 0; i <= top; i--)
        {
            printf("Element: %d\n", stack[i]);
        }
    }
}

int peek(int i)
{
    int arrayInd = top - i + 1;
    if (arrayInd < 0)
    {
        printf("Invalid Index!\n");
        return -1;
    }
    else
    {
        return stack[arrayInd];
    }
}

int main()
{

    int choice;
    while (1)
    {

        printf("\nOperations performed by Stack");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.Peek\n5.End");
        printf("\n\nEnter the choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            show();
            break;

        case 4:
            int n;
            printf("Enter the Position:\n");
            scanf("%d", &n);
            // peek(n);
            printf("The Element at Position %d is %d.\n", n, peek(n));
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
