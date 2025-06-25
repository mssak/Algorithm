#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    unordered_set<int> us;

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        us.insert(a);
    }

    int ans=1;
    while(1){
        if(us.find(ans)==us.end()){
            cout<<ans;
            return 0;
        }
        ans++;
    }

}
