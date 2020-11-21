/*

Read an array of ‘n’ integers from the user and do the following operations:

Search for a specific element in the array.
Sample Input/Output
Input:
    5
    17 42 16 18 39
    18
Output
    Element Found  at position 4    

*/

#include <stdio.h>

int main(){
    int n;
    
    scanf("%d", &n);
    
    int arr[n];
    
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    int ele;
    scanf("%d", &ele);
    
    int place[n], k=0;
    
    for(int i=0; i<n; i++){
        place[i] = 0;
    }
    
    for(int i=0; i<n; i++){
        if(arr[i]==ele){
            place[k++] = i+1;
        }
        
    }
    
    if(k == 0){
        printf("Element not Found");
    } else if( k == 1){
        printf("Element Found at position %d", place[0]);
    } else {
        printf("Element Found at positions %d", place[0]);
        for(int i=1; i<k; i++){
            printf(",%d", place[i]);
            
        }
    }
    
    return 0;
}
