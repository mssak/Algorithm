#include <bits/stdc++.h>
#define MAX 
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vv;
typedef vector<ll> v;

ll n, B;
vv arr(5, v(5));
vv result(5, v(5, 0));
vv temp(5, v(5, 0));

void mul(vv& a, vv& b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= 1'000;
        }
    }
    swap(a, temp);
}

void f(ll b) {
    if (b == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] %= 1000;
            }
        }
        return;
    }

    f(b / 2);
    mul(arr, arr);
    if (b % 2 == 1) {
        mul(arr, result);
    }
}

void print(vv& a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> B;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            result[i][j] = arr[i][j];
        }
    }

    f(B);
    print(arr);
}