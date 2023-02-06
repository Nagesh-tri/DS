/*
Statement:
print prime factors of a number in decending order using stack
tech: Prime factorization: 
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
//defining globle variables :a stack array and top;
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
void print_stack(){
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

//
void prime_fact(int num){
    int i=2;
    //find all prime factors
    while (num!=1)
    {
        while(num%i==0){
            push(i);
            num= num/i;
        }
        i++;
    }
    //pop and print in decending order
    printf("Prime factors of the number in descending order are as follows: ");
    while (top !=-1)
    {
        printf("%d ",pop());
    }
    
    
}
int main(){
    int num;
    printf("Please Enter A Positive Number: \n");
    scanf("%d",&num);
    prime_fact(num);
    return 0;
}