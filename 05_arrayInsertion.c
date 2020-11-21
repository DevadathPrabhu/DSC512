/*

Read an array of ‘n’ integers from the user and do the following operations:

Insert an element at a specific position in the array.
Sample Input/Output
Input:
    5
    17 42 16 18 39
     2 98 
    Output         
     17 98 42 16 18 39    

*/

#include<stdio.h>

int main(){
    int n;
    
    scanf("%d", &n);
    
    int arr[n+1];
    
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    int indexToAdd, valToAdd;
    
    scanf("%d %d", &indexToAdd, &valToAdd);
    
    if(indexToAdd-1 > n || indexToAdd < 1){
        printf("Out of Bound");
    }
    else{
        for(int i=n; i>=indexToAdd-1; i--){
            if(i>0)
                arr[i] = arr[i-1];
        }
        
        arr[indexToAdd-1] = valToAdd;
        
        for(int i=0; i<=n; i++){
            printf("%d ", arr[i]);
        }
    }
    
    return 0;
    
    
}
