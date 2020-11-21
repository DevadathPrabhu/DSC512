/*

Write C program for array implementation of circular queue with maximum size of six.

Remove three elements from the circular queue and display the queue. Display the value of FRONT and REAR.

Add two elements into the circular queue and display the queue. Display the value of FRONT and REAR.


Sample Input/Output
Input

42 77 88 9 3 66 -999

Output

Circular Queue: 9 3 66

FRONT = 3, REAR = 5

Contents of the remaining queue: 9 3 66

Input
-89 -63

Output

9 3 66 -89 -63

FRONT = 3, REAR = 1

*/

#include<stdio.h>
#include<stdlib.h>

int size = 6;
int circularQ[6];
int front = -1;
int rear = -1;
    

void enqueue(int input){
        if((front==0 && rear==size-1) || (rear == (front-1)%(size-1))){
            printf("Queue is full");
        } else if(front == -1){
            front = 0;
            rear = 0;
            circularQ[rear] = input;
        } else if(rear == size-1 && front!=0){
            rear = 0;
            circularQ[rear] = input;
        } else {
            rear++;
            circularQ[rear] = input;
        }
}

void printQ(){
    if(rear >= front){
        for(int i = front; i<=rear; i++){
            printf("%d ", circularQ[i]);
        }
    } else {
        for(int i = front; i<size; i++){
            printf("%d ", circularQ[i]);
        }
        for(int i = 0; i<=rear; i++){
            printf("%d ", circularQ[i]);
        }
    }
}

int main(){
    
    int input, total=0;
    
    while(1!=0){
        scanf("%d", &input);
        if(input == -999) break;
        
        total++;
        if(total > 6){
            printf("Out of bound");
            return 0;
        }
        
        enqueue(input);
    }
    
    int times = 1;
    
    while(times<=3){
        times++;
        
        if(front == -1){
            printf("Empty Queue. Three elements should be deleted.");
            return 0;
        }
        
        if(front == rear){
            front = -1;
            rear = -1;
        } else if (front == size-1){
            front = 0;
        } else {
            front++;
        }
    }
    
    printf("Circular Queue: ");
    printQ();
    
    printf("\nFRONT = %d, REAR = %d\n", front, rear);
    
    printf("Contents of the remaining queue: ");
    printQ();
    
    printf("\n");
    
    int count = 1;
    while(count<=2){
        count++;
        scanf("%d", &input);
        enqueue(input);
    }
    
    printQ();
    
    printf("\nFRONT = %d, REAR = %d", front, rear);
    
    return 0;
}
