/*

Write a C program to convert Infix expression to Postfix expression using linked list implementation of stacks.

Sample Input/Output I
Input
    A – (B / C + (D % E * F) / G) * H   
Output
    A B C / D E F * G / + H *

Sample Input/Output II
Input
    ( A + B * ( C - D ) ) / E   
Output
    A B C D - * + E /

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    char c;
    struct Node* next;
};

int prec(char ch){
    switch(ch){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

int main(){
    
    char infix[100];
    
    scanf("%[^\n]%*c", infix);
    
    int len = strlen(infix);
    
    if(len==0){
        printf("No Input detected");
        return 0;
    }
    
    infix[len] = ')';
    
    struct Node *head=NULL, *temp=NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    
    head->c = '(';
    
    char postfix[100];
    
    int postfixCounter = 0;
    int i=0;
    int hadOperators = 0;
    while(i<=len){
        if(infix[i]==' '){
            
        }
        else if(infix[i]=='('){
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->c = '(';
            temp->next = head;
            head = temp;
        } else if(infix[i]==')'){
            temp = head;
            while(head->c!='(' && head!=NULL){
                postfix[postfixCounter++] = head->c;
                head = head->next;
            }
            if(head!=NULL) head=head->next;
        } else if(infix[i]=='*' || infix[i]=='/' || infix[i]=='+' || infix[i]=='-' || infix[i]=='^'){
            while(head->c!='(' && head!=NULL && prec(head->c) >= prec(infix[i])){
                postfix[postfixCounter++] = head->c;
                head = head->next;
            }
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->c = infix[i];
            temp->next = head;
            head = temp;
        } else {
            postfix[postfixCounter++] = infix[i];
            hadOperators = 1;
        }
        
        i++;
    }
    
    if(hadOperators == 0){
        printf("Invalid input.");
        return 0;
    }
    
    while(head!=NULL){
        postfix[postfixCounter++] = head->c;
        head = head->next;
    }
    
    int x = 0;
    while(x<postfixCounter){
        printf("%c ", postfix[x++]);
    }
    
    return 0;
}
