#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,cnt;
    string s;
    cin>>a;

    while(a--){
        cin>>s;
        cnt=0;
        for(char c:s){
            if(c=='('){
                cnt++;
            }
            else{
                cnt--;
                if(cnt<0){
                    break;
                }
            }
        }
        if(cnt){
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
        }
    }
}