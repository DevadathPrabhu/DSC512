/*

Write a C program to read a string from the user and check whether the string is a pangram or not.

A pangram is a sentence containing every letter in the English alphabet. If the sentence is not a pangram print the alphabets that are missing that will make the sentence a pangram.

For example, the sentence, “The quick brown fox jumps over the lazy dog” is a pangram as it contains all the characters from ‘a’ to ‘z’. The sentence “The quick brown fox jumps over the dog” is not a pangram because the characters ‘a’, ‘l’, ‘z’ and ‘y’ are missing.

Sample Input/Output
    Input:
    The five boxing wizards jump quickly
    Output
    Pangram
    Input:
    bcdefghijklmnopqrstuvwxz.
    Output
    Not Pangram
    a y

*/

#include<stdio.h>

int main(){
    
    char str[1000];
    int total = 0, present[26]={0};
    
    fgets(str, 1000, stdin);
    
    for(int i=0; str[i]!='\0'; i++){
        if('a'<=str[i] && str[i]<='z'){
            
            total+=!present[str[i]-'a'];
            present[str[i]-'a'] = 1;
        }
        else if('A'<=str[i] && str[i]<='Z'){
            
            total+=!present[str[i]-'A'];
            present[str[i]-'A'] = 1;
        }
    }
    
    if(total == 26){
    
        printf("Pangram");
    } else {
        printf("Not Pangram\n");
        for(int k=0; k<26; k++){
            if(present[k]==0){
                printf("%c ", k+97);
            }
        }
    }
    
    return 0;
}
