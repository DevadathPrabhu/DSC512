/*

Read an array of ‘n’ integers from the user and do the following operations:

Delete an element from the array.
Sample Input/Output
Input:
    5
    17 42 16 18 39
    3
Output
  17 42 18 39     

*/

#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    int arr[n];
    
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    int toDel;
    scanf("%d", &toDel);
    
    int newArr[n], k=0;
    
    for(int i=0; i<n; i++){
        if(i+1!=toDel){
            newArr[k++] = arr[i];
        }
        
    }
    
    if(k==0 || toDel < 1 || toDel > n){
        printf("Out of bound");
    }
    else {
        for(int i=0; i<k; i++)
            printf("%d ", newArr[i]);
    }
    return 0;
}
