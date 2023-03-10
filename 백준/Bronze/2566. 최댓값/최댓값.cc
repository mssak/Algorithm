#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,max=-1,ii,jj;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>n;
            if(max<n){
                max=n;
                ii=i;
                jj=j;
            }
        }
    }
    cout<<max<<"\n"<<ii+1<<" "<<jj+1;
}