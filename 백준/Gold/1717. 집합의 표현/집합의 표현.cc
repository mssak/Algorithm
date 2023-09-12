#include<bits/stdc++.h>
#define MAX 1'000'000
using namespace std;

int arr[MAX];

int f(int a)
{
    if(a==arr[a]){
        return a;
    }
    return f(arr[a]);
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
            int br=f(b);
            int cr=f(c);

            if(br>cr){
                arr[cr]=br;
            }
            else{
                arr[br]=cr;
            }
        }
        else{
            if(f(b)==f(c)){
                cout<<"yes\n";
            }
            else{
                cout<<"no\n";
            }
        }
    }
}
