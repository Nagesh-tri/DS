#include<stdio.h>
struct node {
    struct node * prev;
    int data;
    struct node * next;
};

//reverse doubly linked list: 
struct node * reverse(struct node* head){
    struct node* ptr1 =head;
    struct node* ptr2 =ptr1->next;

    ptr1->next=NULL;
    ptr1->prev=ptr2;

    while (ptr2 !=NULL)
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1 =ptr2;
        ptr2 =ptr2->prev;
    }
    head =ptr1;
    return head;
}