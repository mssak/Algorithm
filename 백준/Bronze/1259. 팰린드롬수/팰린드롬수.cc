#include <bits/stdc++.h>

int main() {
    using namespace std;
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while(1){
        int n;
        vector<int> v;
        cin>>n;
        
        if(n==0){
            break;
        }

        for(int i=0;n>0;i++){
            v.push_back(n%10);
            n/=10;
        }

        bool ans=false;
        int s=v.size();
        for(int i=0;i<s;i++){
            if(v[i]!=v[s-i-1]){
                break;
            }
            if(i==s-1){
                ans=true;
            }
        }

        if(ans){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
}