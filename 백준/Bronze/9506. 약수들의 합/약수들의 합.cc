#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    
    while(true){
        vector<int> v;
        cin>>a;
        if(a==-1){
            return 0;
        }

        for(int i=1;i<a;i++){
            if(a%i==0){
                v.push_back(i);
            }
        }

        if(accumulate(v.begin(),v.end(),0)==a){
            printf("%d = ",a);
            for(int i=0;i<v.size()-1;i++){
                printf("%d + ",v[i]);
            }
            printf("%d\n",v[v.size()-1]);
        }

        else{
            printf("%d is NOT perfect.\n",a);
        }
    }
}