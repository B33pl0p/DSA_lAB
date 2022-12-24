#include <stdio.h>
#include <stdlib.h>
#define MAXNODES 100
struct nodetype
{
    int next, info;
};
struct nodetype node[MAXNODES];
int avail = 0;
int IsEmpty();
void InitList();
void InsAtEnd(int);
void InsAfter(int, int);
void DelAfter(int);
void DelAtEnd();
void Display();
int main()
{
    int choice, data, position;
    while (1)
    {
        printf("\n1. Insert data at end");
        printf("\n2. Insert data in some position");
        printf("\n3. Delete data in some position");
        printf("\n4. Delete data at end");
        printf("\n5. Display contents of list");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            InsAtEnd(data);
            break;
        case 2:
            printf("Enter position: ");
            scanf("%d", &position);
            printf("Enter data: ");
            scanf("%d", &data);
            InsAfter(position, data);
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &position);
            DelAfter(position);
            break;
        case 4:
            DelAtEnd();
            break;
        case 5:
            Display();
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
}
void InitList()
{
    int i;
    for (i = 0; i < MAXNODES - 1; i++)
    {
        node[i].next = i + 1;
    }
    node[MAXNODES - 1].next = -1;
}
void InsAtEnd(int data)
{
    int index;
    index = MAXNODES - 1;
    node[index].info = data;
    printf("%d added in %d index\n", data, index);
}
void InsAfter(int position, int data)
{
    if (position > MAXNODES)
    {
        printf("Invalid operation");
        exit(0);
    }
    if (position == MAXNODES - 1)
    {
        InsAtEnd(data);
        return;
    }
    int temp;
    temp = MAXNODES - 1;
    // shift the elements to the right
    while (temp >= position - 1)
    {
        node[temp + 1].next = node[temp].next;
        temp--;
    }
    node[position].info = data;
    // avail = node[avail].next;

    // MAXNODES++; // increase the size of the list by making MAXNODE a global variable
    printf("%d added in %d index\n", data, position);
}

void DelAfter(int position)
{
    int temp, data;
    data = node[position].info;
    if(IsEmpty()){
        printf("List is empty");
        exit(0);
    }
    if (position == MAXNODES - 1)
    {
        DelAtEnd();
        return;
    }
    temp = position - 1;
    // shift the elements to the left
    while (temp <= MAXNODES - 1)
    {
        node[temp].next = node[temp + 1].next;
        temp++;
    }
    node[position].info = 0;
    printf("%d deleted from %d index\n", data, position);
}
void DelAtEnd()
{
    if(IsEmpty()){
        printf("List is empty");
        exit(0);
    }
    int data;
    data = node[MAXNODES - 1].info;
    node[MAXNODES - 1].info = 0;
    printf("%d deleted from %d index\n", data, MAXNODES - 1);
    // MAXNODES--; // decrease the size of the list by making MAXNODE a global variable
}
void Display()
{
    int i;
    printf("INDEX\tDATA\n");
    for (i = 0; i <= MAXNODES - 1; i++)
    {
        if (node[i].info == 0)
        {
            continue;
        }
        printf("%d \t %d\n", i, node[i].info);
    }
    printf("\n");
}
int IsEmpty(){
    int i,detect=1;
    for(i=0;i<MAXNODES;i++){
        if(node[i].info!=0){
            detect=0;
            break;
        }
    }
    if(detect==1){
        return 1;
    }
    else{
        return 0;
    }
}