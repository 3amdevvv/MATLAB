#include <stdio.h>

void printArray(int *A, int n)
{
    printf("The elements are \n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    
}

void selectionSort(int *a,int n){
    int indexofmin,temp;
    for(int i=0;i<n-1;i++){
        indexofmin=i;
        for(int j=i+1;j<n;j++){
             if(a[j] < a[indexofmin]){
                indexofmin=j;
             }
        }
        temp=a[i];
        a[i]=a[indexofmin];
        a[indexofmin]=temp;
        printf("After each pass \n");
        printArray(a,n);
    }
}
int main()
{
    int n, A[100];
    printf("Enter the value of n \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
}