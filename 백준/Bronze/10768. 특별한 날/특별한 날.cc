#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    cin>>a>>b;

    if(a==2 && b==18){
        cout<<"Special";
    }
    else if(a<2){
        cout<<"Before";
    }
    else if(a<=2 && b<=18){
        cout<<"Before";
    }
    else{
        cout<<"After";
    }
}
