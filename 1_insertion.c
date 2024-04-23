#include <stdio.h>

void printArray(int *A, int n)
{
    printf("The elements are \n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    
}
void insertionSort(int *A, int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
         printf(" \n After pass %d: ", i);
        printArray(A, n);
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
    insertionSort(A, n);
    printArray(A, n);
}