/*

Write a C program to build a Binary Search Tree using the following elements: 45, 39, 56, 12, 34, 78, 32, 10, 89, 54, 67, 81

Do In-order Traversal on the constructed Binary Search Tree.

Sample Input/Output
Input

45, 39, 56, 12, 34, 78, 32, 10, 89, 54, 67, 81, -999
Output 

In-order Traversal of the Binary Search Tree Constructed: 10, 12, 32, 34, 39, 45, 54, 56, 67, 78, 81, 89

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

struct node* newNode(int token){
    
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = token;
    temp->left = temp->right = NULL;
        
    return temp;
}

struct node* insert(struct node* root, int token){
    
    if(root==NULL)
        return newNode(token);
    
    if(token < root->data){
        root->left = insert(root->left, token);
    } else {
        root->right = insert(root->right, token);
    }
    
    return root;
    
}

void inorder(struct node* node){
    if(node == NULL) return;
    
    inorder(node->left);
    
    if(printed==0){
        printed=1;
        printf("%d", node->data);
    } else {
        printf(", %d", node->data);
    }
    
    inorder(node->right);
}

void main(){
    
    char input[200];
    struct node* tree=NULL;
        
    scanf("%[^\n]%*c", input);
    
    char *token;
    
    token = strtok(input, ", ");
    
    while(token != NULL){
        
        if(strcmp(token, "-999")==0) break;
        
        // tree;
        int key = atoi(token);
        if(tree==NULL){
            tree = insert(tree, key);
        } else {
            insert(tree, key);
        }
        
        
        token = strtok(NULL, ", ");
    }

    if(tree!=NULL){
        printf("In-order Traversal of the Binary Search Tree Constructed: ");
        inorder(tree);
    } else {
        printf("Tree not found");
    }
    
    
}
