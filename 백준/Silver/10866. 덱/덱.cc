#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    deque<int> dq;
    int a,b;
    string s;
    cin>>a;

    while(a--){
        cin>>s;
        if(s=="push_front"){
            cin>>b;
            dq.push_front(b);
        }
        else if(s=="push_back"){
            cin>>b;
            dq.push_back(b);
        }
        else if(s=="pop_front"){
            if(dq.size()){
                cout<<dq.front()<<"\n";
                dq.pop_front();
            }
            else{
                cout<<"-1"<<"\n";
            }
        }
        else if(s=="pop_back"){
            if(dq.size()){
                cout<<dq.back()<<"\n";
                dq.pop_back();
            }
            else{
                cout<<"-1"<<"\n";
            }
        }
        else if(s=="size"){
            cout<<dq.size()<<"\n";
        }
        else if(s=="empty"){
            cout<<dq.empty()<<"\n";
        }
        else if(s=="front"){
            if(dq.size()){
                cout<<dq.front()<<"\n";
            }
            else{
                cout<<"-1"<<"\n";
            }
        }
        else if(s=="back"){
            if(dq.size()){
                cout<<dq.back()<<"\n";
            }
            else{
                cout<<"-1"<<"\n";
            }
        }
    }
}