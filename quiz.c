/*

Create a singly linked list and Insert an element before a particular element. If there are more than one similar elements in the linked list, add the element before the last occurrence.

Sample Input/Output I
Input:
    17 42 16 18 39 -999
    16 87
Output
    17 42 87 16 18 39    

Sample Input/Output II
Input:
    17 42 16 18 39 16 -999
    16 87
Output
    17 42 16 18 39 87 16

Sample Input/Output III
Input:
    -999
    16 87
Output
    Empty Linked List

Sample Input/Output IV
Input:
    56 26 14 -999
    16 87
Output
    Error!!! Element Not Found

*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main(){
    
    struct Node *head=NULL, *temp=NULL, *anotherNode=NULL, *newNode=NULL;
    
    while(1!=0){
        int element;
        
        scanf("%d", &element);
        
        if(element == -999){
            break;
        }
        
        if(head==NULL){
            head = (struct Node *)malloc(sizeof(struct Node));
            head->data = element;
            head->next = NULL;
            temp = head;
        }
        else {
            anotherNode = (struct Node *)malloc(sizeof(struct Node));
            anotherNode->data = element;
            anotherNode->next = NULL;
            temp->next = anotherNode;
            temp = temp->next;
        }
    }
    
    int insertBefore, insertEle;
    
    scanf("%d", &insertBefore);
    scanf("%d", &insertEle);
    
    if(head == NULL){
        printf("Empty Linked List");
        return 0;
    }
    
    temp = head;
    
    
    
    anotherNode = NULL;
    
    while(temp!=NULL){
        if(temp->data==insertBefore){
            anotherNode = temp;
        }
        temp=temp->next;
    }
    
    if(anotherNode==NULL){
        printf("Error!!! Element Not Found");
        return 0;
    }
    
    temp = head;
    
    while(head!=anotherNode && temp->next!=anotherNode){
        temp=temp->next;
    }
    
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = insertEle;
    newNode->next = anotherNode;
    
    if(anotherNode == head){
        head = newNode;
    }
    else {
        temp->next = newNode;
    }
    
    while(head!=NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    
    return 0;
}
