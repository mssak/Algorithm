#include <iostream>
#include <vector>
using namespace std;

int N, result = 0;
vector<int> queen; 

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queen[i] == col || abs(queen[i] - col) == row - i) return false;
    }
    return true;
}

void solve(int row) {
    if (row == N) {
        result++;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            queen[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    cin >> N;
    queen.resize(N);
    solve(0);
    cout << result << endl;
    return 0;
}
