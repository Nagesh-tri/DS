/*
deleting first node:
step1: take a temp pointer pointing to 1st node
step2: update next part of tail(last node) with add of 2nd node(since it will be 1st node 
after deletion)
step3: free temp and put null in temp

Time complexity: O(1)
 */
struct node* delfirst(struct node* tail){
    //1
    struct node* temp;
    temp=tail->next;
    //2
    tail->next=temp->next;
    //3
    free(temp);
    temp= NULL;
}