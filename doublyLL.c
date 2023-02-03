#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node * prev;
    int data;
    struct node * next;
};
int main(){
    struct node *head=NULL;
    struct node *ptr;
    head =creatList(head);
    //travelsing the list:
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}