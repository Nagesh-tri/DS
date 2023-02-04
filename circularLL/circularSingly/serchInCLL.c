/*
we need to serch for  a element in list and consider 1st node has index of 0;
and return index of node where element found return -1 if not found
*/
int searchInCll(struct node* tail, int element){
    struct node* temp=tail-> next;
    int index=0;
    if (tail==NULL)
    {
        return -2;
    }
    temp =tail->next;
    do
    {
        if (temp->data ==element)
        {
            return index;
        }
        temp=temp->next;
        index++;
        
    } while (temp !=tail->next);
    return-1;
    
}