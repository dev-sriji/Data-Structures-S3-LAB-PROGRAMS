/*Write a program to perform 
 * a. Linear search on N numbers
 * b. Binary search on N numbers - Iterative
 * c. Binary search on N numbers - Recursive

 * COMPILE AND RUN : ```gcc SEARCH.c -o Search.out && ./Search.out```
*/

#include <stdio.h>

int LinearSearch(int arr[],int key,int len);
int BinaryIterative(int arr[],int key,int len);
int BinaryRecursive(int arr[],int key,int start,int end);

void main() {
    int exit=0,res=0,num,arr[100],key;
    printf(">> Enter The Size Of The Array : ");
    scanf("%d",&num);
    printf(">> Enter The Elements\n");
    for(int i=0;i<num;i++){
        printf("%d)",i+1);
        scanf("%d",&arr[i]);
    }
    printf(">> Enter The Element To Search : ");
    scanf("%d",&key);
    int choice;
    printf(">> 1.Linear Search\n>> 2.Binary Search(Iterative)\n>> 3.Binary Search(Recursive)\nEnter The Choice : ");
    scanf("%d",&choice);
        switch(choice){
            case 1 : 
                res = LinearSearch(arr,key,num);
            break;
            case 2 : 
                res = BinaryIterative(arr,key,num);
            break;
            case 3 :
                res = BinaryRecursive(arr,key,0,num);
            break;
        }
    if(res > -1){
        printf(">> Your Element Is Found At Index  >> %d\n",res+1);
    } else {
        printf(">> Element Not Found !");
    }
}

int LinearSearch(int arr[],int key,int len){
    int res;
    for (int i = 0; i<len;i++){
        if(arr[i]==key){
            return i;
        }
    }
}

int BinaryIterative(int arr[],int key,int len){
    int start = 0, end = len;
    while (start <= end){
        int mid = (start + ((end - start)/2));
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] < key) {
            start = mid+1;
        } else if (arr[mid] > key){
            end = mid-1;
        }
    }
    return -1;
}

int BinaryRecursive(int arr[],int key,int start,int end){
    int mid = (start + ((end-start)/2));
    if (start > end) {
        return -1;
    } else if(arr[mid] == key) {
        return mid;
    } else if(arr[mid] < key) {
        return BinaryRecursive(arr,key,mid+1,end);
    } else if(arr[mid] > key) {
        return BinaryRecursive(arr,key,start,mid-1);
    }
}