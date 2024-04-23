import java.util.Scanner;

public class NQueens {
    static int totalCalls = 0;

    // Function to print the solution
    static void printSolution(int board[][], int N) {
        System.out.println("2D Solution:");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println("\n1D Solution:");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1) {
                    System.out.print("Q ");
                } else {
                    System.out.print(". ");
                }
            }
            System.out.println();
        }
    }

    // Function to check if a queen can be placed on board[row][col]
    static boolean isSafe(int board[][], int row, int col, int N) {
        totalCalls++;
        int i, j;

        // Check this row on the left side
        for (i = 0; i < col; i++) {
            if (board[row][i] == 1) {
                return false;
            }
        }

        // Check upper diagonal on the left side
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        // Check lower diagonal on the left side
        for (i = row, j = col; j >= 0 && i < N; i++, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    // Recursive function to solve N-Queens problem
    static boolean solveNQueens(int board[][], int col, int N) {
        if (col >= N) {
            return true;
        }

        for (int i = 0; i < N; i++) {
            if (isSafe(board, i, col, N)) {
                board[i][col] = 1;

                if (solveNQueens(board, col + 1, N)) {
                    return true;
                }

                board[i][col] = 0;
            }
        }

        return false;
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the board size (N): ");
        int N = scanner.nextInt();

        int board[][] = new int[N][N];

        if (!solveNQueens(board, 0, N)) {
            System.out.println("Solution does not exist");
            scanner.close();
            return;
        }

        printSolution(board, N);
        System.out.println("\nTotal number of calls to queen procedure: " + totalCalls);

        scanner.close();
    }
}


// 2D Solution:
// 0 0 1 0 
// 1 0 0 0 
// 0 0 0 1 
// 0 1 0 0 

// 1D Solution:
// . . Q .
// Q . . .
// . . . Q
// . Q . .
