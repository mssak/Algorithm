#include<bits/stdc++.h>
#define MAX 1'000'000
using namespace std;

int arr[MAX];

pair<int,int> f(int a,int b)
{
    if(a==arr[a]){
        return {a,b};
    }
    return f(arr[a],b+1);
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
            auto [br,bt]=f(b,0);
            auto [cr,ct]=f(c,0);

            if(bt<ct){
                arr[br]=cr;
            }
            else{
                arr[cr]=br;
            }
        }
        else{
            if(f(b,0).first==f(c,0).first){
                cout<<"yes\n";
            }
            else{
                cout<<"no\n";
            }
        }
    }
}
