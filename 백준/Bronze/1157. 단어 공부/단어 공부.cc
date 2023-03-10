#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[26]={};
    int max=-1;
    int index;
    string s;
    cin>>s;

    for(char c:s){
        if(c>=97){      //소문자
            arr[c-97]+=1;
        }   
        else{
            arr[c-65]+=1;
        }
    }
    
    for(int i=0;i<26;i++){
        if(arr[i]>max){
            max=arr[i];
            index=i;
        }
        else if(arr[i]==max){
            index=-1;
        }
    }

    if(index==-1) cout << "?";
    else cout << (char)(index+65);
}