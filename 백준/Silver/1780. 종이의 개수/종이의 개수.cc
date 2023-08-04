#include<bits/stdc++.h>
#define MAX 3*3*3*3*3*3*3
using namespace std;

int ans[3]{0};
int arr[MAX][MAX];

bool check(int x,int y,int n)
{
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(arr[i][j]!=arr[x][y]){
                return false;
            }           
        }
    }
    return true;
}

void f(int x,int y,int n)
{
    if(check(x,y,n)){
        ans[arr[x][y]+1]++;
    }

    else{
        f(x,y,n/3);
        f(x+n/3,y,n/3);
        f(x+n*2/3,y,n/3);
        f(x,y+n/3,n/3);
        f(x,y+n*2/3,n/3);
        f(x+n/3,y+n/3,n/3);
        f(x+n/3,y+2*n/3,n/3);
        f(x+2*n/3,y+n/3,n/3);
        f(x+2*n/3,y+2*n/3,n/3);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    f(0,0,n);

    for(int i=0;i<3;i++){
        cout<<ans[i]<<"\n";
    }
}