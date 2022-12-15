#include <stdio.h>
#include <ctype.h>
#include<string.h>
char stack[100];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}
char * ReverseAndAlter(char *s){
char temp[100];
int j = 0,i;
 for(i=strlen(s);i>=0;i--){
        if (s[i] == '('){
            s[i] = ')';
        }
        if (s[i] == ')'){
            s[i] = '(';
        }
    
        temp[j++] = s[i-1];

    }
    return temp;
}
int main()
{
    int i,j=0;
    char temp[100];
    char expression[100];
    char postfixstring[100];
    char *e, x;
    printf("Enter the expression: ");
    scanf("%s", expression);
    ReverseAndAlter(expression);
    printf("%s", expression);
   

    while (*e != '\0')
    {
        if isalnum (*e)
        {
            postfixstring[j] =  *e;
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')

        {
            while ((x = pop()) != '(')
             postfixstring[j]=*e;
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
            {
                postfixstring[j] = *e;
            }
            push(*e);
        }
        e++;
        j++;
    }

  printf("%s",postfixstring);
  while(top!=-1){
    printf("%c",pop());
  }
}
