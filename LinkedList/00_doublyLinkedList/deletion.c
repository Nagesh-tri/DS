#include<stdio.h>
struct node {
    struct node * prev;
    int data;
    struct node * next;
};

/*jsut move head pointer and 
free the prev part of newly head node*/
struct node * delFirst(struct node *head){
    head= head->next;
    free(head->prev);
    head->prev=NULL;
    return head;
}

//Delete last node:
//travel throug list till 2nd last node
//just free the next part of that node and put their null
struct node * delLast(struct node *head){
    struct node *temp;
    while(temp->next->next !=NULL){
        temp= temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

/*
deleting intermidiate node 
we must have postition
*/
struct node * del_im(struct node * head , int pos){
    struct node * temp =head;
    struct node * temp2 =NULL;
    if(pos==1){
        head=delFirst(head);
        return head;
    }
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    if(temp->next==NULL){
        head = delLast(head);
    }
    else{
        temp2=temp->prev;
        temp2->next =temp->next;
        temp->next->prev=temp2;
        free(temp);
        temp=NULL;
    }
    return head;
}