#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    string arr[1001];
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<101;i++){
        unordered_set<string> us;

        bool ans=true;
        for(int j=0;j<n;j++){
            string nn=arr[j].substr(arr[j].size()-i);
            if(us.count(nn)){
                ans=false;
                break;
            }
            else{
                us.emplace(nn);
            }
        }

        if(ans){
            cout<<i;
            return 0;
        }

    }
}
