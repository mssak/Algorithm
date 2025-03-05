#include <bits/stdc++.h>
using namespace std;

int T, W;
int arr[1002];
int dp[1002][32];  // dp[t][moves]: t번째 초부터 시작, 현재까지 moves번 이동한 상태에서 얻을 수 있는 최대 자두 수

int f(int t, int moves) {
    if(t > T) return 0;  // 모든 시간이 지난 경우
    if(dp[t][moves] != -1) return dp[t][moves];
    
    // 현재 자두가 위치한 나무: moves가 짝수이면 1번, 홀수이면 2번
    int currentPos = (moves % 2 == 0) ? 1 : 2;
    
    // 이동하지 않고 그대로 있을 경우
    int stay = f(t + 1, moves) + (arr[t] == currentPos ? 1 : 0);
    
    // 이동하는 경우 (이동 횟수가 남아있는 경우)
    int move = 0;
    if(moves < W) {
        // 이동 후 자두가 위치하는 나무는 반대쪽
        int newPos = 3 - currentPos;
        move = f(t + 1, moves + 1) + (arr[t] == newPos ? 1 : 0);
    }
    
    dp[t][moves] = max(stay, move);
    return dp[t][moves];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T >> W;
    for (int i = 1; i <= T; i++){
        cin >> arr[i];
    }
    
    // dp 배열을 -1로 초기화
    for (int i = 0; i < 1002; i++){
        for (int j = 0; j < 32; j++){
            dp[i][j] = -1;
        }
    }
    
    cout << f(1, 0) << "\n";
    
    return 0;
}
