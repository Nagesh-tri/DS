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

struct node* addTobeg(struct node* tail,int data){
    struct node* newP= malloc(sizeof(struct node));
    newP->data =data;
    newP->next =tail->next;
    tail->next =newP;
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

    printcll(tail);
}