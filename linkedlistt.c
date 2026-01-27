/*
Write a C program of four different functions-
1. Create a linked list (insert at end)
2. Insert elements at different positions
3. Delete a node by entering data
4. Reverse the linked list
*/

#include <stdio.h>
#include <stdlib.h>

/* Node Structure */

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;


/* Function Prototypes */
void create_list();
void display();
void insert_at_position();
void delete_by_data();
void reverse_list();

/* Main Function */
int main()
{
    int choice;

    printf("\n===== LINKED LIST OPERATIONS =====\n");

    while (1)
    {
        printf("\n1. Create Linked List");
        printf("\n2. Insert Node at Position");
        printf("\n3. Delete Node by Data");
        printf("\n4. Reverse Linked List");
        printf("\n5. Display List");
        printf("\n9. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_list();
            break;

        case 2:
            insert_at_position();
            break;

        case 3:
            delete_by_data();
            break;

        case 4:
            reverse_list();
            break;

        case 5:
            display();
            break;

        case 9:
            printf("\nExiting Program...\n");
            exit(0);

        default:
            printf("\nInvalid Choice! Try again.\n");
        }
    }

    return 0;
}

/* 1. Create Linked List (Insert at End) */
void create_list()
{
    int choice;
    struct node *newnode, *temp;
    do
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("\nEnter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
           temp = head = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to add more nodes? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);

    } while (choice == 1);
}

/* Display Linked List */
void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("\nLinked List is Empty!\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* 2. Insert Node at Any Position */
void insert_at_position()
{
    int pos, i = 1, n;
    struct node *newnode, *temp;

    printf("\nEnter position to insert: ");
    scanf("%d", &pos);

    printf("Enter data: ");
    scanf("%d", &n);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;

    /* Insert at Beginning */
    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;

    while (temp != NULL && i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("\nInvalid Position!\n");
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

/* 3. Delete Node by Data */
void delete_by_data()
{
    int key;
    struct node *temp = head, *prev = NULL;

    printf("\nEnter data to delete: ");
    scanf("%d", &key);

    /* If head node contains key */
    if (head != NULL && head->data == key)
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Node Deleted!\n");
        return;
    }

    /* Search node */
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    /* If not found */
    if (temp == NULL)
    {
        printf("Node not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node Deleted!\n");
}

/* 4. Reverse Linked List */
void reverse_list()
{
    struct node *prev = NULL, *cur = head, *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    head = prev;
    printf("\nLinked List Reversed Successfully!\n");
}