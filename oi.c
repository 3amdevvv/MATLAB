#include <stdio.h>

int max(int a, int b) { 
    return (a > b) ? a : b;
     }

// Returns the maximum value that can be
// put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n, int selected[])
{
    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more than
    // Knapsack capacity W, then this item cannot
    // be included in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1, selected);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
    {
        int include = val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1, selected);
        int exclude = knapSack(W, wt, val, n - 1, selected);

        // Choose the better result
        if (include > exclude)
        {
            selected[n - 1] = 1; // Mark the item as selected
            return include;
        }
        else
        {
            selected[n - 1] = 0; // Mark the item as not selected
            return exclude;
        }
    }
}

// Driver code
int main()
{
    int n;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];

    printf("Enter the weights and values of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &weight[i], &profit[i]);
    }

    int W;
    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &W);

    int selected[n] ; // Array to store the selected items (1 if selected, 0 otherwise)

    int totalProfit = knapSack(W, weight, profit, n, selected);

    printf("Selected items (1: selected, 0: not selected):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", selected[i]);
    }
    printf("\n");

    printf("Total profit earned: %d\n", totalProfit);

    return 0;
}

// Enter the number of items: 5
// Enter the weights and values of 5 items:
// Enter weight and value for item 1: 2 10
// Enter weight and value for item 2: 3 5
// Enter weight and value for item 3: 5 15
// Enter weight and value for item 4: 7 7
// Enter weight and value for item 5: 1 6
// Enter the maximum weight of the knapsack: 10