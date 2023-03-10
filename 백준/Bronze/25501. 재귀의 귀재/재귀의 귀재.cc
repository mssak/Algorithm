#include<iostream>
#include <string.h>
using namespace std;

int c;

int recursion(const char *s, int l, int r){
    c++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int a;
    char s[1001];
    cin>>a;
    while(a--){
        cin>>s;
        c=0;
        cout<<isPalindrome(s)<<" "<<c<<"\n";
    }
}