#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 20'001

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    int s=0;
    int f=0;
    int ans=0;
    vector<int> v;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;

        if(v.size()==0){
            v.push_back(c);
        }else if(v.size()==1){
            if(v[0]!=c){
                f=i;
                v.push_back(c);
            }
        }else{
            if(c==v[0]){
                f=i;
                v[0]=v[1];
                v[1]=c;
            }else if(c!=v[1]){
                s=f;
                f=i;
                v[0]=v[1];
                v[1]=c;
            }
        }
        ans=max(ans,i-s+1);
    }

    cout<<ans;
}