/*
polynomial comes from poly which means many and nomial means terms
eg: 5x^3 -3x^2 + 2x+1
consisting : coefficient=5 ,variaable=x and exponent=3

creating ll of polynomial expressions
note: simply creating a linked list w/o any order is not good option  when
the target is to perform some airthmetic operations!;

It would be better if the polynomial expression is sorted in descending order of their exponents.
so for representaion the polynomial expressions , we will use a sorted ll which would be
in descending order based on the exponents.


here need not to store variable coz its the polynomial of one variabla
*/

#include<stdio.h>
#include<stdlib.h>
//structure for polynomial expression
struct node
{
    float coeff;
    int expo;
    struct node* link;
};
//--------------------------------------CREATIONN----------------------------
//insert im sorted  ll
struct node* insert(struct node* head, int co, int ex){
    struct node* temp;
    struct node* newP = malloc(sizeof(struct node));
    newP->coeff =co;
    newP->expo =ex;
    newP->link =NULL;

    if (head ==NULL || ex > head->expo)
    {
        newP->link =head;
        head =newP;
    }
    else{
        temp=head;
        while (temp->link !=NULL && temp->link->expo >=ex)
        {
            temp=temp->link;
        }
        newP->link=temp->link;
        temp->link =newP;
    }
    return head;
    
}

struct node* create(struct node* head){
    int n,i;
    float coeff;
    int expo;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("Enter the coefficient for term %d\t", i+1);
        scanf("%f", &coeff);
        printf("Enter the Exponent for term %d\t", i+1);
        scanf("%d", &expo);
        //step4 inert the new node in sorted linked list
        head = insert(head,coeff,expo);
    }
    return head;
    
}
void print_plym(struct node* head){
    if (head==NULL)
    {
        printf("NO POlynomial!");
    }
    else
    {
        struct node* temp =head;
        while (temp != NULL)
        {
            printf("(%.1fx^%d)",temp->coeff,temp->expo);
            temp=temp->link;
            if(temp!=NULL)
                printf(" + ");
            else{
                printf("\n");
            }
        }
        
    }
    
    
}
/* main for creation time
nesso lect 99
void main(){

    struct node* head =NULL;
    printf("Enter the Polynomial:\n");
    head= create(head);
    //step 5 : print polynomial (compleate poly with variables)
    print_plym(head);
}
*/


//_----------------------------OPERATIONS--------------------------
//Addion--combing like terms(having same variabes and same exponets)--sicne,
//variable are same we need to compare exponents
//since expression are stored in sorted LL , it would be easier
/*\
Algorithm: 
    repeat the following until (ptr1 || ptr2) becomes NULL
        if(ptr1->expo==ptr2->expo)
            add the coefficients and inserts the newly created node in reultant LL
            and make ptr1 and ptr2 to point to next nodes
        if(ptr1->expo>ptr2->expo)
            insert the node poited by ptr1 in the resulatent LL and make ptr1 point to the next node.
        else: do the same thing above with ptr2
    repeat untill ptr2!= NULL
        insert the remaining terms
    repeat untill ptr1!= NULL
        insert the remaining terms
*/

struct node* polyadd(struct node* head1,struct node* head2){
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    while (ptr1 !=NULL && ptr2 !=NULL)
    {
        if(ptr1->expo == ptr2->expo){
            float ad= ptr1->coeff+ptr2->coeff;
            head3 = insert(head3,ad,ptr1->expo);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3= insert(head3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->link;
        }else if (ptr1->expo < ptr2->expo)
        {
            head3= insert(head3,ptr2->coeff,ptr2->expo);
            ptr2=ptr2->link;
        }
        
        
    }
    while (ptr1 !=NULL)
    {
        head3= insert(head3,ptr1->coeff,ptr1->expo);
        ptr1=ptr1->link;
    }
    while (ptr2 !=NULL)
    {
        head3= insert(head3,ptr2->coeff,ptr2->expo);
        ptr2=ptr2->link;
    }
    printf("Added polynomial is : ");
    print_plym(head3);
}/*
//main for addtion operation
void main(){

    struct node* head1 =NULL;
    struct node* head2 =NULL;
    printf("Enter the First Polynomial:\n");
    head1= create(head1);
    print_plym(head1);

    printf("Enter the Second Polynomial:\n");
    head2= create(head2);
    print_plym(head2);
    
    //add
    polyadd(head1,head2);
}
*/

/*
Multiply: means multiplying their coefficients and adding exponets.
*/

struct node* product_ply(struct node* head1, struct node* head2){
    float coff;
    int rex;
     
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    //for each node
    while (ptr1 !=NULL)
    {
        while(ptr2!=NULL){
            coff =ptr1->coeff*ptr2->coeff;
            rex =ptr1->expo+ptr2->expo;
            head3 = insert(head3, coff,rex);
            ptr2= ptr2->link;
        }
        ptr1=ptr1->link;

    }
    
    
}
void main(){
    struct node* head1 =NULL;
    struct node* head2 =NULL;
    printf("Enter the First Polynomial:\n");
    head1= create(head1);
    print_plym(head1);

    printf("Enter the Second Polynomial:\n");
    head2= create(head2);
    print_plym(head2);

    //multiply

}