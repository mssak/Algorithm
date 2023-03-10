#include<bits/stdc++.h>

using namespace std;

int num[10];
int op[4]={};  // {+ - * /}
int n,mn=INT_MAX,mx=INT_MIN;

void f(int p,int res)
{
    if(p==n-1){
        if(mn>res){
            mn=res;
        }
        if(mx<res){
            mx=res;
        }
        return;
    }

    else{
        p++;
            for(int j=0;j<4;j++){
                if(op[j]){
                    op[j]--;
                    if(j==0){
                        f(p,res+num[p]);
                    }
                    else if(j==1){
                        f(p,res-num[p]);
                    }
                    else if(j==2){
                        f(p,res*num[p]);
                    }
                    else if(j==3){
                        f(p,res/num[p]);
                    }
                    op[j]++;
                }
            }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        num[i]=a;
    }

    for(int i=0;i<4;i++){
        int a;
        cin>>a;
        op[i]=a;
    }

    f(0,num[0]);

    cout<<mx<<"\n"<<mn;
}