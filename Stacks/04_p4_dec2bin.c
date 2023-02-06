/*
Decimal to binary Numbers
Procedure: 
    Divide the number by 2
    store the remainder somewhere
    Repeat step 1 and 2 until quotient becomes 0.
    Print all the remainder in reverse order.

we can use stack to print nums in reverse order.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX];
int top=-1;
int isEmpty(){
    if(top==-1){
        return 1;
    }
    else
        return 0;
}
int isFull(){
    if(top==MAX-1){
        return 1;
    }
    else 
        return 0;
}
void push(int data){
    if(isFull()){
        printf("Stack Overflow!");
        return;
    }
    top +=1;
    stack[top]=data;
}
int pop(){
    int value;
    if(isEmpty()){
        printf("Stack Underflow!");
        exit(1);
    }
    value=stack[top];
    top -=1;
    return value;
}
void print(){
    if(isEmpty()){
        printf("Stack Underflow!");
        exit(0);
    }
    for(int i=top;i>=0;i--){
        //i starts froom top coz in stack we first remove top element
        printf("%d\t",stack[i]);
    }
    printf("\n");
}

void dec2bin(int num){
    while (num!=0)
    {
        push(num%2);
        num=num/2;
    }
    //result stored in stack just print the stack
    print();
}
void main (){
    int dec;
    printf("Enter the decimal number: ");
    scanf("%d",&dec);
    dec2bin(dec);
}