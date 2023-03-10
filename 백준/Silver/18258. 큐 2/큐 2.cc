#include<bits/stdc++.h>

using namespace std;

class Queue
{
private:
    int* arr = new int[2'000'000];
    int s=0;
    int p=0;
public:
    void push(int x){
        arr[s]=x;
        s++;
    }
    void pop(){
        if(s-p){
            cout<<arr[p]<<"\n";
            p++;
        }
        else{
            cout<<-1<<"\n";
        }
    }
    void size(){
        cout<<s-p<<"\n";
    }
    void empty(){
        if(s-p){
            cout<<0<<"\n";
        }
        else{
            cout<<1<<"\n";
        }
    }
    void front(){
        if(s-p){
            cout<<arr[p]<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }
    void back(){
        if(s-p){
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
    Queue st;
    cin>>n;
    while(n--){
        cin>>s;
        if(s=="push"){
            cin>>a;
            st.push(a);
        }
        else if(s=="pop"){
            st.pop();
        }
        else if(s=="size"){
            st.size();
        }
        else if(s=="empty"){
            st.empty();
        }
        else if(s=="front"){
            st.front();
        }
        else if(s=="back"){
            st.back();
        }
    }
}