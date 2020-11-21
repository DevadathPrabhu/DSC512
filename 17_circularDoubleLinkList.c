/*

Create a doubly linked circular list. 

Delete the 3rd element in the doubly linked circular list. Display the elements of the resulting linked list in reverse order.

Sample Input/Output
Input
    84 19 32 45 25 39 -999    
Output
    39 25 45 19 84

*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main(){
    
    struct Node *head, *tail, *temp, *traverser;
    
    
    while(1!=0){
        int value;
        
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
    
    
    traverser = head;
    
    int count = 0;
    
    if(head != NULL){
        do{
            count++;    
            if(count == 3){
                temp = traverser->prev;
                temp->next = traverser->next;
                traverser->next->prev = temp;
                traverser->next = NULL;
                traverser->prev = NULL;
                if(traverser == tail){
                    tail = temp;
                }
                free(traverser);
                break;
            }
            traverser = traverser->next;
        }while(traverser!=head);
    }
    
    if(count < 3){
        printf("Underflow !!! Minimum 3 elements must be entered.");
    }
    else {
        traverser = tail;
        do{
            printf("%d ", traverser->data);
            traverser = traverser->prev;
        }while(traverser!=tail);
    }
    return 0;
}
