#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,cnt=0;
    cin>>a;
    a-=1;
    int i=1;
    while(a>0){
        a-=6*i++;
    }
    cout<<i;
}
