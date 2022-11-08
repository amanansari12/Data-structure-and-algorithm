#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        ptr->data = item;
        ptr->next = top;
        top = ptr;
    }
}

int pop()
{

    if (top == NULL)
    {
        printf("Stack Underflow!\n");
        return 0;
    }
    else
    {
        struct node *temp = top;
        int x = top->data;
        top = top->next;
        free(temp);
        return x;
    }
}

void show()
{
    
    if (top == NULL)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        struct node *ptr = top;
        printf("The Element in stack are:\n");
        while (ptr!= NULL)
        {
             printf("%d-->", ptr->data);
            ptr=ptr->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice, item;
    printf("\nImplementation of Stack using Linked List\n");
    while (1) {
        printf("\n\n1. Push\n2. Pop\n3. Show\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}