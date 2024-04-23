#include <stdio.h>
#include <stdbool.h>

int totalCalls = 0;  // Global variable to count total calls

// Returns true if there is a subset
// of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    totalCalls++;  // Incrementing the total number of calls

    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    // If last element is greater than sum,
    // then ignore it
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);

    // Else, check if sum can be obtained by any
    // of the following:
    // (a) including the last element
    // (b) excluding the last element
    return isSubsetSum(set, n - 1, sum)
           || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

// Driver code
int main()
{
    int n, sum;

    // Input the size of the set
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[n];

    // Input the elements of the set
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    // Input the target sum
    printf("Enter the target sum: ");
    scanf("%d", &sum);

    totalCalls = 0;  // Resetting the total number of calls
    if (isSubsetSum(set, n, sum) == true)
        printf("Found a subset with given sum\n");
    else
        printf("No subset with given sum\n");

    printf("Total number of calls to isSubsetSum: %d\n", totalCalls);

    return 0;
}

// Enter the number of elements in the set: 5
// Enter the elements of the set:
// 3 34 4 12 5
// Enter the target sum: 9
