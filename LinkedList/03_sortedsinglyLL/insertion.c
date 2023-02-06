#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* addToEmpty(int data){
    struct node* temp =malloc(sizeof(struct node));
    temp->data=data;
    temp->link =NULL; /*hbmhhhhghgggghhjhhhhhhhhhhhhghhhgggghgggghghhgfggghgffffgfghhgggg
    jkjjhhgjggffhffggfhgfhgghjhkuyytghhgkjhkjhjghvghjgjkhjhfghghjg
    uyuttuytyrtytrrtetrerteteytrytyutuyuikyyyttrtyrdfrrtetrertrtrtuytiuyiouyoiuiuutygyufty*/
    return temp;
}
struct node* addAtEnd(struct node* head, int data){
    struct node* newP =malloc(sizeof(struct node));
    newP->data=data;
    newP->link= NULL;
    struct node* temp=head;
    while (temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=newP;
    return head;
}
struct node* insert(struct node* head, int data){
    struct node* temp;
    struct node* newP = malloc(sizeof(struct node));
    newP->data =data;
    newP->link =NULL;

    int key= data;
    if (head ==NULL || key< head->data)
    {
        newP->link =head;
        head =newP;
    }
    else{
        temp=head;
        while (temp->link !=NULL && temp->link->data <key)
        {
            temp=temp->link;
        }
        newP->link=temp->link;
        temp->link =newP;
    }
    return head;
    
}
void print(struct node* head){
    struct node* temp =head;
    while (temp !=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void main(){
    struct node* head =NULL;
    head =addToEmpty(67);
    addAtEnd(head,644);
    addAtEnd(head,64);
    addAtEnd(head,74);
    head=insert(head,58);
    print(head);

}