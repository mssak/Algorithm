#include<bits/stdc++.h>
#define MAX 100'001
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    int arr[MAX];;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> v;
    v.push_back(arr[0]);
    for(int I=1;I<n;I++){
        int i=arr[I];
        if(v.back()<i){
            v.push_back(i);
        }
        else{
            *lower_bound(v.begin(),v.end(),i)=i;
        }
    }

    cout<<v.size();
}