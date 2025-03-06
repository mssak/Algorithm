#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;
int arr[1'000'001];

int f(int a){
    if(arr[a]==a){
        return arr[a];
    }else{
        return arr[a]=f(arr[a]);
    }
}

void unite(int a,int b){
    
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    
    for(int i=0;i<=n;i++){
        arr[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;

        if(a==0){
            int aa=f(b);
            int bb=f(c);

            if(aa<bb){
                arr[bb]=aa;
            }else{
                arr[aa]=bb;
            }
        }else{
            if(f(b)==f(c)){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
}
