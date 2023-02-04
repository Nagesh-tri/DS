#include<stdlib.h>
/*
deleting first node:
step1: take a temp pointer pointing to 1st node
step2: update next part of tail(last node) with add of 2nd node(since it will be 1st node 
after deletion)
step3: free temp and put null in temp

Time complexity: O(1)
 */
struct node
{
    int data;
    struct node* next;
};

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

/*
Delete last node:
step 1: tavelsel to the 2nd last node of the list as we don't have any pointer to point 
that node which we need coz it will be the last node after deltion
step2: update 2nd last node's next part with 1st node add (present in tail)
step3: free tail
step4: update tail with temp
Time Complexity: O(n)
*/
struct node* dellast(struct node* tail){
    //check if no node present
    if(tail==NULL)
        return tail;
    //if only one node is present
    if (tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    
    struct node* temp =tail->next;//1st node
    //1
    while (temp->next !=tail)
    {
        temp=temp->next;
    }
    //2
    temp->next=tail->next;
    //3
    free(tail);
    //4
    tail=temp;
    return tail;
}

/*
Deleting intermidiate node:
target : delete node at postion pos
step1: travel till jsut before the node to be delted i.e at pos-1th node
step2: make a new temp2 pointer which points to node t0 be deleted
step3: update temp->next with temp2->next value
step4: free temp2 & assign NUll to it.
Time Complexity: O(n)
*/
struct node* delInter(struct node* tail, int pos){
    //need to check 2 more conditions if list is empty or have onlly 1 node
    if (tail==NULL)
    {
        return tail;
    }
    if (tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return NULL;
    }
    
    
    struct node* temp=tail->next;
    while (pos>2)
    {
        temp=temp->next;
        pos--;
    }
    //2
    struct node* temp2=temp->next;
    //3
    temp->next=temp2->next;
    //handling the case of deleting last node:
    if (temp2==tail)
    {
        tail=temp;
    }
    
    //4
    free(temp2);
    temp2=NULL;
    return tail;    
    
}