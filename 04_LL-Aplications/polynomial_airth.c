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
int main(){

    struct node* head =NULL;
    printf("Enter the Polynomial:\n");
    head= create(head);
    //step 5 : print polynomial (compleate poly with variables)
    print_plym(head);
}
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

struct node* add_poly(struct node* head1,struct node* head2){

}