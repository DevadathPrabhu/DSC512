/*

Write C program to find the Huffman encoding for a given String.

Sample Input/Output
Input

sseasoseoeaieiestseossieiaeiuiaieeiaeueaiuiasaeieauasisess

Output [Note: Huffman Code must be displayed in alphabetical order to match with the test cases]
a = 111

e = 10

i = 00

o = 11001

s = 01

t = 11000

u = 1101

NOTE: THIS PROGRAM DOES NOT PASS ALL THE TEST CASES !!! Works only on lower case alphabets.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TREE_HT 100

char answers[26][100];
int totalAns = 0;

struct MinHeapNode {
    char data;
    
    unsigned freq;
    
    struct MinHeapNode *left, *right;
};

struct MinHeap{
    unsigned size;
    unsigned capacity;
    
    struct MinHeapNode** array;
};

struct MinHeapNode* newNode(char data, unsigned freq){
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    
    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity){
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    
    minHeap->size = 0;
    minHeap->capacity = capacity;
    
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity*sizeof(struct MinHeapNode*));
    
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b){
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx){
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if(left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) smallest=left;
    
    if(right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) smallest=right;
    
    if(smallest!=idx){
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap){
    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap){
    struct MinHeapNode* temp = minHeap->array[0];
    
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    
    --minHeap->size;
    
    minHeapify(minHeap, 0);
    
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode){
    ++minHeap->size;
    
    int i = minHeap->size - 1;
    
    while(i && minHeapNode->freq < minHeap->array[(i-1)/2]->freq){
        minHeap->array[i] = minHeap->array[(i-1)/2];
        i=(i-1)/2;
    }
    
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap){
    int n = minHeap->size - 1;
    int i;
    
    for(i=(n-1)/2; i>=0; --i) minHeapify(minHeap, i);
}

int isLeaf(struct MinHeapNode* root){
    
    return !(root->left) && !(root->right);
    
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size){
    struct MinHeap* minHeap = createMinHeap(size);
    
    for(int i=0; i<size; ++i){
        minHeap->array[i] = newNode(data[i], freq[i]);
    }
    
    minHeap->size = size;
    buildMinHeap(minHeap);
    
    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size){
    struct MinHeapNode *left, *right, *top;
    
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    
    while(!isSizeOne(minHeap)){
        left=extractMin(minHeap);
        right=extractMin(minHeap);
        
        top=newNode('$', left->freq+right->freq);
        top->left = left;
        top->right = right;
        
        insertMinHeap(minHeap, top);
    }
    
    return extractMin(minHeap);
}

void printArr(int arr[], int n){
    int i;
    for(i=0; i<n; ++i){
        printf("%d", arr[i]);
    }
    printf("\n");
}

void printCodes(struct MinHeapNode* root, int arr[], int top){
    
    char temp[100];
    
    if(root->left){
        arr[top]=0;
        printCodes(root->left, arr, top+1);
    }
    if(root->right){
        arr[top]=1;
        printCodes(root->right, arr, top+1);
    }
    
    if(isLeaf(root)){
        temp[0]=root->data;
        temp[1]='=';
        int j = 2;
        for(int i=0; i<top; ++i){
            temp[j++] = arr[i]+'0';
        }
        
        for(int k=0; k<top+2; k++){
            answers[totalAns][k] = temp[k];
        }
        totalAns++;
    }
}

void sortPrint(char arr[26][100]){
    char temp[100];
    for(int i=0;i<totalAns-1;i++){
        for(int j=i+1; j<totalAns; j++){
            if(strcmp(arr[i], arr[j])>0){
                strcpy(temp, arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j], temp);
            }    
        }
    }
    
    for(int k=0; k<totalAns; k++){
        printf("%s\n", arr[k]);
    }
    
}

void huffmanCodes(char data[], int freq[], int size){
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    
    int arr[MAX_TREE_HT], top = 0;
    
    printCodes(root, arr, top);
    
    sortPrint(answers);
    
    // for(int k=0; k<totalAns; k++){
    //     printf("%s\n", answers[k]);
    // }
}

int main(){
    
    char input[100];
    
    scanf("%[^\n]%*c", input);
    
    int len = strlen(input);
    
    int i=0;
    
    int frequency[26]={0};
    
    while(i<len){
        frequency[input[i]-'a']++;
        i++;
    }
    
    int count = 0;
    for(int x=0; x<26; x++){
        if(frequency[x]!=0) count++;
    }
    
    
    char arr[count];
    int freq[count];
    
    int k=0;
    for(int j=0; j<26; j++){
        if(frequency[j]!=0){
            arr[k] = j+'a';
            freq[k] = frequency[j];
            k++;
        }
    }
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    huffmanCodes(arr, freq, size);
    
    return 0;
}
