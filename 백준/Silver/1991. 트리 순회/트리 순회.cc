#include<bits/stdc++.h>
#define MAX 27
using namespace std;

char arr[MAX][2]{0};
int n;

void pre()
{
    bool v[MAX]{0};
    stack<char> s;
    v[1]=true;
    v[0]=true;
    s.push(1);

    while(!s.empty()){
        char c=s.top();
        s.pop();
        cout<<(char)(c+'A'-1);

        for(int it=1;it>=0;it--){
            char i=arr[c][it];
            if(!v[i]){
                v[i]=true;
                s.push(i);
            }
        }
    }
}

void inU(int a,bool v[])
{
    v[a]=true;
    if(!v[arr[a][0]]){
        inU(arr[a][0],v);
    }
    cout<<(char)(a+'A'-1);
    if(!v[arr[a][1]]){
        inU(arr[a][1],v);
    }
}

void in()
{
    bool v[MAX]{0};
    v[0]=true;
    inU(1,v);
}

void postU(int a,bool v[])
{
    v[a]=true;
    for(int i:arr[a]){
        if(!v[i]){
            postU(i,v);
        }
    }
    cout<<(char)(a+'A'-1);
}


void post()
{
    bool v[MAX]{0};
    v[0]=true;
    postU(1,v);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i=0;i<n;i++){
        char a,b,c;
        cin>>a>>b>>c;
        a=a-'A'+1;

        if(b!='.'){
            arr[a][0]=b-'A'+1;
        }
        if(c!='.'){
            arr[a][1]=c-'A'+1;
        }
    }

    pre();
    cout<<"\n";
    in();
    cout<<"\n";
    post();
}