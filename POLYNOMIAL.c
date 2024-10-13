/**
  * Question
  * Write a program to read two polynomials and store them in an array. Calculate the sum of the two polynomials and display the first, second and the resultant polynomial.
  * 
  * Compile and Run Command : clear && gcc POLYNOMIAL.c -o POLYNOMIAL.out && ./POLYNOMIAL.out
**/

#include <stdio.h>
#define MAX 10

void readPoly (int* arr, int n){
    int temp;
    printf("Enter the polynomial\n");
    for(int i=0;i<n;i++) {
        printf("x^%d :",i);
        scanf("%d",arr + i);
    }
}

void displayPoly (int arr[], int n){
    int isFirst = 1;
    while(n>=0) {
        if(arr[n] != 0) {
            if(!isFirst)
                printf("+");
            else 
                isFirst = 0;
            if(n == 0){
                printf("%d", arr[n]);
            } else {
                printf("%dx",arr[n]);
                if(n>1) {
                    printf("^%d", n);
                }
            }
        }
        n--;
    }
        printf("\n");
}

void addPoly(int n,int arr1[],int arr2[],int* arr3){
    int i =0;
    while(i<n) {
        arr3[i] = arr2[i] + arr1[i];
        i++;
    }
}

void main() {
    int max_deg;
    printf("Enter The Highest Degree of The Polynomial : \n");
    scanf(" %d",&max_deg);
    max_deg++;
    int poly1[MAX],poly2[MAX],result[MAX];
    printf("Polynomial 1 : \n");
    readPoly(poly1,max_deg);
    printf("Polynomial 2 : \n");
    readPoly(poly2,max_deg);
    printf("\n\nCalculating the results\n--- --- ---\n");
    addPoly(max_deg,poly1,poly2,result);
    printf("Polynomial 1 : \n");
    displayPoly(poly1,max_deg);
    printf("Polynomial 2 : \n");
    displayPoly(poly2,max_deg);
    printf("Result : \n");
    displayPoly(result,max_deg);
}

