#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 동전의 상태(H/T)를 0/1로 변환하고, 3x3 배열을 하나의 정수로 표현합니다.
int get_state(const vector<vector<char>>& board) {
    int state = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 'T') {
                state |= (1 << (i * 3 + j));
            }
        }
    }
    return state;
}

// 8가지 연산에 대한 마스크를 미리 정의합니다.
// 각 비트는 뒤집힐 동전의 위치를 나타냅니다.
const int masks[] = {
    // 3개의 행
    (1 << 0) | (1 << 1) | (1 << 2), // 0, 1, 2
    (1 << 3) | (1 << 4) | (1 << 5), // 3, 4, 5
    (1 << 6) | (1 << 7) | (1 << 8), // 6, 7, 8
    // 3개의 열
    (1 << 0) | (1 << 3) | (1 << 6), // 0, 3, 6
    (1 << 1) | (1 << 4) | (1 << 7), // 1, 4, 7
    (1 << 2) | (1 << 5) | (1 << 8), // 2, 5, 8
    // 2개의 대각선
    (1 << 0) | (1 << 4) | (1 << 8), // 0, 4, 8
    (1 << 2) | (1 << 4) | (1 << 6)  // 2, 4, 6
};

// 1로 세팅된 비트의 개수를 세는 함수 (GCC/Clang에서는 __builtin_popcount 사용 가능)
int count_set_bits(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}


void solve() {
    vector<vector<char>> board(3, vector<char>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> board[i][j];
        }
    }

    int initial_state = get_state(board);
    int min_flips = -1;

    // 2^8 = 256가지의 모든 연산 조합을 시도합니다.
    for (int i = 0; i < (1 << 8); ++i) {
        int current_state = initial_state;
        
        for (int j = 0; j < 8; ++j) {
            // i의 j번째 비트가 1이면, j번째 연산을 수행합니다.
            if ((i >> j) & 1) {
                current_state ^= masks[j];
            }
        }

        // 모든 동전이 앞면(0) 또는 뒷면(511)인지 확인합니다.
        if (current_state == 0 || current_state == 0b111111111) {
            int flips = count_set_bits(i);
            if (min_flips == -1 || flips < min_flips) {
                min_flips = flips;
            }
        }
    }

    cout << min_flips << endl;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}