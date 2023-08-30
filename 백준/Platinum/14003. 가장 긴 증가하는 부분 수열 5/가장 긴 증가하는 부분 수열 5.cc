#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> LIS; // 실제 값들을 저장하는 LIS
    vector<int> idx; // LIS의 원소들의 원래 인덱스를 저장
    vector<int> prev(n, -1); // 각 원소의 이전 원소의 인덱스를 저장

    LIS.push_back(arr[0]);
    idx.push_back(0);
    for(int i=1;i<n;i++){
        if(LIS.back()<arr[i]){
            LIS.push_back(arr[i]);
            idx.push_back(i);
            if(i>0) prev[i]=idx[LIS.size()-2];
        }
        else{
            auto it=lower_bound(LIS.begin(),LIS.end(),arr[i]);
            *it=arr[i];
            int pos=it-LIS.begin();
            idx[pos]=i;
            if(pos>0) prev[i]=idx[pos-1];
        }
    }

    vector<int> ans;
    for(int i=idx.back();i!=-1;i=prev[i]){
        ans.push_back(arr[i]);
    }
    
    cout<<LIS.size()<<"\n";
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    return 0;
}
