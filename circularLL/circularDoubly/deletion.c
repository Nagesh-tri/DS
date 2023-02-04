#include<stdlib.h>
#include<stdio.h>

//deleting first node
struct node* delfirst(struct node* tail){
    //if list is empty or have only one node
    if (tail==NULL)
    {
        return tail;
    }
    //a pointer to point 1st node
    struct node* temp= tail->next;
    //
    if (temp==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    
    //just update the links
    tail->next = temp->next;
    temp-next->prev= tail;
    //free node
    free(temp);
    temp=NULL;
    return tail;

}

//deleting last node
struct node* dellast(struct node* tail){
    if (tail==NULL)
    {
        return tail;
    }
    struct node* temp= tail->prev;
    if (temp==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    temp->next = tail->next;
    tail->next->prev= temp;
    free(tail);
    tail=temp;
    return tail;
}

//deleting inter midiate node...delete node at pos
struct node* delAtpos(struct node* tail, int pos){
    struct node* temp= tail->next;
    //travel till node
    while (pos>1)
    {
        temp=temp->next;
        pos--;
    }
    temp->prev-next=temp->next;
    temp->next->prev = temp-prev;
    if (temp==tail)
    {
        tail=temp->prev;
    }
    free(temp);
    return tail;
    
}