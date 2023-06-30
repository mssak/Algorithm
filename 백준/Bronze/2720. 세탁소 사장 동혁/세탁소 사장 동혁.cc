#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        int a;
        cin>>a;

        do{
            cout<<a/25<<" ";
            a%=25;
        } while(a>=25);

        do{
            cout<<a/10<<" ";
            a%=10;
        } while(a>=10);

        do{
            cout<<a/5<<" ";
            a%=5;
        } while(a>=5);

        do{
            cout<<a/1<<" ";
            a%=1;
        } while(a>=1);
        
        cout<<"\n";   
    }
}
