#include<bits/stdc++.h>
#define MAX 1001
using namespace std;



int main()
{
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string sa,sb;
    int la,lb;
    int prea[MAX][MAX];
    int preb[MAX][MAX];
    char cha[MAX][MAX]{0};
    int len[MAX][MAX]{0};

    cin>>sa>>sb;
    la=sa.size();
    lb=sb.size();

    for(int i=0;i<=la;i++){
        for(int j=0;j<=lb;j++){
            prea[i][j]=-1;
            preb[i][j]=-1;
        }
    }

    for(int i=1;i<=la;i++){
        for(int j=1;j<=lb;j++){
            if(sa[i-1]==sb[j-1]){
                len[i][j]=len[i-1][j-1]+1;
                prea[i][j]=i-1;
                preb[i][j]=j-1;
                cha[i][j]=sa[i-1];
            }
            else{
                if(len[i-1][j]>len[i][j-1]){
                    len[i][j]=len[i-1][j];
                    prea[i][j]=i-1;
                    preb[i][j]=j;
                }
                else{
                    len[i][j]=len[i][j-1];
                    prea[i][j]=i;
                    preb[i][j]=j-1;
                }
            }
        }
    }


    if(len[la][lb]){
        cout<<len[la][lb]<<"\n";
        string ans;
        for(int i=la,j=lb,tmp;i>0||j>0;tmp=i,i=prea[i][j],j=preb[tmp][j]){
            if(cha[i][j]==0){
                continue;
            }
            else{
                ans+=cha[i][j];
            }
        }

        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i];
        }
    }
    else{
        cout<<len[la][lb];
    }
    
}
