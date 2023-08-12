#include<bits/stdc++.h>
#define MAX 1'001
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,arr[MAX]{0};
    cin>>n;

    stack<int> s;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int i=0,g=1;
    while(i<n+1 && g<=n){
        if(arr[i]==g){
            i++;
            g++;
            continue;
        }
        else{
            if(s.size() and s.top()==g){
                s.pop();
                g++;
                continue;
            }
            else{
                s.emplace(arr[i]);
                i++;
                continue;
            }
        }
    }
    if(g==n+1){
        cout<<"Nice";
    }
    else{
        cout<<"Sad";
    }
}
