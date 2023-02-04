//creating cll from scrach with a help of function
struct node* createCList(struct node* tail){
    int i,n,data;
    printf("Enter the number of nodes of the linked list: \n");
    scanf("%d",&n);

    if (n==0)
    {
        return tail;
    }
    printf("Enter the element 1: \n");
    scanf("%d",&data);
    tail= addToEmpty(data);

    for ( i = 1; i < n; i++)
    {
        printf("Enter the element %d",i+1);
        scanf("%d",&data);
        tail=addAtEnd(tail,data);
    }
    return tail;
    
    
}