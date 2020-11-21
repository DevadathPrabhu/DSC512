/*

Create a doubly linked list. Make sure one of the entered elements is 24.

Insert a new element after the existing linked list element 24. If there are more than one occurrence of 24, give user the choice where the new element must be inserted.

Sample Input/Output
Input
    24 19 32 45 24 39 -999
     -56
Output
    2 occurrence of 24 found. Where should the insertion occur?
Input
    1
Output
    24 -56 19 32 45 24 39

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
    
    int count = 0;
    
    while(0!=1){
        int value;
        
        scanf("%d", &value);
        
        if(value == -999) break;
        
        if(value == 24) count++;
        
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
    
    int insert;
    int pos=1;
    
    if(count == 0){
        printf("At Least one element must be 24.");
        return 0;
    }
    
    scanf("%d", &insert);
    
    

    if(count > 1){
        printf("%d occurrence of 24 found. Where should the insertion occur?", count);
        scanf("%d", &pos);
    }
    
    traverser = head;
    
    if(pos==0){
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = insert;
        while(traverser->data!=24){
            traverser=traverser->next;
        }
        newNode->next = traverser;
        newNode->prev = traverser->prev;
        if(traverser->prev != NULL)
            traverser->prev->next = newNode;
        traverser->prev = newNode;
        if(newNode->prev == NULL)
            head = newNode;
    } else {
        while(pos>0){
            if(traverser->data == 24){
                pos--;
            }
            if(pos==0){
                newNode = (struct Node *)malloc(sizeof(struct Node));
                newNode->data = insert;
                newNode->prev = traverser;
                newNode->next = traverser->next;
                if(traverser->next != NULL)
                    traverser->next->prev = newNode;
                traverser->next = newNode;
                
                break;
            }
            traverser=traverser->next;
        }
    }
    
    traverser = head;
    while(traverser != NULL){
        printf("%d ", traverser->data);
        traverser = traverser->next;
    }
    
    
    return 0;
}
