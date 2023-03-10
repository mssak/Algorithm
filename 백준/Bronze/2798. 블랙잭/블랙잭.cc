#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c;
    cin>>a>>b;
    vector<int> v;
    v.reserve(a);

    for(int i=0;i<a;i++){
        cin>>c;
        v.push_back(c);
    }

    int max=0;
    for (int i = 0; i < a-2; i++)
    {
        for (int j = i+1; j < a-1; j++)
        {
            for (int k = j+1; k < a; k++)
            {
                int ind=v[i]+v[j]+v[k];
                if(ind>max and ind<=b){
                    max=ind;
                }
            }
        }
    }
    cout<<max;
}