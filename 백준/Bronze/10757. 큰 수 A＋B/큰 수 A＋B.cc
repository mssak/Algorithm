#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string a;
    string b;
    string ans;
    int alen,blen;
    int up=0;
    
    cin>>a>>b;
    alen=a.size();
    blen=b.size();
    
    int an,bn;


    while(alen>0 or blen>0){
        an=alen>0?a[alen-1]:'0';
        bn=blen>0?b[blen-1]:'0';

        // cout<<an-'0'<<" "<<bn-'0'<<" "<<up<<" "<<endl;
        if((an+bn+up)-'0'*2>=10){
            ans.push_back(an+bn+up-10);
            up=1;
        }
        else{
            ans.push_back(an+bn+up);
            up=0;
        }
        // cout<<(int)ans[i]<<endl;
        alen--;
        blen--;
    }

    // cout<<up<<endl;
    if(up==1){
        ans.push_back('1'+'0');
    }

    for(int i=ans.size()-1;i>=0;i--){
        cout<<(int)ans[i]-'0'*2;
    }
}