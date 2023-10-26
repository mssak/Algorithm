#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v;
    vector<int> asc{1,2,3,4,5,6,7,8};
    vector<int> des{8,7,6,5,4,3,2,1};

    for(int i=0;i<8;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    if(equal(v.begin(),v.end(),asc.begin())){
        cout<<"ascending";
    }
    else if(equal(v.begin(),v.end(),des.begin())){
        cout<<"descending";
    }
    else{
        cout<<"mixed";
    }
}
