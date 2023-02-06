struct node* num_LL(struct node* head,int n){
    while (n!=0)
    {
        head=add_node(head,n%10);
        n=n/10;
    }
    return head;
 }
