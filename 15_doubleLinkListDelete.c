/*

Create a doubly linked list. 

Delete 3 elements from the end of the linked list. Display the elements of the resulting doubly linked list in reverse order.

Sample Input/Output
Input
    84 19 32 45 25 39 -999    
Output
    32 19 84

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
    int totalNodes = 0;
    
    while(0!=1){
        
        int value;
        
        scanf("%d", &value);
        
        if(value == -999) break;
        
        
        if(head == NULL){
            totalNodes = 1;
            head = (struct Node *)malloc(sizeof(struct Node));
            tail = head;
            head->data = value;
            tail->next = NULL;
            tail->prev = NULL;
        }
        else {
            totalNodes++;
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    int toDelete = 3;
    if(totalNodes >= 3){
        while(toDelete > 0){
            newNode = tail;
            if(tail->prev == NULL) tail == NULL;
            else {
                tail = tail->prev;
                tail->next = NULL;
                newNode->prev = NULL;
            }
            newNode = NULL;
            free(newNode);
            toDelete--;
        }
    } else {
        printf("Error!! Underflow, Minimum 3 elements are required.");
        return 0;
    }
    
    traverser = tail;
    
    if(totalNodes == 3){
        printf("NULL");
        return 0;
    }
    
    while(traverser != NULL){
        printf("%d ", traverser->data);
        traverser=traverser->prev;
    }
    
    
    return 0;
}
