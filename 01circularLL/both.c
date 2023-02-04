/*
circular singly LL:
it is similar to the singly linked list exceot that the last node of the circular singly LL
points to the first node.
create: 
jsut create singly LL and at the last node->next replace NULL with head;

circular doubly LL:
first node is pointing to last node and last node is pointing to first node

*/
#include<stdio.h>
#include<stdlib.h>
//circular singly LL:
struct nodeS
{
    int data;
    struct nodeS* next;
};
struct nodeS* circularSingly(int data){
    struct nodeS* temp=malloc(sizeof(struct nodeS));
    temp->data = data;
    temp->next=temp;
    return temp;
}
//Circular doubly LL:
struct nodeD{
    struct nodeD* prev;
    int data; 
    struct nodeD* next; 
};
struct nodeD* circularDoubly(int data){
    struct nodeD* temp = malloc(sizeof(struct nodeD));
    temp->data = data;
    temp->prev = temp;
    return temp;

}

int main(){
    int data=34;
    //we are writing here tail instead of head:
    struct nodeS* tail;
    struct nodeS* taild;
    tail =circularSingly(data);

    printf("%d\n",tail->data);
    //doubly: 
    tail =circularDoubly(data);
    printf("%d\n",taild->data);
    return 0;
}