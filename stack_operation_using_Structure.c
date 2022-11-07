#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

void show(struct stack *ptr)
{
    printf("\nThe Elements in Stack are:\n\n");
    int i;
    if (ptr->top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {

        for (i = 0; i <= ptr->top; i++)
        {
            printf("Element: %d\n", ptr->arr[i]);
        }
    }
}

void push(struct stack *ptr, int val)
{
    // struct stack *ptr;
    if (ptr->top == ptr->size - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("Element: %d Pushed\n", val);
    }
}

void pop(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("Popped Element: %d\n", val);
        // return val;
    }
}

int peek(struct stack *ptr, int i)
{
    int arrayInd = ptr->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Invalid Index!\n");
        return -1;
    }
    else
    {
        return ptr->arr[arrayInd];
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

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
            int x;
            printf("Enter the Element to Push: \n");
            scanf("%d", &x);
            push(s, x);
            break;

        case 2:
            pop(s);
            break;

        case 3:
            show(s);
            break;

        case 4:
            int n;
            printf("Enter the Position:\n");
            scanf("%d", &n);
            // peek(n);
            printf("The Element at Position %d is %d.\n", n, peek(s,n));
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