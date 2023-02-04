//save as template
#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node * prev;
    int data;
    struct node * next;
};
//printing list:
void printll(struct node * ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
//adding nodes:
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
//operations:
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
int main()
{
    struct node* head=NULL;
    struct node* ptr;
    head =addToEmpty(head,76);
    head =addAtEnd(head,786);
    head =addAtEnd(head,64);
    printf("Before Reversing.....\n");
    printll(head);
    //whork with whatever operations yoou want;
    head=reverse(head);
    printf("After Reversing.....\n");
    printll(head);


    return 0;
}
