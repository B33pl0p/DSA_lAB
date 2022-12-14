#include<stdio.h>
#include<ctype.h>
int top = -1;
char stack[100];
void push(char a){
    stack[++top] =a;
}
char pop(){
    if (top == -1){
        return -1;
    }
    else {
        return stack[top--];
    }
}
int main(){
    int expression[100];
    int a,b,result,tempnum;
    printf("enter the expression :");
    scanf("%s",expression);
    char *e;
    e = expression;
    while (*e != '\0'){
        if(isdigit(*e)){
            tempnum = *e-48;
            push(tempnum);
        }
        else {
            a = pop();
            b = pop();
            switch (*e) {
                case  '+':
                result = b+a;
                break;
                case '-':
                result = b-a;
                break;
                case '*':
                result = b*a;
                break;
                case '/':
                result = b/a;
                break;
            }
        push(result);
        }
        e++;

    }
   
    printf("%d",pop());
    

}