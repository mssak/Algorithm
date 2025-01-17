#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        // 정답 초기값은 -1 (찾지 못하면 그대로 -1 출력)
        int answer = -1;

        // x부터 M만큼씩 증가하며 검사
        // (i - 1) % M + 1 = x 를 만족하도록 i를 잡으면,
        // i는 x부터 시작해서 M씩 더해가면 모든 가능한 경우를 확인할 수 있습니다.
        // 그리고 (i - 1) % N + 1 = y 를 만족하는지 검사하면 됩니다.
        for (int i = x; i <= (long long)M * N; i += M) {
            if (((i - 1) % N) + 1 == y) {
                answer = i;
                break;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
