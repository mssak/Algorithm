#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    vector<int> v;
    cin>>a;

    int i=1;
    while(1){
        int n=i*(i+1)/2;
        if(n>=1000){
            break;
        }
        else{
            v.push_back(n);
            i++;
        }
    }

    int siz=v.size();
    while(a--){
        cin>>b;
        bool ans=false;
        int sum=0;
        for(int i=0;i<siz;i++){
            if(ans) break;
            for(int j=0;j<siz;j++){
                if(ans) break;
                for(int k=0;k<siz;k++){
                    if(v[i]+v[j]+v[k]==b){
                        ans=true;
                        cout<<1<<"\n";
                        break;
                    }
                }
            }
        }
        if(!ans) cout<<0<<"\n";
    }
}