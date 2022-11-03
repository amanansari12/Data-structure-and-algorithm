#include <stdio.h>
#include <stdlib.h>

int linkedListOperations();
void display();
struct Node
{
    int data;
    struct Node *next;
};

struct Node *temp = NULL;
// Traversal
void traversal()
{
    struct Node *ptr = temp;
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
    ptr->next = temp;
    temp = ptr;
}

// Insert the Node at the Certain Index:
void insertAtIndex(int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = temp;
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
    struct Node *p = temp;
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
    struct Node *p = temp;
    p=p->next;
    while(p->data!=value){
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
}
// Delete the Node from the Beginning:
void deleteAtFirst()
{
    struct Node *ptr = temp;
    temp = temp->next;
    free(ptr);
}

// Delete the Node at the Given Index:
void deleteAtIndex(int index)
{
    struct Node *p = temp;
    struct Node *q = temp->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
}

// Delete the Last Node:
void deleteAtLast()
{
    struct Node *p = temp;
    struct Node *q = temp->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}

// Delete the Node with the Given Value:
void deleteByValue(int value)
{
    struct Node *p = temp;
    struct Node *q = temp->next;

    if (p->data == value)
    {
        temp=temp->next;
        free(p);
    }
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
}

// Main Function
int main()
{
    printf("\n\n\n");
    display();
    printf("\n\nThe Element in the Linked list are: \n");

    insertAtFirst(23);
    insertAtFirst(56);
    insertAtFirst(22);
    insertAtFirst(38);
    insertAtFirst(52);
    insertAtFirst(54);
    traversal();

    printf("\n\n\n");
    printf("Choose the Options\n");
    int x;
    scanf("%d",&x);
    linkedListOperations(x);
    return 0;
}

void display(){
    printf("1. Insert the Node at the Beginning:\n");
    printf("2. Insert the Node at the Certain Index:\n");
    printf("3. Insert at the End of the Linked List:\n");
    printf("4. Insert a Node After the Given value:\n");
    printf("5. Delete the Node from the Beginning:\n");
    printf("6. Delete the Node at the Given Index:\n");
    printf("7. Delete the Last Node:\n");
    printf("8. Delete the Node with the Given Value:\n");
    printf("9. Exit\n");
}

int linkedListOperations(int x){
    int n; int m;
    switch (x)
    {
    case 1:
        printf("Enter the Element: ");
        scanf("%d",&n);
        insertAtFirst(n);
        printf("\n\nLinked List After the Insertion at the begenning: \n\n");
        traversal();
        printf("\n\n");
        break;
    
    case 2:
        printf("Enter the Index: ");
        scanf("%d",&n);
        printf("Enter the Element: ");
        scanf("%d",&m);
        insertAtIndex(m,n);
        printf("\n\nLinked List After the Insertion: \n\n");
        traversal();
        printf("\n\n");
        break;

    case 3:
        printf("Enter the Element: ");
        scanf("%d",&n);
        insertAtLast(n);
        printf("\n\nLinked List After the Insertion: \n\n");
        traversal();
        printf("\n\n");
        break;
    
    case 4:
        printf("Enter the Element: ");
        scanf("%d",&n);
        printf("Enter the Value: ");
        scanf("%d",&m);
        insertByValue(n, m);
        printf("\n\nLinked List After the Insertion: \n\n");
        traversal();
        printf("\n\n");
        break;

    case 5:
        deleteAtFirst();
        printf("\n\nLinked List After Deletion: \n\n");
        traversal();
        printf("\n\n");
        break;

    case 6:
        printf("Enter the Index: ");
        scanf("%d",&n);
        deleteAtIndex(n);
        printf("\n\nLinked List After Deletion: \n\n");
        traversal();
        printf("\n\n");
        break;

    case 7:
        deleteAtLast();
        printf("\n\nLinked List After Deletion: \n\n");
        traversal();
        printf("\n\n");
        break;
    
    case 8:
        printf("Enter the Value: ");
        scanf("%d",&m);
        deleteByValue(m);
        printf("\n\nLinked List After Deletion: \n\n");
        traversal();
        printf("\n\n");
        break;

    case 9:
    printf("\n\n");
        break;
    
    default:
        printf("\n\nEnter the Corrct Choice!");
        printf("\n\n");
        break;
    }
    return 0;
}