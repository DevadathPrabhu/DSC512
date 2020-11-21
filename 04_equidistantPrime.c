/*

Write a C program to generate prime numbers which has two equidistant prime numbers from it within a given range.

For example, 5 is one such number because we have two prime numbers 3 and 7 both of which are equidistant from 5. The distance in this case would be 2.

Can you generate all such numbers within a given range along with their corresponding two prime numbers and distance?

Sample Input/Output
    Input:
    2 10
    Output
    3 5 7 2

    Input
    10 30
    Output
    11 17 23 6                                                                                                                                                     
    17 23 29 6

*/

#include<stdio.h>

int main(){
    
    int start, end;
    scanf("%d %d", &start, &end);
    
    int prime[end-start+2];
    
    int primeIndex=0;
    
    if(start < 0){
        start = 2;
    }
    
    for(int i=start; i<=end; i++){
        int isPrime = 0;
        for(int j=2; j<=(i/2); j++){
            if(i%j==0){
                isPrime++;
                break;
            }
        }
        
            if(isPrime == 0){
                prime[primeIndex++] = i;
            }
    }
    
    int mid = 1, back, front;
    
    while(mid<=primeIndex){
        
        back = mid-1;
        front = mid+1;
        
        if(prime[mid]-prime[back] == prime[front]-prime[mid]){
            printf("%d %d %d %d", prime[back], prime[mid], prime[front], prime[front]-prime[mid]);
            printf("\n");
        }
        
        while(back>=0 && front<=primeIndex){
            if(prime[mid]-prime[back] < prime[front]-prime[mid]){
                back--;
            }
            else if(prime[mid]-prime[back] > prime[front]-prime[mid]){
                front++;
            }
            else {
                back--;
                front++;
            }
            
            if(prime[mid]-prime[back] == prime[front]-prime[mid]){
                printf("%d %d %d %d", prime[back], prime[mid], prime[front], prime[front]-prime[mid]);
                printf("\n");
            }
        }
        
        mid++;
    }
    
    return 0;
}
