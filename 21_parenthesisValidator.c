/*

Write a C program for parenthesis checking using linked list implementation of stack.

Sample Input/Output I
Input
    [56 + 29 {a – b (m + n) * u} + 89]    
Output
    Parenthesis Matched.

Sample Input/Output II
Input
    [ p + q {m + 8 ] * c { -4 / b ) }    
Output
    Parenthesis Mismatched.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int data;
    struct Node* next;
};

int main(){
    struct Node *top = NULL, *temp = NULL;
    
    char input[100];
    scanf("%[^\n]%*c", input);
    
    int length = strlen(input);
    
    int i = 0;
    int hadBrackets = 0;
    
    while(i < length){
        if(input[i] == '[' || input[i] == '{' || input[i] == '('){
            if(top == NULL){
                hadBrackets = 1;
                top = (struct Node *)malloc(sizeof(struct Node));
                top->data = input[i];
                top->next = NULL;
            } else {
                temp = (struct Node *)malloc(sizeof(struct Node));
                temp->data = input[i];
                temp->next = top;
                top = temp;
            }
        }
        else {
            if(input[i] == ']'){
                if(top == NULL){
                    printf("Parenthesis Mismatched.");
                    return 0;
                }
                if(top->data == '['){
                    top = top->next;
                } else {
                    printf("Parenthesis Mismatched.");
                    return 0;
                }
                
            }
            if(input[i] == '}'){
                if(top == NULL){
                    printf("Parenthesis Mismatched.");
                    return 0;
                }
                if(top->data == '{'){
                    top = top->next;
                } else {
                    printf("Parenthesis Mismatched.");
                    return 0;
                }
                
            }
            if(input[i] == ')'){
                if(top == NULL){
                    printf("Parenthesis Mismatched.");
                    return 0;
                }
                if(top->data == '('){
                    top = top->next;
                } else {
                    printf("Parenthesis Mismatched.");
                    return 0;
                }
                
            }
        }
        i++;
    }
    
    if(hadBrackets == 1){
        printf("Parenthesis Matched.");
    } else {
        printf("No Parenthesis found.");
    }
    
    return 0;
}
