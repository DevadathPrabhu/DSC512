/*

Create a doubly linked circular list. Delete the last element in the doubly linked circular list.

Sample Input/Output
Input
    84 19 32 45 25 39 -999    
Output
    84 19 32 45 25

*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main(){
    
    struct Node *head=NULL, *tail=NULL, *temp;
    int value;
    
    while(1!=0){
        
        scanf("%d", &value);

        if(value == -999) break;
        
        if(head == NULL){
            head = (struct Node *)malloc(sizeof(struct Node));
            tail = head;
            head->data = value;
            tail->next = head;
            tail->prev = head;
            head->prev = tail;
            head->next = tail;
        } else {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = value;
            temp->next = head;
            head->prev = temp;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }
    
    if(tail == NULL){
        printf("Underflow !!! Empty Linked List.");
        return 0;
        
    } else if(tail == head){
        head = NULL;
        tail = NULL;
        free(tail);
        printf("Empty Linked List !!!");
        return 0;
    } else {
        temp = tail->prev;
        head->prev = temp;
        temp->next = head;
        tail->next = NULL;
        tail->prev = NULL;
        free(tail);
        tail = temp;
    }
    
    temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp!=head);
    
    return 0;
}
