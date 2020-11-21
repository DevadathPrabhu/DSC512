/*

Write a C program to implement priority queue using sorted linked list. 

Insert a minimum of five elements.  Display the priority queue.

Remove two elements and display the queue.

The input format is: Data followed by Priority value

Sample Input/Output
Input

25 9 85 6 -89 2 145 4 30 2 -999
Output

-89-->2, 30-->2, 145-->4, 85-->6, 25-->9

After removing two elements: 145-->4 85-->6 25-->9

*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

int main(){
  
  struct Node *head=NULL, *temp=NULL, *newNode=NULL, *prevNode=NULL, *priorityNode=NULL;
  
  int count = 1;
  
    while(1!=0){  
      int element=-9999;
      int priority=-9999;
      
      scanf("%d", &element);
      scanf("%d", &priority);
      
      if(element == -9999 && count<6){
          printf("Insert 5 elements");
          return 0;
      }
      
      if(element == -9999) break;
      
      count++;
  
      if(head==NULL){
          head = (struct Node *)malloc(sizeof(struct Node));
          head->data = element;
          head->priority = priority;
          head->next = NULL;
      }
      else {
          temp = head;
          priorityNode = NULL;
          prevNode = NULL;
          while(temp!=NULL){
              if(temp->priority > priority){
                  priorityNode = temp;
                  break;
              }
              prevNode = temp;
              temp = temp->next;
          }
          
          newNode = (struct Node *)malloc(sizeof(struct Node));
          newNode->data = element;
          newNode->priority = priority;
              
          if(priorityNode == NULL){
              newNode->next = NULL;
              prevNode->next = newNode;
          } else if(priorityNode == head){
              newNode->next = head;
              head = newNode;
          } else {
              prevNode->next = newNode;
              newNode->next = priorityNode;
          }
          
      }
  }
  
  
  
  temp = head;
  while(temp->next!=NULL){
      printf("%d-->%d, ", temp->data, temp->priority);
      temp = temp->next;
  }
  printf("%d-->%d", temp->data, temp->priority);
  
  head = head->next;
  head = head->next;
  
  printf("\nAfter removing two elements: ");
  temp = head;
  while(temp->next!=NULL){
      printf("%d-->%d, ", temp->data, temp->priority);
      temp = temp->next;
  }
  printf("%d-->%d", temp->data, temp->priority);
  
  
  return 0;
}
