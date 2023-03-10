#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a=1,b=1,c;
    bool up=true;
    cin>>c;

    for(int i=0;i<c-1;i++){
        if(up){
            a-=1;
            b+=1;
            if(a==0){
                a=1;
                up=false;
            }
        }
        else{
            a+=1;
            b-=1;
            if(b==0){
                b=1;
                up=true;
            }
        }
    }

    cout<<a<<"/"<<b;
}