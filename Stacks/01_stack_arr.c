/*
we keep top to keep track of topmost element inserted in stack_arr[]
Note: top= 0 indicates that the topmost element is at index 0 and this means there is only one element 
in the stack.

for push op:
top is incremented by 1.
New element is pushed at the postion top
...since we using a array there is static memory allocation i.e capacity of stack is fixed
so when array is full we can not further push element in stack this state is called
stack Overflow.

for pop OP:
The element at the postion of top is deleted.
top is decremented by 1.
..there is no element in stack i.e we are trying to delete item from a empty 
stack it must provide an error called Stack Underflow.
//a array for implementing stack...since, almost every function requires this array.
//Instead of passing it to every function ,the better option is to declare it globally
#include<stdio.h>
#include <stdlib.h>
#define N 100  //define preprocessor directive

int stack_arr[N];

//TO indicate that the stack is empty, we will put -1 in the variable top.
int top=-1;
//check if stack is full
int isFull(){
    if (top==N-1)
    {
        return 1;
    }
    return 0;
    
}
//push
void push(int data){
    if (isFull())
    {
        printf("Stack Overflow!\n");
        return;
    }
    top++;
    stack_arr[top]=data;
}
int main(){

}
*/

#include <stdio.h>
#include <stdlib.h>
/*
Stack is consider just like a simple array having some 
restrictions i.e we can only access top  most elemnt at any cast.*/
//using define preprosedure
#define MAX 10
//defining globle variables :a stack array and top;
int stack_arr[MAX];
int top=-1;//in starting its having value of non existing index.\
//operations of stack
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
    stack_arr[top]=data;
    printf("Your data has been inserted!\n");
}
int pop(){
    int value;
    if(isEmpty()){
        printf("Stack Underflow!");
        exit(1);
    }
    value=stack_arr[top];
    top -=1;
    return value;
}
int peek(){
    if(isEmpty()){
        printf("Stack Underflow!");
        exit(0);
    }
    return stack_arr[top];
}
void print_stack(){
    if(isEmpty()){
        printf("Stack Underflow!");
        exit(0);
    }
    for(int i=top;i>=0;i--){
        //i starts froom top coz in stack we first remove top element
        printf("%d\t",stack_arr[i]);
    }
    printf("\n");
}
