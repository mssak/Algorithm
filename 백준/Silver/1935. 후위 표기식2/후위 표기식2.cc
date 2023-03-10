#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    cin>>a;
    string s;
    vector<double> v;
    int arr['Z'+1]={};

    cin>>s;
    int siz=s.size();
    for(char c:s){
        if(c=='*'){
            v[v.size()-2]*=v[v.size()-1];
            v.erase(--v.end());
        }
        else if(c=='+'){
            v[v.size()-2]+=v[v.size()-1];
            v.erase(--v.end());
        }
        else if(c=='-'){
            v[v.size()-2]-=v[v.size()-1];
            v.erase(--v.end());
        }
        else if(c=='/'){
            v[v.size()-2]/=v[v.size()-1];
            v.erase(--v.end());
        }
        else{
            if(arr[c]){
                v.push_back(arr[c]);
            }
            else{
                cin>>b;
                arr[c]=b;
                v.push_back(b);
            }
        }
    }
    printf("%.2f",v[0]);
}