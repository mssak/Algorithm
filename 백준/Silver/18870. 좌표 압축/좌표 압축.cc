#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    cin>>a;

    pair<int,int>* arr = new pair<int,int>[a];
    int* answer = new int[a]{};
    for(int i=0;i<a;i++){
        cin>>b;
        arr[i]=pair<int,int>(b,i);
    }

    sort(arr,arr+a);
    // for(int i=0;i<a;i++){
    //     cout<<arr[i].first<<","<<arr[i].second<<"\n";
    // }

    int cnt=-1;
    for(int i=0;i<a;i++){
        if(i!=0&&arr[i-1].first==arr[i].first){
            answer[arr[i].second]=cnt;
        }
        else{
            cnt++;
            answer[arr[i].second]=cnt;
        }
    }

    for(int i=0;i<a;i++){
        cout<<answer[i]<<" ";
    }
}