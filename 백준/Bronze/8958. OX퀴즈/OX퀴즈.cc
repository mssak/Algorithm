#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,count,answer;
    cin>>a;

    char arr[a][80]={};
    for(int i=0;i<a;i++){
        cin>>arr[i];
        answer=0;
        count=0;
        for(int j=0;j<80;j++){
            if(arr[i][j]=='O'){
                count += 1;
            }
            else if(arr[i][j]=='X'){
                answer+=count*(count+1)/2;
                count=0;
            }
            else{
                answer+=count*(count+1)/2;
                break;
            }
        }
        cout<<answer<<"\n";
    }
}