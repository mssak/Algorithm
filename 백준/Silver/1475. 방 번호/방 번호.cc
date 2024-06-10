#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin>>s;

    int arr[10]{0};
    for(char c:s){
        arr[c-'0']++;
    }

    arr[6]=(arr[6]+arr[9]+1)/2;
    cout<<*max_element(arr,arr+9);
}
