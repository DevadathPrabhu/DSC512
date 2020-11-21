/*

Create a linked list and Traverse it.

Sample Input/Output
Input:
    17 42 16 18 39 -999
Output
    17 42 16 18 39    

*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main(){
    
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    
    while(0!=1){
        int value;
        
        scanf("%d", &value);
        
        if(value==-999){
            break;
        }
        
        if(head==NULL){
            head = (struct Node *)malloc(sizeof(struct Node));
            temp = head;
            head->data=value;
            temp->next=NULL;
            
        }
        else{
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data=value;
            newNode->next=NULL;
            temp->next=newNode;
            temp=temp->next;
        }
    }
    
    if(head==NULL){
        printf("Underflow");
    }
    
    while(head!=NULL){
        printf("%d ", head->data);
        head=head->next;
    }
    
    return 0;
}
