#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;

    deque<int> dq;
    for(int i=1;i<=n;i++){
        dq.push_back(i);
    }

    cout<<"<";
    int ix=-1;
    while(dq.size()){
        ix+=k;
        ix%=dq.size();
        cout<<dq[ix];
        if(dq.size()!=1){
            cout<<", ";
        }
        dq.erase(dq.begin()+ix);
        ix--;
        if(ix==-1){
            ix=dq.size()-1;
        }
    }
    cout<<">";
}