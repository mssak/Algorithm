#include <bits/stdc++.h>
#define MAX 5
using namespace std;
typedef long long ll;

ll n, B;
ll arr[MAX][MAX];
ll result[MAX][MAX];
ll temp[MAX][MAX];

void mul(ll a[MAX][MAX], ll b[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= 1000;
        }
    }
    memcpy(a, temp, sizeof(temp));
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

void print(ll a[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lld ", a[i][j]);
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
