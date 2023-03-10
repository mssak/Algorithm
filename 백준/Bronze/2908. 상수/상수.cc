#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    cin>>a>>b;

    a=((a%10)*100)+(a%100-a%10)+(a/100);
    b=((b%10)*100)+(b%100-b%10)+(b/100);

    cout << (a<b?b:a);
}