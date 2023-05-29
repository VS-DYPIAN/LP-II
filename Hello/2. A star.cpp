#include <bits/stdtr1c++.h>  // Include necessary standard library headers

using namespace std;

int g = 0;  // Global variable to keep track of the depth or number of moves

// Function to display the puzzle board
void display(int arr[]) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            cout << endl;  // Start a new line after every 3 elements
        }
        if (arr[i] == -1) {
            cout << "_";  // Display "_" for the empty tile
        }
        cout << arr[i] << " ";  // Display the element
    }
    cout << endl;
}

// Move the empty tile to the left
void moveleft(int start[], int pos) {
    swap(start[pos], start[pos - 1]);
}

// Move the empty tile to the right
void moveright(int start[], int pos) {
    swap(start[pos], start[pos + 1]);
}

// Move the empty tile down
void movedown(int start[], int pos) {
    swap(start[pos], start[pos + 3]);
}

// Move the empty tile up
void moverup(int start[], int pos) {
    swap(start[pos], start[pos - 3]);
}

// Calculate the heuristic value of a state
int heurstic(int start[], int goal[]) {
    int h = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (start[i] == goal[j] && start[i] != -1) {
                // Calculate the Manhattan distance heuristic
                h += (abs((j - i) / 3) + abs((j - i) % 3));
            }
        }
    }
    return g + h;
}

// Copy the contents of one array to another
void copy(int temp[], int real[]) {
    for (int i = 0; i < 9; i++) {
        temp[i] = real[i];
    }
}

// Generate possible moves and select the one with the lowest heuristic value
void movetile(int start[], int goal[]) {
    int emptyat = 0;
    for (int i = 0; i < 9; i++) {
        if (start[i] == -1) {
            emptyat = i;  // Find the position of the empty tile
            break;
        }
    }

    int t1[9], t2[9], t3[9], t4[9];  // Temporary arrays to store possible states
    int f1 = INT_MAX, f2 = INT_MAX, f3 = INT_MAX, f4 = INT_MAX;  // Heuristic values of each state
    
    copy(t1, start);
    copy(t2, start);
    copy(t3, start);
    copy(t4, start);

    int row = emptyat / 3;
    int col = emptyat % 3;

    // Generate possible moves and calculate heuristic values
    if (col - 1 >= 0) {
        moveleft(t1, emptyat);
        f1 = heurstic(t1, goal);
    }
    if (col + 1 < 3) {
        moveright(t2, emptyat);
        f2 = heurstic(t2, goal);
    }
    if (row + 1 < 3) {
        movedown(t3, emptyat);
        f3 = heurstic(t3, goal);
    }
    if (row - 1 >= 0) {
        moverup(t3, emptyat);
        f4 = heurstic(t4, goal);
    }

    // Choose the move with the lowest heuristic value
    if (f1 <= f2 && f1 <= f3 && f1 <= f4) {
        moveleft(start, emptyat);
    } else if (f2 <= f3 && f2 <= f1 && f2 <= f4) {
        moveright(start, emptyat);
    } else if (f3 <= f4 && f3 <= f1 && f3 <= f2) {
        movedown(start, emptyat);
    } else {
        moverup(start, emptyat);
    }
}

// Solve the puzzle using A* search algorithm
void solve(int start[], int goal[]) {
    g++;  // Increment the depth or number of moves
    movetile(start, goal);
    display(start);
    int f = heurstic(start, goal);
    if (f == g) {
        cout << "Solved in " << f << " moves.";
        return;
    }
    solve(start, goal);
}

int main() {
    int start[9], goal[9];
    cout << "Enter the start elements: ";
    for (int i = 0; i < 9; i++) {
        cin >> start[i];  // Input the start state
    }
    cout << "Enter the goal elements: ";
    for (int j = 0; j < 9; j++) {
        cin >> goal[j];  // Input the goal state
    }

    solve(start, goal);  // Start solving the puzzle

    return 0;
}
