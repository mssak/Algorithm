#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    list<pair<int,int>> lt;
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        lt.push_back({i,a});
    }

    auto it = lt.begin();
    while(1){
        auto [num,m] = *it;
        cout<<num<<" ";
        it = lt.erase(it);
        if(it==lt.end()){
            it=lt.begin();
        }

        if(lt.empty()){
            break;
        }

        if(m>0){
            for(int i=0;i<m-1;i++){
                it++;
                if(it==lt.end()){
                    it=lt.begin();
                }
            }
        }
        else{
            for(int i=0;i<-m;i++){
                if(it==lt.begin()){
                    it=lt.end();
                }
                it--;
            }
        }
    }
}
