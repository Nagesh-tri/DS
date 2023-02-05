/*
addition of two numbers using linked list 
lets see this in 3 parts:
1. Represent an n-digit number using a singly liked list
2. Reverse the number for addition
3. Add numbers and store the result in the resultant singly linked list
*/

/*
represent n-digit number:
1. need single digit for storing in ll ( for this purpose we can take moduler of num with 10 till zero and store it)
2. add these digits in begening of LInked list
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* add_node(struct node* head,int data){
    struct node* temp =malloc(sizeof(struct node));
    temp->data=data;
    temp->link =head;
    head =temp;
    return head;
}

void print_num(struct node* head){
    struct node* ptr=head;
    if (ptr==NULL)
    {
        printf("No Number.!\n");
    }
    else
    {
        while (ptr->link !=NULL)
        {
            printf("%d -> ",ptr->data);
            ptr=ptr->link;
        }
        printf("%d",ptr->data);
    }
    
    
}
struct node* num_LL(struct node* head,int n){
    while (n!=0)
    {
        head=add_node(head,n%10);
        n =n/10;
    }
    print_num(head);
 }
int main(){
    int a ,b;
    printf("Enter the two numbers: ");
    scanf("%d%d",&a,&b);

    printf("\nLinked list representation of first number: \n");
    struct node* head1 =NULL;
    head1= num_LL(head1,a);
    print_num(head1);

    printf("\nLinked list representation of first number: \n");
    struct node* head2 =NULL;
    head2= num_LL(head2,a);
    print_num(head2);
    return 0;
}