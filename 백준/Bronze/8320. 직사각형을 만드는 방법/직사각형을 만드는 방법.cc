#include <cmath>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long answer = 0;
    // a의 최대값은 sqrt(n)까지
    int limit = (int)floor(sqrt(n));

    for (int a = 1; a <= limit; a++) {
        // floor(n / a)가 a보다 작으면 어차피 직사각형을 만들 수 없으므로 더하지 않음
        int maxB = n / a;

        answer += (maxB - a + 1);
    }

    cout << answer << "\n";
    return 0;
}
