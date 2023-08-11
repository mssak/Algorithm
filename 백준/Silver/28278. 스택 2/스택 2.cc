#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    stack<int> s;
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        switch(a){
            case 1:
                int b;
                cin>>b;
                s.push(b);
                break;
            case 2:
                if(s.size()){
                    cout<<s.top()<<"\n";
                    s.pop();
                }
                else{
                    cout<<-1<<"\n";
                }
                break;
            case 3:
                cout<<s.size()<<"\n";
                break;
            case 4:
                if(s.size()){
                    cout<<0<<"\n";
                }
                else{
                    cout<<1<<"\n";
                }
                break;
            case 5:
                if(s.size()){
                    cout<<s.top()<<"\n";
                }
                else{
                    cout<<-1<<"\n";
                }
        }
    }
}