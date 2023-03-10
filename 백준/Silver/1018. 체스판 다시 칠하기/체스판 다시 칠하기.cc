#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    cin>>a>>b;
    char c;

    char arr[a][b];

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>c;
            arr[i][j]=c;
        }
    }

    int min=INT_MAX;
    int cntw,cntb;
    bool w;
    for(int i=0;i+8<=a;i++){
        for(int j=0;j+8<=b;j++){
            cntw=0;
            cntb=0;
            w=true;
            for(int k=0;k<8;k++){
                for(int l=0;l<8;l++){
                    if(w){
                        if(arr[i+k][j+l]=='B'){
                            cntw++;
                        }
                        else{
                            cntb++;
                        }
                        w=false;
                    }
                    else{
                        if(arr[i+k][j+l]=='W'){
                            cntw++;
                        }
                        else{
                            cntb++;
                        }
                        w=true;
                    }
                }
                w=!w;
            }
            if(cntw<min){
                min=cntw;
            }
            if(cntb<min){
                min=cntb;
            }
        }
    }
    cout<<min;
}