#include <stdio.h>

int calls = 0; // Global variable to count the number of calls to quicksort

void printArray(int *A, int n)
{
    printf("The elements are \n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("\n");
}

int partition(int *A, int low, int high)
{
    int i = low + 1;
    int j = high;
    int temp;
    int pivot = A[low];
    do
    {
        while (A[i] <= pivot && i <= high)
        {
            i++;
        }
        while (A[j] > pivot && j >= low)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int A[], int low, int high)
{
    calls++; // Increment the call counter
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(A, low, high);

        quicksort(A, low, partitionIndex - 1);
        quicksort(A, partitionIndex + 1, high);
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
    quicksort(A, 0, n - 1);
    printf("Sorted array after %d calls to quicksort:\n", calls);
    printArray(A, n);
    return 0;
}
