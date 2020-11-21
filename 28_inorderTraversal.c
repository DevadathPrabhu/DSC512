/*

Write a C program to read a binary tree from the user and perform In-order Traversal.

Sample Input/Output
Input

Sample Input for the binary tree given below will be

A  -999

A B C -999     [Comment: A is the parent, B is the left child and C is the right child ]

B D E -999

C NULL F -999  [Comment: NULL is entered because C does not have a left child and F is the right child]

D G H -999

F I J -999

H NULL L -999

J K NULL -999

-999

Output

In-order Traversal: G, D, H, L, B, E, A, C, I, F, K, J

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int printed = 0;

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int data){
    struct node* thisNode = (struct node*) malloc(sizeof(struct node));
    thisNode->data = data;
    thisNode->left = NULL;
    thisNode->right = NULL;
    
    return (thisNode);
}

struct node* getRootNode(struct node* node, char data){
    
    struct node *ans = NULL;
    
    if(node == NULL) return NULL;
    
    if(node->data == data) return node;
    
    if(ans == NULL){
        ans = getRootNode(node->left, data);
    }
    
    if(ans == NULL){
        ans = getRootNode(node->right, data);
    }
    
    return ans;
    
}

void inorder(struct node* node){
    
    if(node == NULL) return;
    
    inorder(node->left);
    
    if(printed == 0) {
        printf("%c", node->data);
        printed = 1;   
    } else {
        printf(", %c", node->data);
    }
    
    inorder(node->right);
}

int main(){
    
    struct node *root=NULL, *addToThis, *right;
    
    char input[100];
    
    while(1!=0){
        
        char r, l, ri;
        
        scanf("%[^\n]%*c", input);
        
        int len = strlen(input);
        
        if(input[0]=='-') break;
        
        r = input[0];
        ri = '?';
        l = '?';
            
        if(input[2]!= '-'){
            if(input[2]!='N' && input[3]!='U'){
                l = input[2];
                if(input[4]!='N' && input[5]!='U'){
                    ri = input[4];
                }
                else {
                    ri = '?';
                }
            } else {
                l = '?';
                if(input[7]!='N' && input[8]!='U'){
                    ri = input[7];
                }
                else {
                    ri = '?';
                }
                
            }
        }
        
        // printf("%c ", r);
        // printf("%c ", l);
        // printf("%c\n", ri);
        
        if(root == NULL){
            root = newNode(r);
            if(l!='?')
                root->left = newNode(l);
            if(ri!='?')    
                root->right = newNode(ri);
        } else {
            addToThis = getRootNode(root, r);
            
            if(addToThis!=NULL){
                if(l!='?')
                    addToThis->left = newNode(l);
                if(ri!='?')    
                    addToThis->right = newNode(ri);
            } else {
                printf("Root not found to add");
            }
        }
    }
    
    if(root!=NULL){
        printf("In-order Traversal: ");
        inorder(root);
    } else {
        printf("Empty Tree");
    }
    
    return 0;
}
