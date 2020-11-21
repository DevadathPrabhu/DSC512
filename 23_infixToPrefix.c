/*

Write a C program to convert Infix expression to Prefix expression using linked list implementation of stacks.

Sample Input/Output I
Input
    A – (B / C + (D % E * F) / G) * H   
Output
    * A – + / B C / % D * E F G H

Sample Input/Output II
Input
    ( A + B * ( C - D ) ) / E   
Output
    / + A * B - C D E

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
    char infix[50];
    char infix_rev[50];
    scanf("%[^\n]%*c", infix);
    
    int len=strlen(infix);
    
    if(len==0){
        printf("No input detected");
        return 0;
    }
    

    int k = 0, t = 0;
    for(k=len-1; k>=0; k--){
        if(infix[k]=='('){
            infix_rev[t++] = ')';
        } else if(infix[k]==')'){
            infix_rev[t++] = '(';
        } else {
            infix_rev[t++] = infix[k];
        }
    }
    
    infix_rev[t] = ')';

    
    struct Node *head=NULL, *temp=NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    
    head->c = '(';
    
    char postfix[100];
    
    int postfixCounter = 0;
    int i = 0;
    int hadOperators = 0;
    
    while(i<=len){
        if(infix_rev[i]==' '){
            
        } else if(infix_rev[i]=='('){
            temp = (struct Node*) malloc(sizeof(struct Node));
            temp->c = '(';
            temp->next = head;
            head = temp;
        } else if(infix_rev[i]==')'){
            while(head->c!='(' && head!=NULL){
                postfix[postfixCounter++] = head->c;
                head=head->next;
            }
            if(head!=NULL) head=head->next;
        } else if(infix_rev[i]=='*' || infix_rev[i]=='/' || infix_rev[i]=='+' || infix_rev[i]=='-' || infix_rev[i]=='^'){
            while(head->c!='(' && head!=NULL && prec(head->c) >= prec(infix_rev[i])){
                postfix[postfixCounter++] = head->c;
                head=head->next;
            }
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->c = infix_rev[i];
            temp->next = head;
            head=temp;
        } else {
            postfix[postfixCounter++] = infix_rev[i];
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
    
    int x = postfixCounter-1;
    while(x>=0){
        printf("%c ", postfix[x--]);
    }
    
    return 0;
    
}
