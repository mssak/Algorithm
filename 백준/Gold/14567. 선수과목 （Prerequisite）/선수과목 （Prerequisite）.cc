#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
using ll = long long;

int dp[MAX] = {0};
vector<int> v[MAX];

int f(int ix)
{
    if (dp[ix])
    {
        return dp[ix];
    }

    dp[ix] = 1;

    for (int i : v[ix])
    {
        dp[ix] = max(dp[ix], (f(i) + 1));
    }

    return dp[ix];
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << f(i) << " ";
    }
}
