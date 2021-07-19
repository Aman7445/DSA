#include<stdio.h>
#include<stdlib.h>

#define size 5
int stack[size];
int top=-1;

//operating in one stack only
void push(int stack[],int data){
    if(top==size-1){
        printf("can't insert stack is full\n");
    }
    else
    {
        top++;
        stack[top]=data;
    }
    
}

void pull(int stack[]){
    int del;
    if(top==-1){
        printf("stack is empty can't delete\n");
    }
    else
    {
        del=stack[top];
        top--;
        printf("deleted element is %d\n",del);
    }
    
}

void display(int stack[]){
    int i;
    if(top==-1){
        printf("stack is empty\n");
    }
    else
    {
        for(i=top;i>=0;i--){
            printf("stack %d element is %d\n",i ,stack[i]);
        }
    }
}

int main(){
    int s[size];
    push(s,23);
    push(s,34);
    push(s,756);
    pull(s);
    display(s);


    return 0;


}