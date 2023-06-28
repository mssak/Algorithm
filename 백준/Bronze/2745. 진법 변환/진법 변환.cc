#include<bits/stdc++.h>

using namespace std;

char arr[5][15];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string n;
    int b,answer=0;

    cin>>n>>b;

    for(int i=0;i<n.size();i++){
        char c = n[n.size()-i-1];
        int d;

        if(c>='0' and c<='9'){
            d=c-'0';
        }

        else if(c>='A' and c<='Z'){
            d=c-'A'+10;
        }

        answer+=d*(int)pow(b,i);
    }
    cout<<answer;
}