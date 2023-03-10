#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,c;
    vector<int> v;
    cin>>n>>c;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());

    int r,p,before;
    int b=1,e=v.back(),m;
    while(b<=e){
        p=0;
        m=(b+e)/2;

        before=-m;
        for(int i:v){
            if(i-before>=m){
                before=i;
                p++;
                if(p==c){
                    break;
                }
            }
        }
        if(p==c){
            r=m;
            b=m+1;
        }
        else if(p<c){
            e=m-1;
        }
    }

    cout<<r;
}