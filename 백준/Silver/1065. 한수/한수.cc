#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,n,diff1,diff2,answer=0;
    
    cin>>a;
    for(int i=1;i<=a;i++){
        n = i;
        diff1 = n%10-(n/10)%10;
        n/=10;
        while(true){
            if(n<10){
                answer+=1;
                break;
            }
            diff2 = n%10-(n/10)%10;
            if(diff1!=diff2){
                break;
            }
            else{
                diff1=diff2;
                n/=10;
            }
        }
    }
    cout<<answer;
}