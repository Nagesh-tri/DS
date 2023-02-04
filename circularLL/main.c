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
}
struct node* addAtEnd(struct node* tail, int data){
    //creating new node
    struct node* newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = NULL;
    newP->next= tail->next;
    tail->next= newP;
    tail=newP; //also can do tail=tail->next
    return tail;
}
struct node* addAfterPos(struct node* tail,int data,int pos){
    //new node
    struct node* newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = NULL;
    struct node* p = tail->next;
    while (pos>1)
    {
        p=  p->next;
        pos--;
    }
    newP->next=p->next;
    p->next=newP;
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
    printf("\n");
}
struct node* delfirst(struct node* tail){
    struct node* temp;
    temp=tail->next;

    tail->next=temp->next;
  
    free(temp);
    temp= NULL;
    return tail;
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
    //DEL
    tail=delfirst(tail);
    printf("List after delteion: \n");
    printcll(tail);
}