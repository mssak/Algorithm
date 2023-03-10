#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v;
    int b,sum=0;
    
    for(int i=0;i<9;i++){
        cin>>b;
        v.push_back(b);
        sum+=b;
    }
    sum-=100;
    sort(v.begin(),v.begin()+9);
    
    do{
        int ans=0;
        for(int i=0;i<2;i++){
            ans+=v[i];
        }
        if(ans==sum){
            break;
        }
    }while(next_permutation(v.begin(),v.end()));

    
    for(int i=2;i<9;i++){
            cout<<v[i]<<"\n";
        }
}