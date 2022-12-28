#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *head = NULL;
void InsAtBeginning();
void InsAtEnd();
void InsAtPos();
void DelAtBeginning();
void DelAtEnd();
void DelAtPos();
void Display();
void prompt();
int main()
{
    prompt();
}

void prompt()
{
    int choice;
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
            Display();
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
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("Enter the element to insert :");
    scanf("%d", &data);
    newnode->info = data;
    newnode->next = head;
    head = newnode;
    printf("Inserted %d\n", data);
}
void InsAtEnd()
{
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("Enter the element to insert :");
    scanf("%d", &data);
    newnode->info = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
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
    }
}
void InsAtPos()
{
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    int data, pos, i,handler;
    printf("Enter the element to insert :");
    scanf("%d", &data);
    newnode->info = data;
    printf("Enter the position value :");
    scanf("%d", &pos);
    ptr = head;
    for (i = 0; i < pos - 1; i++)
    {
        
        if (ptr == NULL)
        {
            handler = 0;
        }
        else {ptr = ptr->next;}
    }
    if(handler == 0 ){
        system("clear");
        printf("position invalid\n");
        return;
    }


    newnode->next = ptr->next;
    ptr->next = newnode;
}
void Display()
{
    printf("The elements in the list are :\nposition  Item\n");
    int i;
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf(" %d \t %d\n", i++, ptr->info);
        ptr = ptr->next;
    }
}
void DelAtBeginning()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        system("clear");
        printf("Unable to delete\n");
        prompt();
    }
    head = head->next;
    printf("%d deleted\n", ptr->info);
    free(ptr);
}

void DelAtEnd()
{
    struct node *ptr, *temp;
    ptr = head;
    if (head == NULL)
    {
        system("clear");
        printf("Unable to delete\n");
        prompt();
    }
    if (head->next == NULL)
    {
        ptr = head;
        head = NULL;
        printf("%d deleted\n", ptr->info);
        free(ptr);
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("%d deleted\n", ptr->info);
        free(ptr);
    }
}
void DelAtPos()
{
    struct node *ptr, *temp;
    ptr = head;
    if (head == NULL)
    {
        system("clear");
        printf("Unable to delete\n");
        prompt();
    }
    int pos, i,handler;
    printf("Enter the position to delete :");
    scanf("%d", &pos);
    if (pos == 0)
    {
        DelAtBeginning();
    }
    else
    {
        for (i = 0; i < pos; i++)
        {
            temp = ptr;
          
            if (ptr == NULL)
            {
              handler = 0;  
            }
            else {
                  ptr = ptr->next;
            }
        }
        if(handler == 0){
            system("clear");
            printf("position invalid\n");
            return;
        }
        temp->next = ptr->next;
        printf("%d deleted\n", ptr->info);
        free(ptr);
    }
}
