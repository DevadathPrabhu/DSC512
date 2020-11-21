/* Write a C program to read an integer from the user and check whether it is a palindrome or not. The program should output the number and say whether it is a palindrome or not.

After printing it, can you reverse the order of digits in the number the user has just entered. E.g. 1234 should become 4321. Display the result on the screen in an easily understandable format.

Sample Input/Output
    Input:
    121
    Output
    Palindrome
    121

    Input
    1143
    Output
    Not Palindrome
    3411
*/

#include<stdio.h>

int main(){
    
    int num, temp;
    scanf("%d", &num);
    
    
    int neg = 0;
    
    if(num<0){
        neg = 1;
        num = num * -1;
    }
    temp = num;
    
    int rev = 0;
    
    while(num>0){
        int rem = num % 10;
        rev = (rev * 10) + rem;
        num = num/10;
        
    }
    
    
    
    if(temp == rev){
        
        
        if(temp!=0 && temp % 10 == 0 && neg!=1){
            printf("Palindrome\n0%d", rev);
        } else if(temp % 10 == 0 && neg==1){
            printf("Palindrome\n-0%d", rev);
        } else {
            if(neg==1){
                rev = rev * -1;
            }
            printf("Palindrome\n%d", rev);
        }
        
    }
    else {
        if(temp % 10 == 0 && neg!=1){
            printf("Not Palindrome\n0%d", rev);
        } else if(temp % 10 == 0 && neg==1){
            printf("Not Palindrome\n-0%d", rev);
        } else {
            if(neg==1){
                rev = rev * -1;
            }
            printf("Not Palindrome\n%d", rev);
        }
    }
    
    
    return 0;
}
