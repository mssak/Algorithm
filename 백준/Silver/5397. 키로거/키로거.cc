#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    string s;
    cin>>a;
    while(a--){
        list<char> lt;
        list<char>::iterator it=lt.begin();

        cin>>s;
        for(char c:s){
            if(c=='-'){
                if(it!=lt.begin()){
                    it = lt.erase(--it);
                }
            }
            else if(c=='<'){
                if(it!=lt.begin()){
                    it--;
                }
            }
            else if(c=='>'){
                if(it!=lt.end()){
                    it++;
                }
            }
            else{
                lt.insert(it,c);
            }
        }

        for(char c:lt){
            cout<<c;
        }
        cout<<"\n";
    }
}