#include <bits/stdc++.h>
#define MAX
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_queue<int> pq;

    int me;
    cin >> me;
    n--;
    while (n--)
    {
        int a;
        cin >> a;
        pq.push(a);
    }

    int ans = 0;
    while (pq.size() && pq.top() >= me)
    {
        int a = pq.top();
        pq.pop();
        pq.push(--a);
        me++;
        ans++;
    }

    cout << ans;
}
