/*

Create a linked list and Insert an element after a particular element. If there are more than one similar elements in the linked list, add the element after the first occurrence.

Sample Input/Output
Input:
    17 42 16 18 39 -999
    16 87
Output
    17 42 16 87 18 39  

*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main(){
    
    struct Node *head = NULL;
    struct Node *newNode, *temp, *anotherTemp;
    
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
        else {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data=value;
            newNode->next=NULL;
            temp->next=newNode;
            temp=temp->next;
        }
    }
    
    temp = head;
    
    int prev, insert;
    
    scanf("%d", &prev);
    scanf("%d", &insert);
    
    
    while(temp!=NULL && temp->data!=prev){
        temp=temp->next;
    }
    
    if(temp==NULL){
        printf("Not Found");
        return 0;
    }
    
    anotherTemp = temp->next;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=insert;
    newNode->next=anotherTemp;
    temp->next=newNode;
    
    while(head!=NULL){
        printf("%d ", head->data);
        head=head->next;
    }
    
    return 0;
}
