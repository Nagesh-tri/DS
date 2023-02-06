/*
Why doubly linked list?
1:  deletion operation is faster 
in singly LL if intermidiate node is to be deleted we have need of a 'temp' pointer so that
referance to previous node may not lost but in doubly LL it has already 'prev' pointer

2: Inserting a new node before a given node is easier in doubly LL
simler to delterioon

conclusion:  it is clear that whenever it is required to reach the previous node from the 
given node w/o traversing the list, a doubly LL comes in handy;
nesso rapid fire 2: 8/10;
*/
//731s
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node* addAtEnd();
struct node * createList();
struct node {
    struct node * prev;
    int data;
    struct node * next;
};
//printing linked list
void printll(struct node * ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct node *head=NULL;
    //a pointer for travelsing:
    struct node *ptr;
    head =createList(head);
    //printing the list:
    printll(head);
    
    return 0;
}
struct node * addToEmpty(struct node * head,int data){
    struct node * temp =malloc(sizeof(struct node));
    temp->prev =NULL;
    temp->data=data;
    temp->next=NULL;
    head =temp;
    return head;
}
struct node* addAtEnd(struct node *head ,int data){
    struct node *temp, *tp;
    temp=malloc(sizeof(struct node));
    temp->prev =NULL;
    temp->data =data;
    temp->next =NULL;
    tp=head;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next =temp;
    temp->prev =tp;
    return head;
}

struct node * createList(struct node* head){
    int n,data,i;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    if(n==0)
        return head;

    printf("Enter the element for the node 1: ");
    scanf("%d",&data);
    head =addToEmpty(head,data);

    for(i=1;i<n;i++){
        printf("Enter the elemnt for the node %d ",i+1);
        scanf("%d",&data);
        head =addAtEnd(head,data);
    }
    return head;
}
