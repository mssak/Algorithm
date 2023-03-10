#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    int* arr = new int[1500*1500];
    cin>>a;

    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin>>b;
            arr[i*a+j]=b;
        }
    }

    sort(arr,arr+a*a);
    cout<<arr[a*a-a];
}