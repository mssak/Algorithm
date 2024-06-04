#include<bits/stdc++.h>
#define MAX 
using namespace std;

int arr[10];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0;i<10;i++){
        arr[i]=1;
    }

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        arr[a]=0;
    }

    int ans=abs(100-n);
    for(int i=0;i<=5000000;i++){
        bool can=true;
        int nn=0;
        for(int j=i;;){
            if(!arr[j%10]){
                can=false;
                break;
            }
            nn++;
            j/=10;
            if(j==0){
                break;
            }
        }

        if(can){
            ans=min(ans,nn+abs(n-i));
            // cout<<i<<" "<<nn<<" "<<abs(n-i)<<" "<<ans<<"\n";
        }
    }

    cout<<ans;
}
