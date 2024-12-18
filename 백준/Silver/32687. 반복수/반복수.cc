#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    long long A, B, M;
    int K;
    cin >> A >> B >> K >> M;

    long long count = 0;

    // K-자리 시작 숫자 범위
    long long start_S = pow(10, K - 1);
    long long end_S = pow(10, K);

    // B의 길이 계산
    int max_len = to_string(B).length();

    for (long long S = start_S; S < end_S; ++S) {
        string str_S = to_string(S);
        string infinite_S = str_S;
        int L = K;

        while (true) {
            // 필요한 만큼 문자열 확장
            while (L > (int)infinite_S.length()) {
                infinite_S += str_S;
                // cout<<infinite_S<<"\n";
            }

            // 자른 부분 문자열로 숫자 생성
            string N_str = infinite_S.substr(0, L);
            long long N = stoll(N_str);

            if (N > B) break; // 범위를 벗어나면 중단
            if (N >= A && N % M == 0) {
                count++;
            }

            L++; // 다음 길이로 확장
            if (L > max_len) break; // 최대 길이 초과 시 중단
        }
    }

    cout << count << endl;
    return 0;
}
