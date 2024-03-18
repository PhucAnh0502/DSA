#include <iostream>
#define N 9

using namespace std;

void print(int a[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(int a[N][N], int row, int col, int num) {
    // Check row
    for (int i = 0; i < N; i++) {
        if (a[row][i] == num) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < N; i++) {
        if (a[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 box
    int startrow = (row / 3) * 3;
    int startcol = (col / 3) * 3;
    for (int i = startrow; i < startrow + 3; i++) {
        for (int j = startcol; j < startcol + 3; j++) {
            if (a[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve(int a[N][N], int row, int col) {
    // Check if we have reached the last row and column (8, 9)
    if (row == N - 1 && col == N) {
        return true;
    }

    // Check if column reaches the end, move to the next row and start from the first column
    if (col == N) {
        row++;
        col = 0;
    }

    // If the current position is already filled, move to the next column
    if (a[row][col] > 0) {
        return solve(a, row, col + 1);
    }

    for (int num = 1; num <= N; num++) {
        if (check(a, row, col, num)) {
            a[row][col] = num;
            if (solve(a, row, col + 1)) {
                return true;
            }
        }
        a[row][col] = 0; // Reset the value if the current number doesn't lead to a solution
    }
    return false;
}

int main() {
    int a[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    if (solve(a, 0, 0)) {
    	cout << endl; 
        print(a);
    } else {
        cout << "No solution!" << endl;
    }

    return 0;
}

