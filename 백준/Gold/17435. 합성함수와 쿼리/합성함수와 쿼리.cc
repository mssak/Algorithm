#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int m;
int Q;
int n, x;
int f[200001];
#define max_log 20
int table[21][200001];

void init()
{
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int num;
        cin >> num;
        f[i] = num;
    }

    for (int i = 1; i <= m; i++)
        table[0][i] = f[i];

    for (int i = 1; i < max_log; i++) {
        for (int j = 1; j <= m; j++) {
            int tmp = table[i - 1][j];
            table[i][j] = table[i - 1][tmp];
        }
    }
}

int solve(int n, int x)
{
    int cur = x;
    for (int k = 0; k < max_log; k++) {
        if (n & (1 << k)) {
            cur = table[k][cur];
        }
    }
    return cur;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    cin >> Q;
    while (Q--) {
        cin >> n >> x;
        
        int res = solve(n, x);
        cout << res << '\n';
    }
}
