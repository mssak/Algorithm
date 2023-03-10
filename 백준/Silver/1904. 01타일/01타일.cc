// 헤더 파일 포함
#include <iostream>
using namespace std;

// 메인 함수
int main() {
    // 입력 받기
    int n;
    cin >> n;

    // dp 배열 초기화
    int dp[n+1];

    // 초기값 설정
    dp[0] = dp[1] = 1;

    // 점화식 적용
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }

    // 출력하기
    cout << dp[n] << endl;

    return 0;
}