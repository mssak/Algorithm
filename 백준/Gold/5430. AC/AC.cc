#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;

    while(T--){
        string str,sarr;
        int n;
        int arr[MAX];
        cin>>str>>n>>sarr;

        int cnt=0,t=-1;
        for(char c:sarr){
            if(c>='0' && c<='9'){
                if(t==-1){
                    t=0;
                }
                t*=10;
                t+=c-'0';
            }
            else{
                if(t!=-1){
                    arr[cnt]=t;
                    t=-1;
                    cnt++;
                }
            }
        }
        
        int s=0,e=n;
        bool err=false,r=false;
        for(char c:str){
            if(c=='R'){
                r=!r;
            }
            else if(c=='D'){
                if(e-s){
                    if(r){
                        e--;
                    }
                    else{
                        s++;
                    }
                }
                else{
                    err=true;
                    break;
                }
            }
        }
        if(err){
            cout<<"error\n";
        }
        else{
            cout<<"[";
            if(e-s){
                if(r){
                    for(int i=e-1;i>s;i--){
                        cout<<arr[i]<<",";
                    }
                    cout<<arr[s];
                }
                else{
                    for(int i=s;i<e-1;i++){
                        cout<<arr[i]<<",";
                    }
                    cout<<arr[e-1];
                }
            }
            cout<<"]\n";
        }
    }
}
