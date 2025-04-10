#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin>>s;

    int sl=s.size();
    vector<int> v(26);

    for(char c:s){
        v[c-'A']++;
    }

    if(sl%2==0){
        int odd=0;
        for(int i:v){
            if(i%2==1){
                odd++;
            }
        }

        if(odd){
            cout<<"I'm Sorry Hansoo";
            return 0;
        }


        string s;
        for(int i=0;i<26;i++){
            s.append(v[i]/2,i+'A');
        }

        cout<<s;
        for(int i=s.size()-1;i>=0;i--){
            cout<<s[i];
        }
        return 0;

    }else{
        int odd=0;
        char oddc;
        for(int i=0;i<26;i++){
            if(v[i]%2==1){
                odd++;
                oddc='A'+i;
            }
        }

        if(odd!=1){
            cout<<"I'm Sorry Hansoo";
            return 0;
        }

        string s;
        for(int i=0;i<26;i++){
            s.append(v[i]/2,i+'A');
        }

        cout<<s<<oddc;
        for(int i=s.size()-1;i>=0;i--){
            cout<<s[i];
        }
        return 0;
    }
}
