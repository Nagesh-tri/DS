#include<stdio.h>
#include<stdlib.h>

/*

we know that we have 1st node add in tail->next
in order to traverse we start from 1st node, by using a pointer 'p', but the thing is in cll(circular LL)
last node is not contains the 'null' so how to determine when to stop traversing
we also know that p(starts pointing from 1st node) reached the 1st node again we should stop
to do so we use 'do while' with condition p contails the same add as inn tail pointer i.e (p != tail->next)
*/
struct node* printcll(struct node* tail){
    struct node* p = tail->next;
    do{
        printf("%d ", p->data);
        p=p->next;
    }while(p != tail->next);
}

//counting the no of node and print it
void contElements(struct node* tail){
    struct node* temp=tail->next;
    int count=0;
    while (temp !=tail)
    {
        temp=temp->next;
        count++;
    }
    count++;
    printf("There are %d elements in the List.\n",count);
}