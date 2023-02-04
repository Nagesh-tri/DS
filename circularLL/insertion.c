/*
why we use tail?
if we points 1st node using head we need to perform traverse in order to perform o/ps like
insertion at start and end ; coz we need add of the last node in order to add in start as well 
in end
bt if we only track last node of circular LL,using 'tail' we needn't to traverse anymore
since, last node contains add of 1st node already ! (in tail->next);
*/
#include<stdio.h>
#include<stdlib.h>
//circular singly LL:
struct node
{
    int data;
    struct node* next;
};
struct node* addToEmpty(int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data= data;
    temp->next= temp;
    return temp;
}
//
struct node* addTobeg(struct node* tail,int data){
    struct node* newP= malloc(sizeof(struct node));
    newP->data =data;
    newP->next =tail->next;
    tail->next =newP;
    return tail;
}/*
insertion at end:
we just need to
step 1:update next part of newNode with add of 1st node
step 2:after that update next part of tail node with add of newNode 
step 3: update tail with newNode add thatas ittt
*/
struct node* addAtEnd(struct node* tail, int data){
    //creating new node
    struct node* newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = NULL;
    //step1:
    newP->next= tail->next;
    //step2:
    tail->next= newP;
    //step3:
    tail=newP; //also can do tail=tail->next
    return tail;
}/*
Insertion between the nodes:
target to add newNode afer postion 2;
step1: we need to traverse till that postion
step 2: update next part of newNOde with add of next node at particular position
step3: update next of particular node after that newNode to be inserted with add of newNOde
step4: we also have to check wheter user wants to add node maybe after last node, in that case 
we also have to update tail pointer with add of newNode
*/
struct node* addAfterPos(struct node* tail,int data,int pos){
    //new node
    struct node* newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = NULL;
    //step1
    struct node* p = tail->next;
    while (pos>1)
    {
        p=  p->next;
        pos--;
    }
    //step2
    newP->next=p->next;
    //step 3
    p->next=newP;
    //step 4
    if (p==tail)
    {
        tail=newP;
    }
    return tail;
    
}
struct node* printcll(struct node* tail){
    struct node* p = tail->next;
    do{
        printf("%d ", p->data);
        p=p->next;
    }while(p != tail->next);
}

void main(){
    struct node* tail;
    tail =addToEmpty(45);
    tail =addTobeg(tail,595);
    //add at end

    tail=addAtEnd(tail,76);
    tail=addAtEnd(tail,67);

    printcll(tail);
    //addd after pos
    tail= addAfterPos(tail,55,2);
    printcll(tail);
}