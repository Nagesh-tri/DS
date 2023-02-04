#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node* prev;
    int data;
    struct node* next;
};
struct node* addToEmpty(int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = temp;
    temp->data = data;
    temp->next =temp;
    return temp;
}
struct node* addAtBeg(struct node* tail, int data){
    struct node* newP =addToEmpty(data);
    if (tail==NULL)
    {
        return newP;
    }
    else{
        struct node* temp = tail->next;

        newP->prev =tail;
        newP->next=temp;
        temp->prev = newP;
        tail->next =newP;
    }
    
}
struct node* printcll(struct node* tail){
    if (tail==NULL)
    {
        printf("No element in the List!");
    }
    
    struct node* p = tail->next;
    do{
        printf("%d ", p->data);
        p=p->next;
    }while(p != tail->next);
    printf("\n");
}

//
struct node* addAtEnd(struct node* tail,int data){
    struct node* newP =addToEmpty(data);
    if (tail ==NULL)
    {
        return newP;
    }
    else{
        //pointer for head
        struct node* temp =tail->next;

        newP->next =temp;
        newP->prev =tail;
        tail->next =newP;
        temp->prev=newP;
        tail=newP;
        return tail;
    }
    
}
//insertion between nodes
//need to add node after pos
struct node* addAfterPos(struct node* tail, int pos, int data){
    //new node 
    struct node* newP = addToEmpty(newP);
    //if list is empty 
    if (tail==NULL)
    {
        return newP;
    }
    
    //travel till pos
    struct node* temp =tail->next;
    while (pos>1)
    {
        temp=temp->next;
        pos--;
    }
    newP->prev= temp;
    newP->next = temp->next;
    temp->next=newP;
    temp->next->prev=newP;
    //handling if adding node at last
    if (temp==tail)
    {
        tail=temp;
    }
    return tail;          
    
       
}
int main(){
    struct node* tail =NULL;
    tail= addToEmpty(45);
    tail= addAtBeg(tail,34);
    tail= addAtEnd(tail,87);
    printcll(tail);
    return 0;
}