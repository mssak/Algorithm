#include <bits/stdc++.h>
#define MAX
using namespace std;
using ll = long long;

int mx;

bool chk(int ix)
{
    if (ix >= 1 && ix <= mx)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int k;
    cin >> k;
    mx = pow(2, k) - 1;
    int arr[2024] = {0};

    int cnt = 0;
    int cur = 1;

    while (cnt < mx)
    {
        int left = cur * 2;
        int right = cur * 2 + 1;
        int parent = cur / 2;

        if (chk(left) && !arr[left])
        {
            cur = left;
            continue;
        }
        if (chk(cur) && !arr[cur])
        {
            int a;
            cin >> a;
            cnt++;
            arr[cur] = a;
            continue;
        }
        if (chk(right) && !arr[right])
        {
            cur = right;
            continue;
        }
        cur = parent;
    }

    for (int i = 1; i <= mx; i *= 2)
    {
        for (int j = i; j < i * 2; j++)
        {
            cout << arr[j] << " ";
        }
        cout << "\n";
    }
}
