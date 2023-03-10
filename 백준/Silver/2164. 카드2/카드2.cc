#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    deque<int> dq;
    int a;
    cin>>a;

    for(int i=a;i>0;i--){
        dq.push_back(i);
    }

    while(dq.size()!=1){
        dq.pop_back();
        dq.push_front(dq.back());
        dq.pop_back();
    }

    cout<<dq[0];
}