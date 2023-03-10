#include<bits/stdc++.h>

using namespace std;

class Stack
{
private:
    int arr[100'000];
    int s=0;
public:
    void push(int x){
        arr[s]=x;
        s++;
    }
    void pop(){
        if(s){
            cout<<arr[s-1]<<"\n";
            s--;
        }
        else{
            cout<<-1<<"\n";
        }
    }
    void size(){
        cout<<s<<"\n";
    }
    void empty(){
        if(s){
            cout<<0<<"\n";
        }
        else{
            cout<<1<<"\n";
        }
    }
    void top(){
        if(s){
            cout<<arr[s-1]<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }
};


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,a;
    string s;
    Stack st;
    cin>>n;
    while(n--){
        cin>>s;
        if(s=="push"){
            cin>>a;
            st.push(a);
        }
        if(s=="pop"){
            st.pop();
        }
        if(s=="size"){
            st.size();
        }
        if(s=="empty"){
            st.empty();
        }
        if(s=="top"){
            st.top();
        }
    }
}