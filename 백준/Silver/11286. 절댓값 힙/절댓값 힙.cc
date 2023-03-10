#include<bits/stdc++.h>

using namespace std;

struct comp
{
    bool operator()(int a,int b){
        if(abs(a)==abs(b)){
            return a>b;
        }
        else{
            return abs(a)>abs(b);
        }
    }
};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    priority_queue<int,vector<int>,comp> pq;
    int a,b;
    cin>>a;

    while(a--){
        cin>>b;
        if(b==0){
            if(pq.size()){
                cout<<pq.top()<<"\n";
                pq.pop();
            }
            else{
                cout<<"0\n";
            }
        }
        else{
            pq.push(b);
        }
    }
}