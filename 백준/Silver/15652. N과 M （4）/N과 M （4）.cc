#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<int> arr;

int f(int a){
    if(a >= m){
        return -1;
    }
    if(arr[a] + 1 == n+1){
        return arr[a] = f(a + 1);
    }
    return ++arr[a];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    arr.resize(m, 1); // m의 값에 맞게 벡터 크기를 조정합니다.

    while(true){
        for(int i = m - 1; i >= 0; i--){
            cout << arr[i]<<" ";
        }
        cout << "\n";
        if(f(0) == -1){
            break;
        }
    }
    return 0;
}
