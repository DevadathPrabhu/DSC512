/*

Create a linked list and Delete an element before a particular element. If there are more than one similar elements in the linked list, delete the element before the last occurrence.

Sample Input/Output
Input:
    17 42 16 18 39 -999
    16
Output
    17 16 18 39  

*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main(){
    
    struct Node *head = NULL;
    struct Node *newNode, *temp, *toDelAfter = NULL, *prev;
    
    while(0!=1){
        int value;
        
        scanf("%d", &value);
        
        if(value==-999) break;
        
        if(head==NULL) {
            head = (struct Node *)malloc(sizeof(struct Node));
            temp = head;
            head->data = value;
            temp->next = NULL;
        }
        else {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = NULL;
            temp->next = newNode;
            temp = temp->next;
        }
    }
    
    temp = head;
    prev = temp;
    temp = temp->next;
    
    int delBefore;
    
    scanf("%d", &delBefore);
    
    while(temp->next!=NULL){
        if(temp->next->data == delBefore){
            toDelAfter = prev;
        }
        prev=prev->next;
        temp=temp->next;
    }
    
    if(toDelAfter==NULL){
        if(head->next->data == delBefore) head = head->next;
        else if(head->data == delBefore){
            printf("Out of bound");
            return 0;
        }
        else {
            printf("Not found");
            return 0;
        }
    }
    
    if(toDelAfter!=NULL)
        toDelAfter->next = toDelAfter->next->next;
    
    while(head!=NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    
    return 0;
}
