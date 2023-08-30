#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int len1 = s1.size();
    int len2 = s2.size();

    // DP for LCS
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // print length of LCS
    cout << dp[len1][len2] << "\n";

    // traceback for LCS string
    string result = "";
    while (len1 > 0 && len2 > 0) {
        if (dp[len1][len2] == dp[len1 - 1][len2]) {
            len1--;
        } else if (dp[len1][len2] == dp[len1][len2 - 1]) {
            len2--;
        } else {
            result = s1[len1 - 1] + result;
            len1--;
            len2--;
        }
    }

    if (!result.empty()) {
        cout << result << "\n";
    }

    return 0;
}
