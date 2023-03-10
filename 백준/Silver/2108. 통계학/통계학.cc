#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v;
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());
    
    double sum = accumulate(v.begin(),v.end(),(double)0);
    printf("%d\n",(int)round(sum/n));

    printf("%d\n",v[n/2]);

    vector<int> count(10000);
    for(int i:v){
        count[i+5000]++;
    }

    int max=0;
    int maxi=0;
    int c=0;
    for(int i=0;i<count.size();i++){
        if(max<count[i]){
            maxi=i;
            max=count[i];
            c=1;
        }
        else if(max==count[i]&&++c==2){
            maxi=i;
        }
    }
    printf("%d\n",maxi-5000);

    printf("%d",v[v.size()-1]-v[0]);
}