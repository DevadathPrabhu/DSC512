/*

Write a C program to implement stack data structure using linked lists.

Do the following operations:

PUSH a few elements into the stack. (Minimum 4 elements)
Do a PEEK operation.
Do three consecutive POP operations and display the elements.
Display the entire contents of the remaining Stack.
Sample Input/Output 1
Input
    42 19 32 45 42 39 45 25 36 -999
Output
   Peek: 36
   POP operations: 36 25 45
   Contents of the remaining Stack: 39 42 45 32 19 42

*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main(){
    
    struct Node *top = NULL, *temp = NULL;
    int totalNodes = 0;
    
    while(1!=0){
        int element;
        
        scanf("%d", &element);
        
        if(element == -999) break;
        
        if(top == NULL){
            top = (struct Node *)malloc(sizeof(struct Node));
            top->data = element;
            top->next = NULL;
            totalNodes++;
        } else {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = element;
            temp->next = top;
            top = temp;
            totalNodes++;
        }
    }
    
    if(totalNodes < 4){
        printf("Minimum 4 elements must be entered.");
        return 0;
    }
    
    if(top != NULL){
        printf("Peek: %d\n", top->data);
    
    
        int count = 1;
        printf("POP operations: ");
        while(top!=NULL && count<4){
            printf("%d ", top->data);
            top = top->next;
            count++;
        }
        
        temp=top;
        if(top!=NULL) printf("\nContents of the remaining Stack: ");
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }

    }
    
    return 0;
}
