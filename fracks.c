#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int p[n], w[n], used[n];
    printf("Enter the weights and values of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &w[i], &p[i]);
        used[i] = 0;  // Initialize used array
    }

    int W;
    printf("Enter the maximum weight of the bag: ");
    scanf("%d", &W);

    int cur_w = W;
    float total_v = 0.0;
    int solution[n];
    int solution_count = 0;

    while (cur_w > 0) {
        int maxi = -1;
        for (int i = 0; i < n; ++i) {
            if (used[i] == 0 && (maxi == -1 || ((float)w[i] / p[i] > (float)w[maxi] / p[maxi]))) {
                maxi = i;
            }
        }

        if (maxi == -1) {
            break;
        }

        used[maxi] = 1;
        cur_w -= w[maxi];
        total_v += p[maxi];
        solution[solution_count++] = maxi + 1;

        if (cur_w >= 0) {
            printf("Item %d selected\n", maxi + 1);
        } else {
            float fraction = (float)(cur_w + w[maxi]) / w[maxi];
            printf("Item %d partially selected: %.2f%%\n", maxi + 1, fraction * 100);
            total_v -= p[maxi];
            total_v += fraction * p[maxi];
        }
    }
    
    printf("Solution vector: ");
    for (int i = 0; i < solution_count; i++) {
        printf("%d ", solution[i]);
    }
    printf("\nTotal profit earned: %.2f\n", total_v);
    
    return 0;
}

// Enter the number of items: 5
// Enter the weights and values of 5 items:
// Enter weight and value for item 1: 2 10
// Enter weight and value for item 2: 3 5
// Enter weight and value for item 3: 5 15
// Enter weight and value for item 4: 7 7
// Enter weight and value for item 5: 1 6
// Enter the maximum weight of the bag: 10