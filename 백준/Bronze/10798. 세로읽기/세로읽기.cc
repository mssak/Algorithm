#include<bits/stdc++.h>

using namespace std;

char arr[5][15];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;

    for(int i=0;i<5;i++){
        for(int j=0;j<15;j++){
            arr[i][j]=0;
        }
    }

    for(int i=0;i<5;i++){
        cin>>s;
        s.copy(arr[i],s.size(),0);
    }

    for(int i=0;i<15;i++){
        for(int j=0;j<5;j++){
            if(arr[j][i]!=0){
                cout<<arr[j][i];
            }
        }
    }
}