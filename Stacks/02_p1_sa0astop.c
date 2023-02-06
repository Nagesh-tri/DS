/*
statement: 
WAP to implement stack in an array stack_arr[] using stack_arr[0] as the top element. 
MY Opinion:
    Dekho y sb befaltu k chochle h...aur kuch krne ki jrurt nhi h
    but fir v try kr hi lete h..
    lets see as brute fource
    I can try that let that top and whenever push perform shift all data in array one side right
    and when pop perform shift left thats it

*/
#include<stdio.h>
#include<stdlib.h>
#define N 5

int stack_arr[N];

//I think we need here a extra variable to keep track of last element of array..
int bottm =-1;
//
int isFull(){
    if (bottm==N-1)
    {
        return 1;
    }
    return 0;
    
}
int isEmpty(){
    if (bottm==-1)
    {
        return 1;
    }
    return 0;
    
}
//shift
void shift_right(){
    int i;
    for ( i = bottm; i >0; i--)
    {
        stack_arr[i+1]=stack_arr[i];
    }
    
}
void shift_left(){
    int i;
    for ( i = 1; i<bottm; i++)
    {
        stack_arr[i-1]=stack_arr[i];
    }
    
}
//push
void push(int data){
    //all before check wether the stack is Full or not
    if (isFull())
    {
        printf("Stack Overflow!\n");
        return;
    }
    //need to update first elemnet (bottm)
    bottm +=1;
    
    //before pushing data we need to shift all right
    shift_right();
    //put data at index 0 as it is our top
    stack_arr[0]=data;
    
}
int pop(){
    if (isEmpty())
    {
        printf("Stack Underflow!\n");
        exit(1);
    }
    int value=stack_arr[0];
    //first shift then decrement bottm
    shift_left();
    bottm -=1;
    return value;
    
}
//
int peek(){
    if(isEmpty()){
        printf("Stack Underflow!");
        exit(0);
    }
    return stack_arr[0];
}
void print_stack(){
    if(isEmpty()){
        printf("Stack Underflow!");
        exit(0);
    }
    for(int i=bottm;i>=0;i--){
        //i starts froom top coz in stack we first remove top element
        printf("%d\t",stack_arr[i]);
    }
    printf("\n");
}
void main(){
    int choice, data;
    //our requireent froom user: for user:
    //user interface
        printf("-----------------------------*****-----------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top Element\n");
        printf("4. Print all elements in Stack\n");
        printf("5. Quit(Exit the program)\n");
    while(1){
        printf("Enter Your Choice \n");
        scanf("%d",&choice);

        //switch case
        switch(choice){
            case 1:
                printf("Enter Your data to push:\n");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                data =pop();
                printf("Deleted Element is: %d\n",data);
                break;
            case 3:
                printf("The top is %d\n",peek());
                break;
            case 4:
                printf("Elements are:\n");
                print_stack();
                break;
            case 5:
                exit(0);
                break;
            default: 
                printf("Please Enter any valid Choice!");


        }
    }
}
//stack array done before for assingments