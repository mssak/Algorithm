#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,d,p=1,count=0;
    cin>>n;
    vector<char> ans;
    stack<int> s;

    for(int i=0;i<n;i++){
        cin>>d;
        if(s.empty() or d>s.top()){
            do{
                s.push(p++);
                ans.push_back('+');
            }while(s.top()<d and p<=n);
        }
        if(d==s.top()){
            s.pop();
            ans.push_back('-');
            count++;
        }
        else if(d<s.top()){
            break;
        }
    }
    if(count==n){
        for(auto i:ans){
            cout<<i<<"\n";
        }
    }
    else{
        cout<<"NO";
    }
}