#include<bits/stdc++.h>

using namespace std;

int k;
int c=0;
bool bfind=0;

void merge(vector<int> &v,int p,int q,int r) {
    int i = p;
    int j = q + 1;
    int t = 1;
    int tmp[r-p+2];
    while (i <= q and j <= r) {
        if (v[i] <= v[j]){
            tmp[t++] = v[i++];
        }
        else tmp[t++] = v[j++];
    }
    while (i <= q)
        tmp[t++] = v[i++];
    while (j <= r)
        tmp[t++] = v[j++];
    i = p;
    t = 1;
    while (i <= r){
        c++;
        if(c==k)
        {
            cout << tmp[t];
            bfind=1;
        }
        v[i++] = tmp[t++];
    }
}

void merge_sort(vector<int> &v,int p,int r) {
    if (p < r){
        int q = (p + r) / 2;       
        merge_sort(v, p, q);    
        merge_sort(v, q + 1, r); 
        merge(v, p, q, r);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    cin>>a>>k;

    vector<int> v;
    v.reserve(a);
    while(a--){
        cin>>b;
        v.push_back(b);
    }
    merge_sort(v, 0, v.size()-1);

    if(!bfind){
        cout<<-1;
    }
}