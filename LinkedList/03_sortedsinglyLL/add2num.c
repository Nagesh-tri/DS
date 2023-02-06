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
    struct node* newNode =malloc(sizeof(struct node));
    newNode->data=data;

    newNode->link =head;
    head =newNode;
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
    printf("\n");
}
struct node* num_LL(struct node* head,int n){
    while (n!=0)
    {
        head=add_node(head,n%10);
        n=n/10;
    }
    return head;
 }

/*
Reverse Number:
or reversing perticular singly list list
*/
struct node* rev_num(struct node* head){
    if (head==NULL)
    {
        return head;
    }

    struct node* current=NULL;
    struct node* next=head->link;
    head->link =NULL;
    while (next !=NULL)
    {
        current =next;
        next =next->link;
        current->link =head;
        head= current;
    }
    return head;
    
}
/*
add numbers: and store in resalant singly list list!
*/
struct node* addnum(struct node* head1, struct node* head2){
    if (head1->data==0)
    {
        return head2;
    }
    if (head2->data==0)
    {
        return head1;
    }
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    int carry=0,sum=0;
    while (ptr1 || ptr2)
    {
        sum=0;
        if(ptr1)
            sum += ptr1->data;
        if(ptr2)
            sum += ptr2->data;
        sum +=carry;
        carry=sum/10;
        sum=sum%10;

        head3 =add_node(head3,sum);
        if(ptr1)
            ptr1=ptr1->link;
        if(ptr2)
            ptr2=ptr2->link;
    }
    if (carry)
    {
        head3=add_node(head3,carry);
    }
    return head3;
}

void back2num(struct node* head){
    struct node* temp =head;
    printf("\nresult = ");
    while (temp)
    {
        printf("%d",temp->data);
        temp =temp->link;
    }
    return;
}
int main(){
    int a ,b;
    printf("Enter the two numbers: ");
    scanf("%d%d",&a,&b);

    printf("\nLinked list representation of first number: \n");
    struct node* head1 =NULL;
    head1= num_LL(head1,a);
    print_num(head1);

    printf("Linked list representation of first number: \n");
    struct node* head2 =NULL;
    head2= num_LL(head2,b);
    print_num(head2);

    head1=rev_num(head1);
    head2=rev_num(head2);

    printf("\nReversed NUmbers are: \n");
    print_num(head1);
    print_num(head2);
    //adding
    struct node* head3 =NULL;
    head3=addnum(head2,head1);
    printf("\nResultant LL after adding: \n");
    print_num(head3);

    back2num(head3);
    return 0;
}