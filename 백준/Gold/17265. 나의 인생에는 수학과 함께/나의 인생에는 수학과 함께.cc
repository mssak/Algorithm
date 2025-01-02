#include <bits/stdc++.h>
#define MAX 5
using namespace std;
using ll = long long;

int n;
char mp[MAX][MAX];
int mx = INT_MIN;
int mn = INT_MAX;

void dfs(int y, int x, int sum, char sig) {
    if (y < 0 || y >= n || x < 0 || x >= n) {
        return;
    }

    if (mp[y][x] >= '0' && mp[y][x] <= '9') {
        int num = mp[y][x] - '0';
        if (sig == '+') {
            sum += num;
        } else if (sig == '-') {
            sum -= num;
        } else if (sig == '*') {
            sum *= num;
        }
    } else {
        sig = mp[y][x];
    }

    if (y == n - 1 && x == n - 1) {
        mx = max(sum, mx);
        mn = min(sum, mn);
    } else {
        dfs(y + 1, x, sum, sig);
        dfs(y, x + 1, sum, sig);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
        }
    }
    dfs(0, 0, 0, '+');

    cout << mx << " " << mn;
}
