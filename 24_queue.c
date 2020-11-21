/*

Write a C program to implement Queue data structure using linked lists.

Do the following operations:

Insert few elements into the queue. (Minimum 4 elements)
Display the element at the front of the queue (Do not remove it from the Queue).
Remove and display three elements from the Queue.
Display the entire contents of the remaining Queue.
Sample Input/Output
Input

42 77 88 9 3 66 -999

Output

Element at the front of the queue: 42

Remove and display three elements: 42 77 88

Contents of the remaining queue: 9 3 66

*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main(){
    
    struct Node *front=NULL, *rear=NULL, *temp=NULL;
    
    int totalNodes = 0;
    
    while(1!=0){
        
        int ele;
        scanf("%d", &ele);
        
        if(ele == -999) break;
        
        if(front==NULL){
            front = (struct Node *)malloc(sizeof(struct Node));
            front->data = ele;
            front->next = NULL;
            rear = front;
            totalNodes++;
        } else {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = ele;
            temp->next = NULL;
            rear->next = temp;
            rear = temp;
            totalNodes++;
        }
    }
    
    if(totalNodes < 4){
        printf("Minimum 4 elements must be entered.");
        return 0;
    }
    
    if(front != NULL){
        printf("Element at the front of the queue: %d\n", front->data);
        
        int count = 1;
        printf("Remove and display three elements: ");
        while(front!=NULL && count<4){
            printf("%d ", front->data);
            if(front == rear){
                rear = NULL;
            }
            front = front->next;
            count++;
        }
        
        temp=front;
        if(temp!=NULL) printf("\nContents of the remaining queue: ");
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    
    return 0;
}
