#include<stdio.h>
#include<stdlib.h>
//operations using createlist
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
struct node* printcll(struct node* tail){
    struct node* p = tail->next;
    do{
        printf("%d ", p->data);
        p=p->next;
    }while(p != tail->next);
    printf("\n");
}
//creating cll from scrach with a help of function
struct node* createCList(struct node* tail){
    int i,n,data;
    printf("Enter the number of nodes of the linked list: \n");
    scanf("%d",&n);

    if (n==0)
    {
        return tail;
    }
    printf("Enter the element 1:\t");
    scanf("%d",&data);
    tail= addToEmpty(data);

    for ( i = 1; i < n; i++)
    {
        printf("Enter the element %d\t",i+1);
        scanf("%d",&data);
        tail=addAtEnd(tail,data);
    }
    return tail;
}
//jsut using dellast
struct node* dellast(struct node* tail){
    
    if(tail==NULL)
        return tail;
    if (tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    
    struct node* temp =tail->next;
    while (temp->next !=tail)
    {
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
    return tail;
}
int main(){
    struct node* tail =NULL;
    tail=createCList(tail);
    printf("\nList before Deletion: ");
    printcll(tail);

    tail =dellast(tail);
    printf("List after deletion: ");
    printcll(tail);
}