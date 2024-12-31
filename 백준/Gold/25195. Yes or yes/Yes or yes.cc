#include <bits/stdc++.h>
#define MAX
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> vt(n + 1);
    vector<bool> hell(n + 1);
    fill(hell.begin(), hell.end(), false);

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        vt[u].push_back(v);
    }

    int s;
    cin >> s;
    while (s--)
    {
        int a;
        cin >> a;
        hell[a] = 1;
    }

    string ans = "Yes";

    queue<int> q;
    q.push(1);

    while (q.size())
    {
        int cur = q.front();
        q.pop();

        if (hell[cur])
        {
            continue;
        }

        if (vt[cur].size() == 0)
        {
            ans = "yes";
            break;
        }

        for (int i : vt[cur])
        {
            q.push(i);
        }
    }

    cout << ans;
}
