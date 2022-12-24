#include <stdio.h>
#include <stdlib.h>
#define MAXNODE 10
struct nodetype
{
    int info, next;
};
struct nodetype node[MAXNODE];
int avail = 0, i;
void initlist();
void delafter(int);
void freenode(int);
int getnode();
void insafter(int, int);
void display();
int main()
{
    initlist();
    insafter(0, 5);
    insafter(1, 0);
    insafter(2, 100);
    insafter(3, 500);
    insafter(4, 1000);
    display();
    delafter(3);
    display();
    insafter(5,22);
    display();
}
void initlist()
{
    int i;
    for (i = 0; i < MAXNODE-1; i++)
    {
        node[i].next = i + 1;
    }
    node[MAXNODE - 1].next = -1;
}
void insafter(int position, int data)
{
    int temp;
    if (position == -1)
    {
        printf("Invalid operation");
        exit(0);
    }
    temp = getnode();
    node[temp].info = data;
    node[temp].next = node[position].next;
    node[position].next = temp;
    printf("%d added\n", data);

}
int getnode()
{
    int temp;
    if (avail == -1)
    {
        printf("Data can't be added \n");
        exit(0);
    }
    temp = avail;
    avail = node[avail].next;
    return temp;
}
void delafter(int position)
{
    int temp, data;
    if (position == -1 || node[position].next == -1)
    {
        printf("Invalid deletion");
        exit(0);
    }
    temp = node[position].next;
    data = node[temp].info;
    node[position].next = node[temp].next;
    freenode(temp);
    printf("Element(s) deleted after %d\n", data);
}
void freenode(int position)
{
    node[position].next = avail;
    avail = position;
}
void display()
{
    printf("The elements in the list are :");
    int i;
    for (i = 0; i < avail; i++)
    {
        printf("%d ", node[i].info);
    }
    printf("\n");
}