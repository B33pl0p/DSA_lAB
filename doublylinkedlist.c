#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev, *next;
    int info;
};
struct node *head = NULL;
void InsAtBeginning();
void InsAtEnd();
void display();
void InsAtPos();
void DelAtBeginning();
void DelAtEnd();
void DelAtPos();
int main()
{
    while (1)
    {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsAtBeginning();
            break;
        case 2:
            InsAtEnd();
            break;
        case 3:
            InsAtPos();
            break;
        case 4:
            DelAtBeginning();
            break;
        case 5:
            DelAtEnd();
            break;
        case 6:
            DelAtPos();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}

void InsAtBeginning()
{
    int data;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &data);
    newnode->info = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        system("clear");
        printf("Inserted %d\n", data);
        main();
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        system("clear");
        printf("Inserted %d\n", data);

        main();
    }
}
void display()
{
    struct node *temp;
    temp = head;
    printf("position  data\n");
    int i = 0;
    while (temp != NULL)
    {
        printf("%d\t %d\n", i++, temp->info);
        temp = temp->next;
    }
    printf("\n");
    return;
}
void InsAtEnd()
{
    int data;
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->next = NULL;
    printf("Enter data to insert :");
    scanf("%d", &data);
    newnode->info = data;
    if (head == NULL)
    {
        head = newnode;
        system("clear");
        printf("Inserted %d\n", data);
        return;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
        system("clear");
        printf("Inserted %d\n", data);
        return;
    }
}
void InsAtPos()
{
    int data, pos, i;
    printf("Enter position to insert :");
    scanf("%d", &pos);
    if (pos == 0)
    {
        InsAtBeginning();
    }

    printf("Enter data to insert :");
    scanf("%d", &data);
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    ptr = head;
    for (i = 0; i < pos - 1; i++)
    {
        ptr = ptr->next;
        if (ptr == NULL)
        {

            system("clear");
            printf("Invalid position\n");
            main();
        }
    }
    newnode->next = ptr->next;
    newnode->prev = ptr;
    ptr->next->prev = newnode;
    ptr->next = newnode;

    system("clear");
    printf("Inserted %d\n", data);
    return;
}
void DelAtBeginning()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        system("clear");
        printf("List is empty\n");
        return;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
        printf("Deleted %d\n", ptr->info);
        free(ptr);
        system("clear");
        return;
    }
}
void DelAtEnd()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        system("clear");
        printf("List is empty\n");
        return;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        printf("Deleted %d\n", ptr->info);
        free(ptr);
        system("clear");
        return;
    }
}

void DelAtPos()
{
    int pos, i;
     struct node *ptr;
    ptr = head;
    printf("Enter position to delete :");
    scanf("%d", &pos);
    if (pos == 0)
    {
        DelAtBeginning();
    }

    else {
    for(i=0;i<pos;i++){
        ptr = ptr->next;
        if(ptr == NULL){
            system("clear");
            printf("Invalid position\n");
            main();
        }
    }
    
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    system("clear");
    printf("Deleted %d\n", ptr->info);
    free(ptr);
    return;
    }
}
