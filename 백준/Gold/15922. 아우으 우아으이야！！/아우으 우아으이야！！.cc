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

    int ans = 0;
    int now;
    int x, y;
    cin >> x >> y;
    n--;
    ans += y - x;
    now = y;

    while (n--)
    {
        int x, y;
        cin >> x >> y;
        if (x > now)
        {
            ans += y - x;
            now = y;
        }
        else if (y > now)
        {
            ans += y - now;
            now = y;
        }
    }
    cout << ans;
}
