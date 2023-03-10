#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;
    int a,b;
    cin >> a;
    v.push_back(a);

    while(true){
        b = a%10+a/10;
        a = (a%10)*10+b%10;

        for(int i:v){
            if(i==a){
                cout<<v.size();
                exit(0);
            }
        }
        v.push_back(a);
    }
}