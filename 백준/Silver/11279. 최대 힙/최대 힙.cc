#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    priority_queue<int> pq;
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