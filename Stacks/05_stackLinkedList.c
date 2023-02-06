/*
Why linked list representaion
smiplest ans when size of stack not known in advanced
we prefer 1t node as our top , since deleting and adding new node in start is esier in linked list 

rep:
    structure of node
    push() fun code
    the actual imple
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
}*top=NULL;//top pointer

int isEmpty(){
    if (top==NULL)
    {
        return 1;  
    }
    return 0;
}
int peek(){
    if (isEmpty())
    {
        printf("Stack Underflow.");
        exit(1);
    }
    return top->data;
    
}
void push(int data){
    struct node* newNode;
    newNode = malloc(sizeof(newNode));
    if (newNode==NULL)
    {
        printf("Stack Overflow. ");
        exit(1);
    }
    newNode->data =data;
    newNode->link =top;
    top=newNode;
    
}
int pop(){
    struct node* temp;
    temp =top;
    if (isEmpty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    int val=temp->data;
    top =top->link;
    free(temp);
    temp=NULL;
    return val;
    
}

void print_stackl(){
    struct node* ptr;
    ptr=top;
    if (isEmpty())
    {
        printf("Stack Underflow.");
        exit(1);
    }
    
    printf("The Stack Elements are:");
    while (ptr)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
void main(){
    int choice, data;
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