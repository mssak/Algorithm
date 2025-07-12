#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 101

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        multiset<int> ms;
        int k;
        cin>>k;
        while(k--){
            char c;
            int a;
            cin>>c>>a;
            if(c=='I'){
                ms.insert(a);
            }else{
                if(ms.size()){
                    if(a==1){
                        ms.erase(--ms.end());
                    }else{
                        ms.erase(ms.begin());
                    }
                }
            }
        }
        if(ms.size()) cout<<*(--ms.end())<<" "<<*ms.begin()<<"\n";
        else cout<<"EMPTY\n";
    }
}