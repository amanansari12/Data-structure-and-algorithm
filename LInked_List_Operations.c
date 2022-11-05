#include <stdio.h>
#include <stdlib.h>

int linkedListOperations();
void display();
struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;
// Traversal
void traversal()
{
    struct Node *ptr = first;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Insert the Node at the Beginning:
void insertAtFirst(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = first;
    first = ptr;
}

// Insert the Node at the Certain Index:
void insertAtIndex(int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = first;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
}
// Insert at the End of the Linked List:
void insertAtLast(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}
// Insert a Node After the Given value:
void insertByValue(int data, int value)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = first;
    p = p->next;
    while (p->data != value)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
}
// Delete the Node from the Beginning:
void deleteAtFirst()
{
    struct Node *ptr = first;
    first = first->next;
    free(ptr);
    printf("Node Deleted from the Node.\n");
}

// Delete the Node at the Given Index:
int deleteAtIndex(int index)
{
    struct Node *temp;
    int x;
    struct Node *p = first;
    struct Node *q = first->next;

    if (first == NULL)
    {
        printf("Linked List Is Empty\n");
        return 0;
    }

    if (index == 0)
    {
        temp = first;
        first = first->next;
        x = temp->data;
        free(temp);
        return x;
    }

    if (first->next == NULL)
    {
        printf("Index %d not found\n", index);
        return 0;
    }

    int i = 0;
    while (i < index - 1 && q->next != NULL)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    if (i != index - 1)
    {
        printf("\n\nIndex %d Not found! Invalid Index\n\n", index);
        return 0;
    }

    p->next = q->next;
    temp = q;
    x = q->data;
    free(q);
    printf("Element %d at Index %d deleted.\n\n", x, index);
    traversal();
    return x;
}

// Delete the Last Node:
int deleteAtLast()
{
    struct Node *p = first;
    struct Node *q = first->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    int x = q->data;
    free(q);
    printf("Value %d at Last Node deleted\n", x);
    return x;
}

// Delete the Node with the Given Value:
int deleteByValue(int value)
{
    struct Node *temp;
    int x;
    struct Node *p = first;
    struct Node *q = first->next;

    if (first == NULL)
    {
        printf("Linked List Is Empty\n");
        return 0;
    }

    if (p->data == value)
    {
        temp = first;
        first = first->next;
        int x = temp->data;
        free(p);
        printf("Value %d Deleted.\n\n", x);
        return x;
    }
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        int x = q->data;
        printf("Value %d Deleted.\n\n", x);
        free(q);
        printf("\n\nLinked List After Deletion: \n\n");
        traversal();
        return x;
    }
    else
    {
        printf("Value %d not found in the Linked List\n", value);
    }
}

// Main Function
int main()
{
    insertAtFirst(8);
    insertAtFirst(9);
    insertAtFirst(12);
    insertAtFirst(33);
    insertAtFirst(56);
    linkedListOperations();
    return 0;
}

void display()
{
}

int linkedListOperations()
{
    int n;
    int m;
    while (1)
    {
        printf("\n");
        printf("1. Insert the Node at the Beginning:\n");
        printf("2. Insert the Node at the Certain Index:\n");
        printf("3. Insert at the End of the Linked List:\n");
        printf("4. Insert a Node After the Given value:\n");
        printf("5. Delete the Node from the Beginning:\n");
        printf("6. Delete the Node at the Given Index:\n");
        printf("7. Delete the Last Node:\n");
        printf("8. Delete the Node with the Given Value:\n");
        printf("9. Show Elements:\n");
        printf("10. Exit\n");

        printf("\n\n\n");
        printf("Choose the Options\n");
        int x;
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter the Element: ");
            scanf("%d", &n);
            insertAtFirst(n);
            break;

        case 2:
            if (first == NULL)
            {
                printf("Linked List Empty\n");
            }
            else
            {
                printf("Enter the Index: ");
                scanf("%d", &n);
                printf("Enter the Element: ");
                scanf("%d", &m);
                insertAtIndex(m, n);
            }
            break;

        case 3:
            if (first == NULL)
            {
                printf("Linked List Empty\n");
            }
            else
            {
                printf("Enter the Element: ");
                scanf("%d", &n);
                insertAtLast(n);
            }
            break;

        case 4:
            if (first == NULL)
            {
                printf("Linked List Empty\n");
            }
            else
            {
                printf("Enter the Element: ");
                scanf("%d", &n);
                printf("Enter the Value: ");
                scanf("%d", &m);
                insertByValue(n, m);
            }
            break;

        // Delete at First
        case 5:
            if (first == NULL)
            {
                printf("Linked List Is Empty\n");
                return 0;
            }
            else
            {
                deleteAtFirst();
                if (first != NULL)
                {
                    printf("\n\nLinked List After Deletion: \n\n");
                }

                traversal();
                printf("\n\n");
            }

            break;

        // Delete at Certain Index
        case 6:
            printf("Enter the Index: ");
            scanf("%d", &n);
            deleteAtIndex(n);
            printf("\n\n");
            break;

        // Delete the Last Node
        case 7:
            if (first == NULL)
            {
                printf("Linked List Is Empty\n");
                return 0;
            }
            else
            {
                deleteAtLast();
                printf("\n\nLinked List After Deletion: \n\n");
                traversal();
                printf("\n\n");
            }

            break;
        // Delete the Given Value
        case 8:
            printf("Enter the Value: ");
            scanf("%d", &m);
            deleteByValue(m);
            printf("\n\n");
            break;

            
        case 9:
            if (first == NULL)
            {
                printf("Linked List Empty!\n");
            }
            else
            {
                printf("\n\nThe Element in the Linked list are: \n");
                traversal();
            }
            break;
        case 10:
            exit(0);
            break;

        default:
            printf("\n\nEnter the Corrct Choice!");
            printf("\n\n");
            break;
        }
    }

    return 0;
}
