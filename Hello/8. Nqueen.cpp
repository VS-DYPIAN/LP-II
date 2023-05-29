#include <bits/stdtr1c++.h>
using namespace std;

// Function to check if placing a queen at position (x, y) is safe
bool issafe(int** arr, int x, int y, int n) {
    // Check if there is any queen in the same column
    for (int row = 0; row < n; row++) {
        if (arr[row][y] == 1) {
            return false;
        }
    }
    
    // Check if there is any queen in the upper left diagonal
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0) {
        if (arr[row][col] == 1) {
            return false;
        }
        row--;
        col--;
    }
    
    // Check if there is any queen in the upper right diagonal
    row = x;
    col = y;
    while (row >= 0 && col < n) {
        if (arr[row][col] == 1) {
            return false;
        }
        row--;
        col++;
    }
    
    // If no conflicts, it is safe to place a queen at position (x, y)
    return true;
}

// Recursive function to solve the N-Queens problem
bool nqueen(int** arr, int x, int n) {
    // Base case: All queens have been placed successfully
    if (x >= n) {
        return true;
    }
    
    // Try placing the queen in each column of the current row
    for (int col = 0; col < n; col++) {
        // Check if it is safe to place a queen at position (x, col)
        if (issafe(arr, x, col, n)) {
            arr[x][col] = 1; // Place the queen
            
            // Recursive call to place queens in the next row
            if (nqueen(arr, x + 1, n)) {
                return true; // Solution found
            }
            
            arr[x][col] = 0; // Backtrack if no solution found
        }
    }
    
    return false; // No solution found
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    
    // Create a dynamic 2D array to represent the chessboard
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0; // Initialize the chessboard with 0 (no queen)
        }
    }
    
    // Call the nqueen function to solve the N-Queens problem
    if (nqueen(arr, 0, n)) {
        // Print the resulting placement of queens
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
