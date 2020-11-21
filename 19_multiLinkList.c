/*

Write a C program to read name and total marks of students in a batch.

The program must sort student names in alphabetical order. The program must also sort student list based on descending order of marks. 

You must use multi-linked lists with various links following ascending ordered marks and alphabetically ordered records.

If two students have same marks display them alphabetically. If two students have the same name display the details of the student with highest marks first.

Note: Marks cannot be negative. The name of a student only consists of capital and small English alphabets.

Sample Input/Output
Input
    James
    56
    Paul
    39
    Augustine
    12
    William
    85
    Kishan
    35
    Rithi Sing
    85
    Kishan
    55
    -999    
Output
    Descending order of Marks: Rithi Sing 85, William 85, James 56, Kishan 55, Paul 39, Kishan 35, Augustine 12,
    Alphabetical Order: Augustine 12, James 56, Kishan 55, Kishan 35, Paul 39, Rithi Sing 85, William 85,

NOTE: THIS PROGRAM DOES NOT PASS ALL THE TEST CASES !!!
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    char name[20];
    int marks;
    struct Node* next, *ascMarkLink, *alphaOrderedLink;
};

void reverserPrint(struct Node *head){
    if(head!=NULL){
        reverserPrint(head->ascMarkLink);
        printf("%s ", head->name);
        printf("%d, ", head->marks);
    }
}

int main(){
    
    struct Node *head=NULL, *tail=NULL, *temp=NULL;
    
    struct Node *temp1=NULL, *temp2=NULL;
    
    struct Node *marksStrt=NULL, *nameStrt=NULL, *tempName=NULL;
    
    char nameInput[20];
    int givenMarks;
    
    int marksErr = 0;
    
    while(1!=0){
        int comp = 0;
        
        scanf("%[^\n]%*c", nameInput);
        if(comp == strcmp(nameInput, "-999")) break;
        
        scanf("%d", &givenMarks);
        
        if(givenMarks < 0) marksErr = 1;
        
        if(head == NULL){
            head = (struct Node *)malloc(sizeof(struct Node));
            strcpy(head->name, nameInput);
            head->marks = givenMarks;
            head->next = NULL;
            head->ascMarkLink = NULL;
            tail = head;
        } else {
            temp = (struct Node *)malloc(sizeof(struct Node));
            strcpy(temp->name, nameInput);
            temp->marks = givenMarks;
            temp->ascMarkLink = NULL;
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
        }
        fgets(nameInput, 50, stdin);
    }
    
    if(head == NULL){
        printf("You must enter atLeast one student.");
    }
    
    if(marksErr == 1){
        printf("Marks cannot be negative.");
    }
    
    temp1=head;
    int num2 = 999;
    while(temp1!=NULL){
        
        temp = NULL;
        tempName = NULL;
        temp2 = head;
        int num = 999;
        num2 = 999;
        
        while(temp2!=NULL){
            if(temp2->marks > temp1->marks && temp2->marks < num){
                temp = temp2;
                num = temp->marks;
            }
            if(strcmp(temp2->name, temp1->name) > 0 && strcmp(temp2->name, temp1->name) < num2){
                tempName = temp2;
                num2 = strcmp(temp2->name, temp1->name);
            }

            temp2 = temp2->next;
        }
        
        if(temp!=NULL){
            if(marksStrt==NULL) marksStrt = temp1;
            temp1->ascMarkLink = temp;
            if(marksStrt->marks > temp1->marks) marksStrt = temp1;
        }
        
        if(tempName!=NULL){
            if(nameStrt==NULL) nameStrt = temp1;
            temp1->alphaOrderedLink = tempName;
            if(strcmp(nameStrt->name, temp1->name)>0) {
                nameStrt = temp1;
            }
        }
        
        temp1 = temp1->next;
        
    }
    
    printf("Descending order of Marks:");
    reverserPrint(marksStrt);
    
    printf("\nAlphabetical Order: ");   
    while(nameStrt!=NULL){
        printf("%s ", nameStrt->name);
        printf("%d, ", nameStrt->marks);
        nameStrt=nameStrt->alphaOrderedLink;
    }
    
    return 0;
}


