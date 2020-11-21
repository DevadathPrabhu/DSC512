/*

Read an array of ‘n’ integers from the user and do the following operations:

Sort the array in ascending order.
Sort the array in descending order.
Sample Input/Output
    Input:
    5
    17 42 16 18 39
    Output
    16 17 18 39 98
    98 39 18 17 16

*/

#include<stdio.h>

int main(){
    
    int n;
    
    scanf("%d", &n);
    
    int arr[n], asc[n], desc[n];
    
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n; j++){
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    for(int i=n-1; i>=0; i--){
        printf("%d ", arr[i]);
    }
    
    
    return 0;
    
}
