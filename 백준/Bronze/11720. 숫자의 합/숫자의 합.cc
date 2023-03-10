#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,answer=0;
    char b;
    cin>>a;
    
    for(int i=0;i<a;i++){
        cin >> b;
        answer += b-48;
    }
    cout<<answer<<endl;
}