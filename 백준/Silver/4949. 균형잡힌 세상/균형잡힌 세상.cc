#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s,st;

    while(1){
        getline(cin,s);
        if(s=="."){
            break;
        }
        st.clear();
        for(char c:s){
            if(c=='('){
                st.push_back(c);
            }
            else if(c=='['){
                st.push_back(c);
            }
            else if(c==')'){
                if(st.back()!='('){
                    st.push_back(c);
                    break;
                }
                st.pop_back();
            }
            else if(c==']'){
                if(st.back()!='['){
                    st.push_back(c);
                    break;
                }
                st.pop_back();
            }
        }
        if(st.empty()){
            cout<<"yes"<<"\n";
        }
        else{
            cout<<"no"<<"\n";
        }
    }
}