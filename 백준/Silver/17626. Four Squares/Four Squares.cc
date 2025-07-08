#include <iostream>
#include <vector>
#include <algorithm> // for std::min
#include <cmath>     // for std::sqrt

int main() {
    // 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // dp[i]는 i를 제곱수의 합으로 나타내는 최소 개수
    // n의 최대값이 50,000이므로 크기를 n+1로 설정
    std::vector<int> dp(n + 1);

    // 초기값 설정
    dp[0] = 0; // 0은 0개의 제곱수로 표현

    // 1부터 n까지 각 숫자에 대해 최소 제곱수 개수를 계산
    for (int i = 1; i <= n; ++i) {
        // 일단 최대값으로 초기화 (가능한 가장 큰 값)
        // 4개의 제곱수까지 가능하므로 4보다 큰 값으로 설정해도 됨
        dp[i] = i; // 최악의 경우 1을 i번 더하는 경우 (1^2 + 1^2 + ... + 1^2)

        // j*j가 i보다 작거나 같은 모든 제곱수를 확인
        for (int j = 1; j * j <= i; ++j) {
            // 점화식: dp[i] = min(dp[i], dp[i - j*j] + 1)
            // i에서 j*j를 뺀 값을 만드는 데 필요한 제곱수 개수에 1 (j*j)를 더함
            dp[i] = std::min(dp[i], dp[i - j * j] + 1);
        }
    }

    // 결과 출력
    std::cout << dp[n] << std::endl;

    return 0;
}