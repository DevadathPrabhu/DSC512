/*

Create a Doubly linked list and Traverse it in forward and backward direction.

Sample Input/Output
Input:
    17 42 16 18 39 -999
Output
    17 42 16 18 39 
    39 18 16 42 17   

*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main(){
    
    struct Node *head, *tail, *newNode, *traverser;
    
    while(0!=1){
        int value;
        
        scanf("%d", &value);
        
        if(value == -999) break;
        
        if(head == NULL){
            head = (struct Node *)malloc(sizeof(struct Node));
            tail = head;
            head->data = value;
            tail->next = NULL;
            tail->prev = NULL;
        } else {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    traverser = head;
    
    if(head == NULL){
        printf("Underflow");
    }
    else {
        while(traverser != NULL){
            printf("%d ", traverser->data);
            traverser=traverser->next;
        }
        
        traverser = tail;
        
        printf("\n");
        while(traverser != NULL){
            printf("%d ", traverser->data);
            traverser=traverser->prev;
        }
    }
    
    
    
    return 0;
}
