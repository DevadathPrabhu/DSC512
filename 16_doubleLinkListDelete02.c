/*

Create a doubly linked list. Make sure one of the entered elements is 42.

Delete an element before the existing linked list element 42. If there are more than one occurrence of 42, give user the choice where the new element must be deleted.

Sample Input/Output 1
Input
    42 19 32 45 42 39 -999
Output
    2 occurrence of 42 found. Where should the deletion occur?
Input
    2
Output
    42 19 32 42 39

Sample Input/Output 2
Input
    42 19 32 45 42 39 -999
Output
    2 occurrence of 42 found. Where should the deletion occur?
Input
    1
Output
    No element before 42

*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main(){
    
    struct Node *head, *tail, *temp, *traverser;
    
    int count = 0;
    
    while(1!=0){
        
        int value;
        
        scanf("%d", &value);
        
        if(value == -999) break;
        
        if(value == 42) count++;
        
        if(head == NULL){
            head = (struct Node *)malloc(sizeof(struct Node));
            tail = head;
            head->data = value;
            tail->next = NULL;
            tail->prev = NULL;
        } else {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = value;
            temp->prev = tail;
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
        }
    }
    
    if(count == 0){
        printf("At least one element must be 42.");
        return 0;
    }
    
    int pos=1;
    
    if(count>1){
        printf("%d occurrence of 42 found. Where should the deletion occur?", count);
        scanf("%d", &pos);
        printf("\n");
    }
    
    traverser = head;
    
    int occurrence = 0;
    while(traverser != NULL){
        if(traverser->data == 42) occurrence++;
        
        if(occurrence == pos){
            if(traverser->prev == NULL) {
                printf("No element before 42");
                return 0;
            }
            
            temp = traverser->prev;
            
            if(temp->prev !=NULL)
                temp->prev->next = temp->next;
            
            if(temp->prev == NULL){
                head = temp->next;
            }
            
            temp->next->prev = temp->prev;
            temp->next = NULL;
            temp->prev = NULL;
            temp=NULL;
            free(temp);
            break;
        }
        
        traverser=traverser->next;
    }
    
    traverser = head;
    
    while(traverser != NULL){
        printf("%d ", traverser->data);
        traverser = traverser->next;
    }
    
    
    return 0;
}
