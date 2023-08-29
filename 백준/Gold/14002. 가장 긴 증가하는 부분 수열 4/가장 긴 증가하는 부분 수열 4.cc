#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[MAX];
    int len[MAX]={0};
    int bef[MAX];

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<MAX;i++){
        bef[i]=-1;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && len[j]+1>len[i]){
                len[i]=len[j]+1;
                bef[i]=j;
            }
        }
    }



    vector<int> v;

    int i=max_element(len,len+n)-len;
    cout<<len[i]+1<<"\n";
    for(;bef[i]!=-1;i=bef[i]){
        v.push_back(arr[i]);
    }
    v.push_back(arr[i]);

    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
}
