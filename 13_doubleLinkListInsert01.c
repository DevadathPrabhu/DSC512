/*

Create a doubly linked list. 

Add 3 elements from the beginning of the linked list. Display the elements of the resulting doubly linked list in reverse order.

Sample Input/Output
Input
    84 19 32 45 25 39 -999
    -5 -12 -68
Output
    39 25 45 32 19 84 -5 -12 -68

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
    int empty = 0;
    
    while(0!=1){
        int value;
        
        scanf("%d", &value);
        
        
        if(value == -999) break;
        
        empty = 1;
        
        if(head == NULL){
            head = (struct Node *)malloc(sizeof(struct Node));
            tail = head;
            head->data = value;
            tail->next = NULL;
            tail->prev = NULL;
        }
        else {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    
    
    int val1=-999, val2=-999, val3=-999;
    
    
    
    scanf("%d", &val1);
    scanf("%d", &val2);
    scanf("%d", &val3);
    
    if(val1==-999 || val2==-999 || val3==-999){
        printf("Error!! Three elements must be inserted.");
        return 0;
    }
    
    if(empty == 0){
        head = (struct Node *)malloc(sizeof(struct Node));
        tail = head;
        head->data = val1;
        tail->next = NULL;
        tail->prev = NULL;
    }
    else {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val1;
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }
    
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val2;
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    head = newNode;
    
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val3;
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    head = newNode;
    
    traverser = tail;
    
    while(traverser != NULL){
        printf("%d ", traverser->data);
        traverser=traverser->prev;
    }
    
    return 0;
    
}
