#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string n;
    cin>>n;

    int arr[10]={0,};
    int sm=0;
    
    for(char c:n){
        int a=c-'0';
        sm+=a;
        arr[a]++;
    }

    if(!(sm%3==0&&arr[0])){
        cout<<-1;
        return 0;
    }

    for(int i=9;i>=0;i--){
        for(int j=0;j<arr[i];j++){
            cout<<i;
        }
    }
}